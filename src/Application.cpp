#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Application.h"
#include "Mesh.h"

namespace Game {
	
	float vertexData[] = {
		-0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
	};
	
	void Application::setupWindow(){
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		m_window = glfwCreateWindow(m_windowConfig.width, m_windowConfig.height,
															 m_windowConfig.title, NULL, NULL);
		glfwMakeContextCurrent(m_window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glViewport(0, 0, m_windowConfig.width, m_windowConfig.height);
	}

	void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void Application::defineCallbacks(){
		glfwSetFramebufferSizeCallback(m_window, framebuffer_resize_callback);
	}

	void Application::run(){
		Mesh player;
		player.create(vertexData, 9);
		while(!glfwWindowShouldClose(m_window)){
			handleInput();
			glClearColor( 0.118f, 0.161f, 0.212f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			player.use();
			glDrawArrays(GL_TRIANGLES, 0, player.m_vertexCount);
			glfwSwapBuffers(m_window); 
			glfwPollEvents();
		}
	}

	void Application::handleInput(){
		if(glfwGetKey(m_window , GLFW_KEY_ESCAPE) == GLFW_PRESS){
			glfwSetWindowShouldClose(m_window, true);
		}
	}
	
	Application::~Application(){
		glfwTerminate();
		glfwDestroyWindow(m_window);

	}
}
