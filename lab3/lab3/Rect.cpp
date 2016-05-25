#include "stdafx.h"
#include "Rect.h"


Rect::Rect() {

}

Rect::Rect(double a, double b)
{
	this->a = a;
	this->b = b;
}
double Rect::getMera() {
	return a*b;
}
void Rect::print() {
	cout << endl << "a=" << a << " b=" << b << " s=" << getMera()<<endl;
}

Rect & Rect::operator=(Rect & r)
{
	a = r.a;
	b = r.b;
	return *this;

}
Rect::~Rect()
{
}
