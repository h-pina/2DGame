#include "InputHandler.h"
#include "GLFW/glfw3.h"

namespace Game {
	void InputHandler::keyPressed(GLFWwindow* window, int key, int action ){
		if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
			glfwSetWindowShouldClose(window,GL_TRUE );
		}	

	}
}
