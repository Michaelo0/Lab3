#pragma once
class OcList // ����� - ������ ������ �� ����������
{
	string name; // ��� ����������

	list<int> oclist; // ������ ������ 
public:
	OcList(string name);
	OcList();
	string & getDisName();
	list<int>& getOcList();
	~OcList();
	void printAll(); // ������ �����
	void add(int oc); // �������� ������ � ������
	double getSrBall(); // ������� ������� ���� �� ������ ������
	friend ostream& operator<<(ostream& out, OcList & list1);
	friend istream& operator>>(istream& in, OcList & list1);
};

