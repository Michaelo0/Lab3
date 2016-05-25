#pragma once
class Rect
{
protected:
	double a, b;

public:
	Rect(double a, double b);
	virtual double getMera();
	virtual void print();
	Rect & operator=(Rect & r);
	Rect();
	virtual ~Rect();
};

