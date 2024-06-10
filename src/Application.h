#include "GLFW/glfw3.h"
#include <cstdint>

namespace Game {


	struct windowConfig{
		const uint32_t width = 800;
		const uint32_t height = 900;
		const char* title = "2D Game";
	};

	class Application {
		public:
			void setupWindow();
			void run();

			~Application();
		
		private:
			void handleInput();
			void defineCallbacks();
			windowConfig m_windowConfig;
			GLFWwindow* m_window;
	};

}
