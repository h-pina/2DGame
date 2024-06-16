#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GameObject.h"
#include "Renderer.h"


namespace Game {

	Renderer::Renderer(GLFWwindow* window, Scene* scene){
		m_window = window;
		m_scene = scene;
	}

	void Renderer::renderFrame(){
		glClearColor( 0.118f, 0.161f, 0.212f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		executeDrawCalls();

		glfwSwapBuffers(m_window); 
	}

	//TODO: Improve the capabilities of this function
	void Renderer::executeDrawCalls(){
		for(GameObject go : m_scene->getGameObjects()){
			go.m_mesh->use();
			go.m_shader->use();
			//go.tex.use();
			glDrawArrays(GL_TRIANGLES, 0, go.m_mesh->m_vertexCount);
		}
	}



}
