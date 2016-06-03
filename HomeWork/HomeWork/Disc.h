#pragma once
class Disc
{
	string name;
	double proh_ball;
public:
	string& getName(); // �������� ��� ����������
	Disc();
	Disc(string &name);
	void setProhBall(double proh_ball); // ��������� ���������� �����
	void print(); // ������ ������ �������� 
	void printAll(); // ������ ����� 
	~Disc();
	friend ostream& operator<<(ostream& out, Disc & dis);
	friend istream& operator>>(istream& in, Disc & dis);
};

