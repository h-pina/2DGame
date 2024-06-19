#pragma once 

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"

namespace Game {

	Window::Window(){
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		m_glfwWindow = glfwCreateWindow(m_windowConfig.width, m_windowConfig.height,
															 m_windowConfig.title, NULL, NULL);
		glfwMakeContextCurrent(m_glfwWindow);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glViewport(0, 0, m_windowConfig.width, m_windowConfig.height);
	}

	GLFWwindow* Window::getGlfwWindow(){
		return m_glfwWindow;
	}

	int Window::getWidth(){	
		return m_windowConfig.width;
	}

	int Window::getHeight(){	
		return m_windowConfig.height;
	}
	void Window::framebuffer_resize_callback(GLFWwindow* window, int width, int height){
		glViewport(0, 0, width, height); 
		m_windowConfig.width = width;
		m_windowConfig.height = height;
	}

	Window::~Window(){
		glfwTerminate();
		glfwDestroyWindow(m_glfwWindow);
	}

}
