#pragma once
class Student;
class Disc;
class Group
{
	string name;
	list<Student> listSt; // Список студентов
	list<Disc> listDis; // Список дисциплин
public:
	Group();
	list<Student> & getListSt();
	list<Disc> & getListDis();

	Group(string& name);
	void add(Student & st); // Добавить студента
	void add(Disc & dis); // Добавить дисциплину
	void print(); // Печать только названия
	void printAll(); // Печать всего и всех списков
	~Group();
	friend ostream& operator<<(ostream& out, Group & gr);
	friend istream& operator>>(istream& in, Group & gr);
};



