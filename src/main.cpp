#include "Application.h" 
#include <cstdlib>

int main (int argc, char *argv[]) {
	Game::Application app;
	app.setupWindow();
	app.run();

	return EXIT_SUCCESS;
}
