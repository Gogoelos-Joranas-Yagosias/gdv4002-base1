#include "Engine.h"
#include "Keys.h"
#include <bitset>

std::bitset<5> keys{ 0x0 };
// Function prototypes
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

// Global Variables


int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	//

	
	//
	// Set callback functions
	//
	setKeyboardHandler(myKeyboardHandler);

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();


	// return success :)
	return 0;
}

void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Check if the key was just pressed
	if (action == GLFW_PRESS) {

		// now check which key was pressed...
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			// If escape is pressed tell GLFW we want to close the window (and quit)
		
				glfwSetWindowShouldClose(window, true);
			break;

		case GLFW_KEY_W:
			printf("w pressed\n");
			break;

		case GLFW_KEY_A:
			printf("a pressed\n");
			break;

		case GLFW_KEY_S:
			printf("s pressed\n");
			break;

		case GLFW_KEY_D:
			printf("d  pressed\n");
			break;
		}
	}
	// If not pressed, check the key has just been released
	else if (action == GLFW_RELEASE) {

		// handle key release events
		switch (key)
		{
		case GLFW_KEY_W:
			printf("w released\n");
			break;

		case GLFW_KEY_A:
			printf("a released\n");
			break;

		case GLFW_KEY_S:
			printf("s released\n");
			break;

		case GLFW_KEY_D:
			printf("d released\n");
			break;
		}

	}
}
