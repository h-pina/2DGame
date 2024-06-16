#pragma once

#include "GLFW/glfw3.h"
#include "InputHandler.h"
#include "EventHandler.h"
#include "Renderer.h"
#include "Scene.h"
#include <memory>

namespace Game {


	class Application {
		public:
			Application();
			void run();
			~Application();
		
		private:
			GLFWwindow* m_window = NULL;
	};

}
