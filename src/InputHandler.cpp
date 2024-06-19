#include "InputHandler.h"
#include "GLFW/glfw3.h"
#include "GameObject.h"

namespace Game {
	
	void InputHandler::keyPressed(GLFWwindow* window, int key, int action ){
		//At first, the game will operate on `act on press` philosophy 
		if(action != GLFW_PRESS) 
			return; 

		if(key == GLFW_KEY_ESCAPE){
			glfwSetWindowShouldClose(window,GL_TRUE );
			return;
		}	

		if(!m_player){
			switch(key){
				case GLFW_KEY_A:
					m_player->move("right");
					break;
				case GLFW_KEY_D:
					m_player->move("left");
					break;
			}
		}
	}

	void InputHandler::attachPlayer(GameObject* player){
		m_player = player;
	}
}
