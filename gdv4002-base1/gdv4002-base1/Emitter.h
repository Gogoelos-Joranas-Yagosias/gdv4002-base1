#pragma once

#include "GameObject2D.h"


class Player;

class Emitter : public GameObject2D
{
private:

	float	emitTimeInterval;
	float	emitCounter;

	unsigned long long particleNumber; // monotonically increasing particle index / number - used to set key


public:

	 Emitter( glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval);

	void update(double tDelta ) override;
	
	

};

