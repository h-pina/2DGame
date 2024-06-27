#pragma once

#include "GLFW/glfw3.h"
#include "GameObject.h"
#include "Player.h"

namespace Game {
	namespace InputHandler{
		void attachPlayer(std::shared_ptr<Player> player);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}
