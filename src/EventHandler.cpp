#include <GLFW/glfw3.h>
#include "EventHandler.h"
#include "InputHandler.h"
//NOTE: Should I always pass windows on constructor? Or maybe I create a function like
//Application.getWindow() so it is consistent across classes?? Idk
namespace Game {
	static InputHandler* s_inputHandler = NULL;

	EventHandler::EventHandler(GLFWwindow* window, InputHandler* inputHandler){
		s_inputHandler = inputHandler;
		m_window = window; 
	}

	void EventHandler::setupCallbacks(){
		glfwSetFramebufferSizeCallback(m_window, EventHandler::framebuffer_resize_callback);
		glfwSetKeyCallback(m_window, EventHandler::key_callback);
	}

	void EventHandler::pollEvents(){
		glfwPollEvents();
	}

	void EventHandler::framebuffer_resize_callback(GLFWwindow* window, int width, int height){
		glViewport(0, 0, width, height); 
	}

	void EventHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
		if(s_inputHandler != NULL){
			s_inputHandler->keyPressed(window, key, action);
		}
	}
}
