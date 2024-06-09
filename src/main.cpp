
#include <glad/glad.h> // OpenGL function pointers resolution 
#include <GLFW/glfw3.h> //Extensionns on openGL functionality to interact with OS 

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}  
void checkForEscInput(GLFWwindow* window){
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		glfwSetWindowShouldClose(window, true);
	}
}

GLFWwindow* setupGlfwWindow(){
	//Open GL definitions for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//window setup
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		glfwTerminate();
		return NULL;
	}
	return window;
}

void setupCallbacks(GLFWwindow* window){
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //resize callback function
}

void cleanup(){
	glfwTerminate();
}
int main() {
	glfwInit(); //initialize glfw

	GLFWwindow* window = setupGlfwWindow(); 
	if (window == NULL) return -1;

	//Create OpenGL Context
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1;
	}
	
	//Viewport setup. This is somehow different from 
	//glfwCreateWindow, but I`m not so sure how different
	//it is
	glViewport(0,0,800,600);

	while(!glfwWindowShouldClose(window)) {
			checkForEscInput(window);
			glfwSwapBuffers(window); 
			glfwPollEvents(); 
	}
	cleanup();
	return 0;
}
