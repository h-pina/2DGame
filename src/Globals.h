#include <cstdint>

namespace Game {

	struct windowConfig{
		uint32_t width = 800;
		uint32_t height = 900;
		const char* title = "2D Game";
	};

	extern windowConfig g_windowConfig;

}
