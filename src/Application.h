#pragma once

#include "Window.h"
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
		private:
			//NOTE: Allocated on heap since those are the core objects of the program
			std::unique_ptr<Window> m_window;
			std::unique_ptr<InputHandler> m_inputHandler;
			std::unique_ptr<EventHandler> m_eventHandler;
	};

}
