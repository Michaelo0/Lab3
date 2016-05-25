#pragma once
class Rect;
class Vector
{
	Rect **pp;
	int n; // 
public:
	Vector(Rect **pp, bool *flag, int n); 
	void print();
	Vector& operator+(Rect & rect);
	Vector& operator-(Rect & rect);
	Rect & operator[](int i);

	Vector();
	~Vector();
};

