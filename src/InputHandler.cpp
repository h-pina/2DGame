#include "InputHandler.h"
#include "GLFW/glfw3.h"
#include "GameObject.h"

namespace Game {
	void InputHandler::keyPressed(GLFWwindow* window, int key, int action ){
		if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
			glfwSetWindowShouldClose(window,GL_TRUE );
		}	
		if(key == GLFW_KEY_A && action == GLFW_PRESS && m_player != NULL){
			m_player->move("right");
		}
		if(key == GLFW_KEY_D && action == GLFW_PRESS && m_player != NULL){
			m_player->move("left");
		}
	}

	void InputHandler::attachPlayer(GameObject* player){
		m_player = player;
	}
}
