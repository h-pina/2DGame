#include "glad/glad.h" 
#include "GLFW/glfw3.h"
#include "Application.h"
#include "Scene.h"
#include "Renderer.h"
#include "EventHandler.h"
#include <memory>

namespace Game {
	Application::Application():
		m_window(std::make_unique<Window>()),
		m_inputHandler(std::make_unique<InputHandler>()),
		m_eventHandler(std::make_unique<EventHandler>(m_window.get(), m_inputHandler.get()))
	{
	}

	void Application::run(){
		m_eventHandler->setupCallbacks(); 

		//Since scene can grow as an object, I`ll allocate it on heap.
		//All the application core instances are allocated on heap. 
		//The Unique pointers will guarantee its correct lifetime	
		std::unique_ptr<Scene> scene = std::make_unique<Scene>();
		std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>(m_window.get(), scene.get());
		
		while(!glfwWindowShouldClose(m_window->getGlfwWindow())){
			renderer->renderFrame();
			m_eventHandler->pollEvents();
		}
	}
}
