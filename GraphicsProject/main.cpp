#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include <iostream>

int main() {
	if (glfwInit() == GLFW_FALSE) {
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Test Window", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	//Load OpenGl
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}
	int majorVersion = ogl_GetMajorVersion();
	int minorVersion = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", majorVersion, minorVersion);

	//cleanup and exit
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}