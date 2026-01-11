#include "Emitter.h"
#include "Engine.h"
#include "GameObject2D.h"
#include "Bullets.h"
#include "Keys.h"
#include <bitset>
#include "Player.h"
extern std::bitset<5> keys;
using namespace std;



Emitter::Emitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval) : GameObject2D(initPosition, 0.0f, initSize, 0) {
	this->emitTimeInterval = emitTimeInterval;
	emitCounter = emitTimeInterval;
	particleNumber = 0;
	
}

GLuint playerTexture = loadTexture("Resources\\Textures\\player1_ship.png"); // Creation of player

Player* mainPlayer = new Player(glm::vec2(-1.0f, 0.0f), 1.5f, glm::vec2(0.5f, 0.5f), playerTexture, 1.0f);


void Emitter::update(double tDelta) 
{  

	emitCounter += (float)tDelta;
	if (keys.test(Key::SPACE) == true)
	{
		while (emitCounter >= emitTimeInterval) {

			// decrease emitCounter by emitTimeInterval - don't set to 0 as this would ignore the case where multiple particles are needed.
			emitCounter -= emitTimeInterval;

			// Create new particle

			Bullets* bullets = new Bullets(glm::vec2(), 0.0f, glm::vec2(0.2f, 0.2f), loadTexture("Resources\\Textures\\circle.png"), 1.0f);

			

			string key = string("bullet");

			if (particleNumber > 0) { // first name in collection must not be numbered if using this approach

				// add value so unique anyway - not using engine mechanism
				key += to_string(particleNumber);
			}

			particleNumber++;

			addObject(key.c_str(), bullets);
		}
		

	}
	
}


