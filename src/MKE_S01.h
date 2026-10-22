#pragma once
#include <Arduino.h>

class MKE_S01
{
public:
	MKE_S01(int out, int echo);			//initialisation class MKE_S01 (trig pin , echo pin)
	MKE_S01(int out, int echo[], int n); //initialisation class MKE_S01 (trig pin , echo pin)
	~MKE_S01();							//destructor
	float dist() const;					//return curent distance of element 0
	float dist(int n) const;			//return curent distance of element n

private:
	void init(int out, int echo[], int n); //for constructor
	int out;							   //out pin
	int *echo;							   //echo pin list
	int n;								   //number of el
};
