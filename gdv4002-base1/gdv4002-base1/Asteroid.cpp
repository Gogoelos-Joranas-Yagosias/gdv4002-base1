#include "Asteroid.h"
#include <cmath>
#include <iostream>
#include "Engine.h"
#include "Keys.h"
#include <bitset>

extern std::bitset<5> keys;

Enemy::Enemy(
	glm::vec2 initPosition,
	float initOrientation,
	glm::vec2 initSize,
	GLuint initTextureID,
	float initialPhase,
	float initialPhaseVelocity, float mass)
	: GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	phaseAngle = initialPhase;
	phaseVelocity = initialPhaseVelocity;
	this->mass = mass;

	velocity = glm::vec2(0.0f, 0.0); // default to 0 velocity

}



void Enemy::update( double tDelta)
{
	glm::vec2 F = glm::vec2(1.0f, 1.0f);
	float anglespersecond = glm::radians(80.0);
	float thrust = 10.0f;
	
	
	orientation = orientation + anglespersecond * (velocity.x+velocity.y) * tDelta;

		
	
	

	if (position.y < -getViewplaneHeight()/2.4) {

		F = glm::vec2(0.0f, 20.0f);
		
		
	}
	if (position.y > getViewplaneHeight()/2.4) {

		F = glm::vec2(0.0f, -20.0f);
	
	}
	if (position.x < -getViewplaneWidth()/2.4) {

		F = glm::vec2(20.0f, 0.0f);
		
	}
	if (position.x > getViewplaneWidth()/2.4) {

		F = glm::vec2(-20.0f, 0.0f);
		
	}

	
	

	// 2. calculate acceleration.  If f=ma, a = f/m
	glm::vec2 a = F * (1.0f / mass);

	// 3. integate to get new velocity
	velocity = velocity + (a * (float)tDelta);

	// 4. integrate to get new position
	position = position + (velocity * (float)tDelta);
	
	

	
	

}