#pragma once

#include "GLFW/glfw3.h"

namespace Game {
	
	struct WindowConfig{
		uint32_t width = 800;
		uint32_t height = 900;
		const char* title = "2D Game";
	};


	class Window {
		public:
			Window();

			static WindowConfig s_windowConfig;
			GLFWwindow* getGlfwWindow();
			int getWidth();
			int getHeight();
			static void framebuffer_resize_callback(GLFWwindow* window, int width, int height);

			~Window();
		private:
			//NOTE: Had to make m_windowConfig static because the callback
			//has to access it	
			GLFWwindow* m_glfwWindow = nullptr;
	};
}
