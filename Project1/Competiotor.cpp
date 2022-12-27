#include "Competiotor.h"

Competitor::Competitor(const char* _name , double st, double maxJH)
{
	name = _name;
	stamina = st;
	maxJHeight = maxJH;
}

Competitor::~Competitor() {};

bool Competitor::Run(double distance)
{
	bool res=0;
	if (stamina >= distance) {
		printf("%s run %f meters.\n", name.c_str(), distance);
		res =stamina -= distance;
	}
	else {
		printf("%s could not run %f meters. This competitor is out.\n", name.c_str(), distance);
	}
	return res;
}

bool Competitor::Jump(double height)
{	
	bool res=0;
	if(maxJHeight >= height && stamina >= height) {
		printf("%s jump over %f meters wall.\n", name.c_str(), height);
		res = stamina -= height;
	}
	else {
		printf("%s could not hump over %f meters wall. This competitor is out.\n", name.c_str(), height);
	}
	return res;
}

int Competitor::GetStamina()
{
	return stamina;
}

void Competitor::SetStamina(double st)
{
	stamina = st;
}

double Competitor::GetMaxJHeight()
{
	return maxJHeight;
}

string Competitor::GetName()
{
	return name;
}

void Competitor::SetMaxJHeight(double maxJH)
{
	maxJHeight = maxJH;
}

Human::Human(const char* _name) :Competitor(_name, HUMAN_ST, HUMAN_JUMP)
{
}

Human::~Human()
{
}

Cat::Cat(const char* _name) :Competitor(_name, CAT_ST, CAT_JUMP)
{
}

Cat::~Cat()
{
}

Robot::Robot(const char* _name) :Competitor(_name, ROBOT_ST, ROBOT_JUMP)
{
}

Robot::~Robot()
{
}
