#pragma once
#include <GLFW/glfw3.h>
#include <memory>
#include "InputHandler.h"
#include "Scene.h"
#include "Window.h"

namespace Game {

	class EventHandler {
		public:
			EventHandler(Window* window, InputHandler* inputHandler);
			void setupCallbacks();
			void pollEvents();
		private:
			Window* m_window;
			InputHandler* m_inputHandler;

			static void framebuffer_resize_callback(GLFWwindow* window, int width, int height);
			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};

}
