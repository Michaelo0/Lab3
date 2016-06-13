// lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Rect.h"
#include "Paral.h"
#include "Vector.h"


int _tmain(int argc, _TCHAR* argv[])
{
	double x, y,z;
	setlocale(LC_ALL, "rus");
	cout << "Input width n length: ";
	cin >> x >> y;
	Rect * pRect1=new Rect(x,y);
	cout << "Input width n length, higth: ";
	cin >> x >> y >> z;
	Paral *pParal1=new Paral(x, y, z);
	pRect1->print();
	pParal1->print();
	
	Rect *p;
	p = pParal1;
	p->print();
	Rect r1(3, 5), r2(30, 50), r3(300, 500);
	Paral par1(4, 5, 6), par2(40, 50, 60), par3(400, 500, 600);
	Rect **pp1 = new Rect*[6]; 
	pp1[0] = &r1; pp1[1] = &r2; pp1[2] = &r3;
	pp1[3] = &par1; pp1[4] = &par2; pp1[5] = &par3;
	bool flag[6] = { 0, 0, 0, 1, 1, 1 }; // first 3 objects re rectangles, next 3 - paralls
	Vector V1(pp1, flag, 6);
	V1.print();
	// Add objects to vector
	V1 + *pRect1;
	V1 + *pParal1;
	V1.print();
	// Delete objects from vecor
	V1 - *pRect1;
	V1 - *pParal1;
	V1.print();
	cout << endl << "print of individual vector's objects by overload []";
	for (int i = 0; i < 6; i++) // print 
		V1[i].print();


	system("pause");
	
	return 0;
}

