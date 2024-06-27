#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GameObject.h"
#include "Renderer.h"

#include "glm/ext/matrix_clip_space.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include <iostream>


namespace Game {

	Renderer::Renderer(Window* window, Scene* scene):
		m_window(window),
		m_scene(scene)
	{
	}

	void Renderer::renderFrame(){
		glClearColor( 0.118f, 0.161f, 0.212f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		executeDrawCalls();

		glfwSwapBuffers(m_window->getGlfwWindow()); 
	}

	//TODO: Improve the capabilities of this function
	void Renderer::executeDrawCalls(){
		// Send screen dimensions to ortho
		glm::mat4 projection = glm::ortho(0.0f,(float)m_window->getWidth(),
																			0.0f,(float)m_window->getHeight(),
																			-1.0f,1.0f);
		std::vector<std::shared_ptr<GameObject>> gameObjects = m_scene->getGameObjects();
		for(std::shared_ptr<GameObject> go : gameObjects){
			std::shared_ptr<Mesh> objMesh = go->getMesh();	
			std::shared_ptr<Shader> objShader = go->getShader();	
			objMesh->use();
			objShader->use();
			objShader->mat4Uniform("model",go->getModelMatrix());
			objShader->mat4Uniform("projection",projection);
			//go.tex.use();
			glDrawArrays(GL_TRIANGLES, 0, objMesh->m_vertexArrayConfig.count);
		}
	}
}
