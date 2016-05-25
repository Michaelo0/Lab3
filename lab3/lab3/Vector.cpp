#include "stdafx.h"
#include "Vector.h"
#include "Rect.h"
#include "Paral.h"


Vector::Vector()
{
	n = 0;
}

Vector::Vector(Rect **pp, bool *flag, int n) 
{
	this->n = n;
	this->pp = new Rect*[n];
	for (int i = 0; i < n; i++)
		if (flag[i])
			this->pp[i] = new Paral((Paral &)*pp[i]);
		else this->pp[i] = new Rect(*pp[i]);

}

void Vector::print()
{
	cout << endl << "В векторе " << n << " объектов:";
	for (int i = 0; i < n; i++)
		pp[i]->print();
}


Vector::~Vector()
{
	if (n)
	{
		for (int i = 0; i < n; i++)
			delete pp[i];
		delete[] pp;
	}
}

Vector& Vector::operator+(Rect & rect)
{
	Rect **ppR = new Rect*[n + 1];
	for (int i = 0; i < n; i++) ppR[i] = pp[i];
	ppR[n] = &rect;
	delete[] pp; 
	pp = ppR; 
	n++; 
	return *this;
}

Vector& Vector::operator-(Rect & rect) 
{
	Rect **ppR = new Rect*[n - 1]; 
	int flag = 0; 
	int iDel; 
	for (int i = 0; i < n; i++)
		if (pp[i] != &rect)  
			if (flag == 0) ppR[i] = pp[i]; else ppR[i - 1] = pp[i];
		else 
		{
			flag = 1; 
			iDel = i; 
		}
	delete pp[iDel];   
	delete[] pp; 
	pp = ppR; 
	n--;
	return *this;
}

Rect & Vector::operator[](int i)
{
	return *pp[i];
}
