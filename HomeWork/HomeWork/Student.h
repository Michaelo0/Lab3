#pragma once
class Group;
class OcList;
class Student
{
	string fio;
	Group *pGr; // Указатель на группу
	list<OcList> listOc; // Список списков оценок по разным дисциплинам

public:
	void setGroup(Group *pGr); // Установить группу для студента
	Student();
	list<OcList>& getListOc();
	Student(string& fio);
	void print(); // Печать только ФИО
	void printAll(); // Печать всего
	~Student();
	friend ostream& operator<<(ostream& out, Student & st);
	friend istream& operator>>(istream& in, Student & st);
};


