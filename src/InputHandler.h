#pragma once

#include "GLFW/glfw3.h"
namespace Game {
	class InputHandler {
	public:
		InputHandler() = default;
		void keyPressed(GLFWwindow* windown, int key, int action ); //TODO: Find a better name--> not necessarily pressed
	};
}
