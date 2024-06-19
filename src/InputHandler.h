#pragma once

#include "GLFW/glfw3.h"
#include "GameObject.h"
namespace Game {
	class InputHandler {
		public:
			InputHandler() = default;

			void attachPlayer(GameObject* player);
			void keyPressed(GLFWwindow* windown, int key, int action ); 

			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

		private:
			GameObject* m_player = nullptr; 
	};
}
