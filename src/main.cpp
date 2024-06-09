

#include <GLFW/glfw3.h>
#include <iostream>

int main (int argc, char *argv[]) {
	GLFWwindow* window = glfwCreateWindow(800, 600, "title", NULL, NULL) ;
	std::cout << "Hello" << std::endl;
	return 0;
}

