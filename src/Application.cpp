#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Application.h"
#include "Scene.h"
#include "Renderer.h"
#include "EventHandler.h"

//#include "Mesh.h"
//#include "Shader.h"

namespace Game {
	
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
		m_window = glfwCreateWindow(m_windowConfig.width, m_windowConfig.height,
															 m_windowConfig.title, NULL, NULL);
		glfwMakeContextCurrent(m_window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glViewport(0, 0, m_windowConfig.width, m_windowConfig.height);
	}

	void Application::run(){

		//TODO: Make those variables into class members?
		Scene scene;
		InputHandler inputHandler;
		Renderer renderer(m_window, &scene);
		EventHandler eventHandler(m_window, &inputHandler);

		eventHandler.setupCallbacks(); //EventHandler
		/*
		Mesh player;
		Shader shader("/home/p/u/dev/2d-game/src/shaders/vertexShader.vert",
						"/home/p/u/dev/2d-game/src/shaders/fragShader.frag");
		player.create(vertexData, 9);
		*/
		
		while(!glfwWindowShouldClose(m_window)){
			/*
			glClearColor( 0.118f, 0.161f, 0.212f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			player.use();
			shader.use();
			glDrawArrays(GL_TRIANGLES, 0, player.m_vertexCount);
			glfwSwapBuffers(m_window); 
			glfwPollEvents(); //should this be in a eventHandler?
			*/
			renderer.renderFrame();
			eventHandler.pollEvents();
		}
	}

	/*
	void Application::handleInput(){
		if(glfwGetKey(m_window , GLFW_KEY_ESCAPE) == GLFW_PRESS){
			glfwSetWindowShouldClose(m_window, true);
		}
	}
	*/
	
	Application::~Application(){
		glfwTerminate();
		glfwDestroyWindow(m_window);

	}
}
