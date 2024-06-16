#pragma once
#include <GLFW/glfw3.h>
#include "InputHandler.h"
#include "Scene.h"

namespace Game {

	class EventHandler {
		public:
			EventHandler(GLFWwindow* window, InputHandler* inputHandler);
			void setupCallbacks();
			void pollEvents();
		private:
			GLFWwindow* m_window;

			InputHandler* m_inputHandler;
			static void framebuffer_resize_callback(GLFWwindow* window, int width, int height);
			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};

}
