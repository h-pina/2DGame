#include "InputHandler.h"
#include "GLFW/glfw3.h"

namespace Game {
	namespace InputHandler {

		std::shared_ptr<Player> m_player;

		void attachPlayer(std::shared_ptr<Player> player){
			m_player = player;
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
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
						m_player->move("right", 110000.0f);
						break;
					case GLFW_KEY_D:
						m_player->move("left",111000.0f);
						break;
				}
			}
		}



	}
}
