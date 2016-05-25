#pragma once
#include "Rect.h"
class Paral :
	public Rect
{
	double c;
public:
	Paral(double a, double b, double c);
	double getMera();
	void print();
	Paral & operator=(Paral & r);
	Paral();
	virtual  ~Paral();
};

