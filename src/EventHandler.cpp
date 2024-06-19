#include <GLFW/glfw3.h>
#include "EventHandler.h"
#include "InputHandler.h"
//NOTE: Should I always pass windows on constructor? Or maybe I create a function like
//Application.getWindow() so it is consistent across classes?? Idk
namespace Game {

	EventHandler::EventHandler(Window* window, InputHandler* inputHandler):
		m_window(window),
		m_inputHandler(inputHandler)
	{
	}

	void EventHandler::setupCallbacks(){
		GLFWwindow* window = m_window->getGlfwWindow();
		glfwSetFramebufferSizeCallback(window, Window::framebuffer_resize_callback);
		glfwSetKeyCallback(window, InputHandler::key_callback);
	}

	void EventHandler::pollEvents(){
		glfwPollEvents();
	}
}
