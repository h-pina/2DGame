#pragma once

#include "GLFW/glfw3.h"
#include "InputHandler.h"
#include "EventHandler.h"
#include "Renderer.h"
#include "Scene.h"
#include <cstdint>
#include <memory>

namespace Game {
	struct windowConfig{
		const uint32_t width = 800;
		const uint32_t height = 900;
		const char* title = "2D Game";
	};

	class Application {
		public:
			Application();
			void run();

			~Application();
		
		private:
			
			windowConfig m_windowConfig;
			GLFWwindow* m_window = NULL;
	};

}
