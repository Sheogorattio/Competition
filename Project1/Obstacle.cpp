#include "Obstacle.h"

Obstacle::Obstacle(const char* _name, int _value)
{
	name = _name;
	value = _value;
}

bool Wall::Cope(Competitor* obj)
{
	return obj->Jump(value);
}

bool Treadmill::Cope(Competitor* obj)
{
	return obj->Run(value);
}
