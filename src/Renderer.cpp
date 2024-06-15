#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GameObject.h"
#include "Renderer.h"


namespace Game {

	Renderer::Renderer(GLFWwindow* window, Scene scene){
		m_window = window;
		m_scene = scene;
	}

	void Renderer::renderFrame(){
		glClearColor( 0.118f, 0.161f, 0.212f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		executeDrawCalls();

		glfwSwapBuffers(m_window); 
		glfwPollEvents(); //should this be in a eventHandler?
	}

	void Renderer::executeDrawCalls(){
		/*for(GameObject go : m_scene.gameObjects){
			renderGameObject(go);
		}*/
	}

	void Renderer::renderGameObject(GameObject go){
		go.setupGLStateForRender();
		//call the correct draw function based on
		// gl.DrawCallSpecs
	}



}
