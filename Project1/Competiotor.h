#pragma once
#include<string>
#include<iostream>

using namespace std;

//STAMINA TABLE
//
#define DEF_STAMINA 0
#define HUMAN_ST	5000
#define CAT_ST		3000
#define ROBOT_ST	10000

//MAX JUMP HEIGHT TABLE
//
#define DEF_JUMP	0.0	
#define HUMAN_JUMP	2.0	
#define CAT_JUMP	1.8	
#define ROBOT_JUMP	20.0

class Competitor
{
protected:
	string name;
	double stamina;// 1 meter == 1 stamina point(for sprint and jump)
	double maxJHeight;
public:
	Competitor(const char* n, double st, double maxJH);
	bool Run(double distance);
	bool Jump(double height);
	int GetStamina();
	void SetStamina(double st);
	double GetMaxJHeight();
	string GetName();
	void SetMaxJHeight(double maxJH);
	virtual ~Competitor() = 0;
};

class Human :public Competitor
{
public:
	Human(const char* _name) ;
	 ~Human();
};

class Cat :public Competitor
{
public:
	Cat(const char* _name) ;
	 ~Cat() override;
};

class Robot :public Competitor
{
public:
	Robot(const char* _name) ;
	 ~Robot();
};
