#include "Player.h"
#include "Keys.h"
#include <bitset>
#include "Engine.h"
#include <cmath>
#include <iostream>
#include "GameObject2D.h"

// global variables
extern std::bitset<5> keys;


Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;

	velocity = glm::vec2(0.0f, 0.0f); // default to 0 velocity

	
}


void Player::update(double tDelta) {

	glm::vec2 F = glm::vec2(0.0f, 0.0f);
	float anglespersecond = glm::radians(100.0);
	const float thrust = 10.0f;

	// 1. accumulate forces
	if (keys.test(Key::W) == true) 
	{
		
		F += glm::vec2(cos(orientation) * thrust, sin(orientation)* thrust);

	} 
	if (keys.test(Key::S) == true) 
	{
		
		F -= glm::vec2(cos(orientation) * thrust, sin(orientation) * thrust);
	}
	if (keys.test(Key::A) == true) 
	{

		orientation += anglespersecond * tDelta; 
	}
	if (keys.test(Key::D) == true) {

		orientation += -anglespersecond * tDelta;

	}

	// 2. calculate acceleration.  If f=ma, a = f/m
	glm::vec2 a = F * (1.0f / mass);
	
	// 3. integate to get new velocity
	velocity = velocity + (a * (float)tDelta);

	// 4. integrate to get new position
	position = position + (velocity * (float)tDelta);


	// Screen warping
	if (position.y < -getViewplaneHeight() / 2.0f) {

		position.y = getViewplaneHeight() / 2.0;
	}
	if (position.y > getViewplaneHeight() / 2.0f) {

		position.y = -getViewplaneHeight() / 2.0;
	}
	if (position.x < -getViewplaneWidth() / 2.0f) {

		position.x = getViewplaneWidth() / 2.0;
	}
	if (position.x > getViewplaneWidth() / 2.0f) {

		position.x = -getViewplaneWidth() / 2.0;
	}
}


