#pragma once
#include<string>
#include<iostream>
#include"Competiotor.h"

using namespace std;

class Obstacle
{
protected:
	string name;
	int value;
public:
	Obstacle(const char* _name, int _value);
	virtual bool Cope(Competitor* obj) = 0;//return value
};

class Wall:public Obstacle
{
public:
	Wall(int _height) :Obstacle("Wall", _height){};
	bool Cope( Competitor* obj);
};

class Treadmill :public Obstacle
{
public:
	Treadmill(int _distance) :Obstacle("Treadmill", _distance){};
	bool Cope( Competitor* obj);
};
