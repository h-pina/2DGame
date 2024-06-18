#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GameObject.h"
#include "Renderer.h"
#include "glm/ext/matrix_clip_space.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Globals.h"


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
		// Send screen dimensions to ortho
		glm::mat4 projection = glm::ortho(0.0f,(float)g_windowConfig.width,0.0f,(float)g_windowConfig.height,-1.0f,1.0f);
		auto objs = m_scene->getGameObjects();
		for(GameObject go : *objs){
			go.m_mesh.use();
			go.m_shader.use();
			go.m_shader.mat4Uniform("model",go.getModelMatrix());
			go.m_shader.mat4Uniform("projection",projection);
			//go.tex.use();
			glDrawArrays(GL_TRIANGLES, 0, go.m_mesh.m_vertexCount);
		}
	}



}
