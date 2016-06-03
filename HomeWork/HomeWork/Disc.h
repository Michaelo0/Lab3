#pragma once
class Disc
{
	string name;
	double proh_ball;
public:
	string& getName(); // Получить имя дисциплины
	Disc();
	Disc(string &name);
	void setProhBall(double proh_ball); // Установка проходного балла
	void print(); // Печать только названия 
	void printAll(); // Печать всего 
	~Disc();
	friend ostream& operator<<(ostream& out, Disc & dis);
	friend istream& operator>>(istream& in, Disc & dis);
};

