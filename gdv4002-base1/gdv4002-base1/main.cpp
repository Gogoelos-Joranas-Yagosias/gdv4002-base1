#include "Engine.h"
#include "Keys.h"
#include <bitset>
#include "Player.h"
#include "Asteroid.h"


// Function prototypes
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

// Global Variables
std::bitset<5> keys{ 0x0 };


int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	//  Game scene objects
	//
	GLuint playerTexture = loadTexture("Resources\\Textures\\player1_ship.png"); // Creation of player

	Player* mainPlayer = new Player(glm::vec2(-1.0f, 0.0f), 1.5f, glm::vec2(0.5f, 0.5f), playerTexture, 1.0f);

	addObject("player", mainPlayer);

	// create asteroid enemies
	// 1. Load asteroid texture 
	GLuint enemyTexture = loadTexture("Resources\\Textures\\alien01.png");

	// 2. Create enemy objects
	
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
			// If escape is pressed tell GLFW we want to close the window(and quit)
			
				glfwSetWindowShouldClose(window, true);
			break;

		case GLFW_KEY_W:
			printf("w pressed\n");
			keys[Key::W] = true;
			break;

		case GLFW_KEY_A:
			printf("a pressed\n");
			keys[Key::A] = true;
			break;

		case GLFW_KEY_S:
			printf("s pressed\n");
			keys[Key::S] = true;
			break;

		case GLFW_KEY_D:
			printf("d pressed\n");
			keys[Key::D] = true;
			break;

		case GLFW_KEY_SPACE:
			printf("space pressed\n");
			keys[Key::SPACE] = true;
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
			keys[Key::W] = false;
			break;

		case GLFW_KEY_A:
			printf("a released\n");
			keys[Key::A] = false;
			break;

		case GLFW_KEY_S:
			printf("s released\n");
			keys[Key::S] = false;
			break;

		case GLFW_KEY_D:
			printf("d released\n");
			keys[Key::D] = false;
			break;

		case GLFW_KEY_SPACE:
			printf("space released\n");
			keys[Key::SPACE] = false;
			break;
		}

	}
}
