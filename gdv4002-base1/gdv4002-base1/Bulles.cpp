#include "Bullets.h"

Bullets::Bullets(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass ) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f);

	
}

void Bullets::update(double tDelta) {

	// 1. Physics bit for movement

	// 1.1. Sum forces - only add gravity for now
	glm::vec2 F = glm::vec2(0.0f, 0.0f);

	// 1.2. Calculate acceleration
	glm::vec2 accel = F * (1.0f / mass);

	// 1.3. Update velocity
	velocity = velocity + accel * (float)tDelta;

	// 1.4. Update position
	position = position + velocity * (float)tDelta;


}

