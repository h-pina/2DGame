#include "GameObject.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Application.h"
#include "Scene.h"
#include "Renderer.h"
#include "EventHandler.h"
#include "Globals.h"

namespace Game {

	windowConfig g_windowConfig;
	
	float vertexData[] = { //This will be stored in a separate file
		-0.1f, -0.1f, 0.0f,
     0.1f, -0.1f, 0.0f,
     0.0f,  0.1f, 0.0f
	};
	
	Application::Application(){
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		m_window = glfwCreateWindow(g_windowConfig.width, g_windowConfig.height,
															 g_windowConfig.title, NULL, NULL);
		glfwMakeContextCurrent(m_window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glViewport(0, 0, g_windowConfig.width, g_windowConfig.height);
	}

	void Application::run(){
		//TODO: Make those variables into class members?
		Scene scene;
		
		auto objs = scene.getGameObjects();
		InputHandler inputHandler;
		inputHandler.attachPlayer(&(objs->at(0)));
		Renderer renderer(m_window,&scene);
		EventHandler eventHandler(m_window, &inputHandler);

		eventHandler.setupCallbacks(); 
		
		while(!glfwWindowShouldClose(m_window)){
			renderer.renderFrame();
			eventHandler.pollEvents();
		}
	}

	Application::~Application(){
		glfwTerminate();
		glfwDestroyWindow(m_window);

	}
}
