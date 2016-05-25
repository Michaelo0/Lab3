#include "stdafx.h"
#include "Paral.h"


Paral::Paral()
{
}
Paral::Paral(double a, double b, double c) :Rect(a, b) {
	this->c = c;
}
double Paral::getMera() {
	return Rect::getMera()*c;
}
void Paral::print() {
	cout << endl << "a=" << a << " b=" << b << " c=" << c << " V=" << getMera()<<endl;
}

Paral & Paral::operator=(Paral & r)
{
	a = r.a;
	b = r.b;
	c = r.c;
	return *this;

}

Paral::~Paral()
{
}

