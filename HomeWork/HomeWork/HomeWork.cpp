// HomeWork.cpp: ���������� ����� ����� ��� ����������� ����������.
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

list<Group>listGr; // ������ �����

int _tmain(int argc, _TCHAR* argv[])
{
	int Reg;
	string buf1;
	Group *pGr = 0; // ��� �������� ������ �����������
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
		cout << "������� ����� ������: 1- ���� ����� ������ 2- ���� ������ �������� 3- ���� ����� ���������� 4- ���� ������ ��� �������� �� ���������� 5 - ������ ���� ������ 8- ��������� ������ � ����� 9- ��������� ������� �� ����� 10 - �����" <<
			endl << "����� �=";
		cin >> Reg;
		switch (Reg)
		{
		case 1: // ���� ����� ������
			cout << "������� ���� ������: "; cin >> buf1;
			pGr = new Group(buf1);
			listGr.push_back(*pGr); // ��������� � ������
			break;
		case 2: // ���� ������ ��������
			if (listGr.size() == 0) {
				cout << "������ ����� ����, �� ����� ������ �������� ������ ���� ������� ������ ��� ��������� �� �����" << endl;
				break;
			}
			cout << "������� ��� ��������: "; cin >> buf1;
			pSt = new Student(buf1);
			cout << "������ ������������ �����:" << endl;
			i = 1;
			for (auto& pos : listGr) {
				cout << i << ". ����: "; pos.print();
				i++;
			}
			cout << "������� ����� ������ ��� ��������: "; cin >> Num;
			i = 1;
			for (auto& pos : listGr) {
				if (Num == i) {
					pos.add(*pSt);
					break;
				}
				i++;
			}
			break;
		case 3: // ���� ����� ����������
			if (listGr.size() == 0) {
				cout << "������ ����� ����, �� ����� ����� ���������� ������ ���� ������� ������ ��� ��������� �� �����" << endl;
				break;
			}
			cout << "������� �������� ����������: "; cin >> buf1;
			pDis = new Disc(buf1);
			cout << "������ ������������ �����:" << endl;
			i = 1;
			for (auto& pos : listGr) {
				cout << i << ". ����: "; pos.print();
				i++;
			}
			cout << "������� ����� ������ ��� ����������: "; cin >> Num;
			i = 1;
			for (auto& pos : listGr) {
				if (Num == i) {
					pos.add(*pDis);
					break;
				}
				i++;
			}
			break;
		case 4: // ���� ������ ��� �������� �� ����������
			if (listGr.size() == 0) {
				cout << "������ ����� ����, �� ����� ������ ������ ���� ������� ������ ��� ��������� �� �����" << endl;
				break;
			}

			cout << "������ ������������ �����:" << endl;
			i = 1;
			for (auto& pos : listGr) {
				cout << i << ". ����: "; pos.print();
				i++;
			}
			cout << "������� ����� ������ ��� ������ ���������� � ��������: "; cin >> Num;
			i = 1;
			for (auto& pos : listGr) {
				if (Num == i) {
					pGr = &pos;
					break;
				}
				i++;
			}
			if (pGr->getListDis().size() == 0) {
				cout << "������ ��������� � ������ ����, �� ����� ������ ������ ���� ������� ���������� ��� ��������� �� �����" << endl;
				break;
			}
			i = 1;
			for (auto& pos : pGr->getListDis()) {
				cout << i << ". ��������: "; pos.print();
				i++;
			}
			cout << "������� ����� ���������� ��� ������: "; cin >> Num;
			i = 1;
			for (auto& pos : pGr->getListDis()) {
				if (Num == i) {
					pDis = &pos;
					break;
				}
				i++;
			}

			if (pGr->getListSt().size() == 0) {
				cout << "������ ��������� � ������ ����, �� ����� ������ ������ ���� ������� �������� ��� ��������� �� �����" << endl;
				break;
			}
			i = 1;
			for (auto& pos : pGr->getListSt()) {
				cout << i << ". ���: "; pos.print();
				i++;
			}
			cout << "������� ����� �������� ��� ������: "; cin >> Num;
			i = 1;
			for (auto& pos : pGr->getListSt()) {
				if (Num == i) {
					pSt = &pos;
					break;
				}
				i++;
			}
			cout << "������� ����� ������: "; cin >> Oc;
			flag = 0;

			if (pSt->getListOc().size()>0) for (auto& pos : pSt->getListOc()) if (pos.getDisName() == pDis->getName()) // ����� ���������� � ��������
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
		case 5: //	������ ���� ������
				cout << "����� �����: " << listGr.size() << endl;
				for (auto pos : listGr) pos.printAll();  // ������ �����
				break;
		case 8: // ��������� ������ � �����
			ofs.open("MyFileDat.txt");
			ofs << listGr.size() << endl;
			for (auto& pos : listGr) ofs << pos;
			ofs.close();
			break;
		case 9: //	��������� ������� �� �����
			ifs.open("MyFileDat.txt");
			ifs >> Num; // ����� ��������� ������ (�����)
			listGr.clear();
			for (int i = 0; i < Num; i++)
			{
				pGr = new Group;
				ifs >> *pGr;
				listGr.push_back(*pGr);
			}

			ifs.close();
			if (listGr.size() == 0)
				cout << "���� ��� ������ �� ���������� ��� �� ����, ������ �� ���������" << endl;
			else cout << "������ ������� ���������" << endl;
			break;
		
		case 10: // �����
			ofs.close();
			return 0;
		

		}

	}
	return 0;
}


