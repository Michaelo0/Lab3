// HomeWork.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Group.h"
#include "Student.h"
#include "Disc.h"
#include "OcList.h"


ostream& operator<<(ostream& out, Disc & dis)
{
	return out << dis.name << endl << dis.proh_ball << endl;
}

istream& operator>>(istream& in, Disc & dis)
{
	return in >> dis.name >> dis.proh_ball;
}

ostream& operator<<(ostream& out, OcList & list1)
{
	out << list1.name << endl;
	out << list1.oclist.size() << endl;
	for (auto pos : list1.oclist) out << pos << endl;
	return out;
}

istream& operator>>(istream& in, OcList & list1)
{

	in >> list1.name;
	int n;
	in >> n;
	int oc;
	for (int i = 0; i < n; i++)
	{
		in >> oc;
		list1.oclist.push_back(oc);
	}
	return in;
}

ostream& operator<<(ostream& out, Student & st)
{
	out << st.fio << endl;
	out << st.listOc.size() << endl;
	for (auto pos : st.listOc) out << pos;
	return out;
}

istream& operator>>(istream& in, Student & st)
{
	in >> st.fio;
	int n;
	in >> n;
	OcList *pL;
	for (int i = 0; i < n; i++)
	{
		pL = new OcList;
		in >> *pL;
		st.listOc.push_back(*pL);
	}
	return in;
}

ostream& operator<<(ostream& out, Group & gr)
{
	out << gr.name << endl;
	out << gr.listSt.size() << endl;
	for (auto pos : gr.listSt) out << pos;
	out << gr.listDis.size() << endl;
	for (auto pos : gr.listDis) out << pos;
	return out;
}

istream& operator>>(istream& in, Group & gr)
{
	in >> gr.name;
	int n;
	in >> n;
	Student *pSt;
	for (int i = 0; i < n; i++)
	{
		pSt = new Student;
		in >> *pSt;
		pSt->setGroup(&gr);
		gr.listSt.push_back(*pSt);
	}
	in >> n;
	Disc *pDis;
	for (int i = 0; i < n; i++)
	{
		pDis = new Disc;
		in >> *pDis;
		gr.listDis.push_back(*pDis);
	}
	return in;
}

list<Group>listGr; // Список групп

int _tmain(int argc, _TCHAR* argv[])
{
	int Reg;
	string buf1;
	Group *pGr = 0; // Для создания группы динамически
	Student *pSt = 0;
	OcList *pLOc;
	Disc *pDis = 0;
	setlocale(LC_ALL, "rus");
	int i, Num;
	int Oc;
	int flag;
	ofstream ofs;
	ifstream ifs;

	while (1)
	{
		cout << "Введите номер режима: 1- Ввод новой группы 2- Ввод нового студента 3- Ввод новой дисциплины 4- Ввод оценок для студента по дисциплине 5 - Печать всех данных 8- Сохранить данные в файле 9- Прочитать даннные из файла 10 - Выход" <<
			endl << "Режим №=";
		cin >> Reg;
		switch (Reg)
		{
		case 1: // Ввод новой группы
			cout << "Введите шифр группы: "; cin >> buf1;
			pGr = new Group(buf1);
			listGr.push_back(*pGr); // Добавляем в список
			break;
		case 2: // Ввод нового студента
			if (listGr.size() == 0) {
				cout << "Список групп пуст, до ввода нового студента должны быть введены группы или прочитаны из файла" << endl;
				break;
			}
			cout << "Введите ФИО студента: "; cin >> buf1;
			pSt = new Student(buf1);
			cout << "Список существующих групп:" << endl;
			i = 1;
			for (auto& pos : listGr) {
				cout << i << ". Шифр: "; pos.print();
				i++;
			}
			cout << "Введите номер группы для студента: "; cin >> Num;
			i = 1;
			for (auto& pos : listGr) {
				if (Num == i) {
					pos.add(*pSt);
					break;
				}
				i++;
			}
			break;
		case 3: // Ввод новой дисциплины
			if (listGr.size() == 0) {
				cout << "Список групп пуст, до ввода новой дисциплины должны быть введены группы или прочитаны из файла" << endl;
				break;
			}
			cout << "Введите название дисциплины: "; cin >> buf1;
			pDis = new Disc(buf1);
			cout << "Список существующих групп:" << endl;
			i = 1;
			for (auto& pos : listGr) {
				cout << i << ". Шифр: "; pos.print();
				i++;
			}
			cout << "Введите номер группы для дисциплины: "; cin >> Num;
			i = 1;
			for (auto& pos : listGr) {
				if (Num == i) {
					pos.add(*pDis);
					break;
				}
				i++;
			}
			break;
		case 4: // Ввод оценок для студента по дисциплине
			if (listGr.size() == 0) {
				cout << "Список групп пуст, до ввода оценок должны быть введены группы или прочитаны из файла" << endl;
				break;
			}

			cout << "Список существующих групп:" << endl;
			i = 1;
			for (auto& pos : listGr) {
				cout << i << ". Шифр: "; pos.print();
				i++;
			}
			cout << "Введите номер группы для поиска дисциплины и студента: "; cin >> Num;
			i = 1;
			for (auto& pos : listGr) {
				if (Num == i) {
					pGr = &pos;
					break;
				}
				i++;
			}
			if (pGr->getListDis().size() == 0) {
				cout << "Список дисциплин у группы пуст, до ввода оценок должны быть введены дисциплины или прочитаны из файла" << endl;
				break;
			}
			i = 1;
			for (auto& pos : pGr->getListDis()) {
				cout << i << ". Название: "; pos.print();
				i++;
			}
			cout << "Введите номер дисциплины для выбора: "; cin >> Num;
			i = 1;
			for (auto& pos : pGr->getListDis()) {
				if (Num == i) {
					pDis = &pos;
					break;
				}
				i++;
			}

			if (pGr->getListSt().size() == 0) {
				cout << "Список студентов у группы пуст, до ввода оценок должны быть введены студенты или прочитаны из файла" << endl;
				break;
			}
			i = 1;
			for (auto& pos : pGr->getListSt()) {
				cout << i << ". ФИО: "; pos.print();
				i++;
			}
			cout << "Введите номер студента для выбора: "; cin >> Num;
			i = 1;
			for (auto& pos : pGr->getListSt()) {
				if (Num == i) {
					pSt = &pos;
					break;
				}
				i++;
			}
			cout << "Введите новую оценку: "; cin >> Oc;
			flag = 0;

			if (pSt->getListOc().size()>0) for (auto& pos : pSt->getListOc()) if (pos.getDisName() == pDis->getName()) // Нашли дисциплину у студента
			{
				pos.getOcList().push_back(Oc); flag = 1; break;
			}
			if (flag == 0)
			{
				pLOc = new OcList(pDis->getName());
				pLOc->add(Oc);
				pSt->getListOc().push_back(*pLOc);
			}
			break;
		case 5: //	Печать всех данных
				cout << "Число групп: " << listGr.size() << endl;
				for (auto pos : listGr) pos.printAll();  // Печать всего
				break;
		case 8: // Сохранить данные в файле
			ofs.open("MyFileDat.txt");
			ofs << listGr.size() << endl;
			for (auto& pos : listGr) ofs << pos;
			ofs.close();
			break;
		case 9: //	Прочитать даннные из файла
			ifs.open("MyFileDat.txt");
			ifs >> Num; // Число элементов списка (групп)
			listGr.clear();
			for (int i = 0; i < Num; i++)
			{
				pGr = new Group;
				ifs >> *pGr;
				listGr.push_back(*pGr);
			}

			ifs.close();
			if (listGr.size() == 0)
				cout << "Файл для чтения не существует или он пуст, данные не прочитаны" << endl;
			else cout << "Данные успешно прочитаны" << endl;
			break;
		
		case 10: // Выход
			ofs.close();
			return 0;
		

		}

	}
	return 0;
}


