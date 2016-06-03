#pragma once
class OcList // Класс - список оценок по дисциплине
{
	string name; // Имя дисциплины

	list<int> oclist; // Список оценок 
public:
	OcList(string name);
	OcList();
	string & getDisName();
	list<int>& getOcList();
	~OcList();
	void printAll(); // Печать всего
	void add(int oc); // Добавить оценку в список
	double getSrBall(); // Считаем средний балл по списку оценок
	friend ostream& operator<<(ostream& out, OcList & list1);
	friend istream& operator>>(istream& in, OcList & list1);
};

