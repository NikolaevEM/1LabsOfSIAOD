/* Lab2 E 20
�� ������������� ���������� ������� ��������� ���������, ���������� �������� � ��������� � �� ����������, ������������ � ���� ��������� ������.
�������� ���������, �������:
�	������������ ��������� ������������ ��������� � ���� ��������� ������;
�	���������� ����� ���� ���������;
�	������ ����� �������� � ����� ���������;
�	������� ��������� �� ������ ����������� ���������.
��������� ������ ������������ ������ � ������� ���� � �������� ������ ��� �����.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Brunch {														   //����� ������
	int phone;
	int minutes;
	Brunch *l, *r;														 //��������� �� ����� �����

public:
	void show(Brunch *&CurBrunch) {											 //����� ������
		if (CurBrunch != NULL) {												//���� �� ���������� ������ �����
			show(CurBrunch->l);													//������� ����� �����
			cout << "������� " << (*CurBrunch).phone << " :	 " << CurBrunch->minutes << " ����� �������" << endl;     //(*a).method == a->method
			show(CurBrunch->r);													//������� ������ �����
		}
	}

	void add_Brunch(int phone, int minutes, Brunch *&NewBrunch) {			//������� �����. *& - �������� NewBrunch, �.� ��������������� �� �������
		if (NULL == NewBrunch) {									   //���� ����� ���, �� ������� �����
			NewBrunch = new Brunch;										//�������� ������ ��� ����� ������
			NewBrunch->phone = phone;									//���������� ������ � �����
			NewBrunch->minutes = minutes;
			NewBrunch->l = NewBrunch->r = NULL; ;						//��������� ����� �����
		}

		if (phone < NewBrunch->phone) {									//���� ������, �� ������ ������� � �����
			if (NewBrunch->l != NULL) add_Brunch(phone, minutes, NewBrunch->l); 
			else {						
				NewBrunch->l = new Brunch;								//�������� ������ ��� ����� ��������   
				NewBrunch->l->l = NewBrunch->l->r = NULL;				//�������� �������� ��������
				NewBrunch->l->phone = phone;							//������� ������ � ����� ��������
				NewBrunch->l->minutes = minutes;
			}
		}

		if (phone > NewBrunch->phone) {										//���� ������, �� ������ ������� � ������
			if (NewBrunch->r != NULL) add_Brunch(phone, minutes, NewBrunch->r); 
			else {                                    
				NewBrunch->r = new Brunch;            
				NewBrunch->r->l = NewBrunch->r->r = NULL; 
				NewBrunch->r->phone = phone;                  
				NewBrunch->r->minutes = minutes;
			}
		}
	}

	void del(Brunch *&CurBrunch) {								//����������
		if (CurBrunch != NULL) {             
			del(CurBrunch->l);            
			del(CurBrunch->r);             
			delete CurBrunch;                
			CurBrunch = NULL;         
		}
	}

	void alert(Brunch *&CurBrunch, int curNumber) {								//���������
		if (CurBrunch != NULL ) {												//���� �� ���������� ������ �����
			if (CurBrunch->phone == curNumber) {
				cout << "������� " << (*CurBrunch).phone << " �� " << CurBrunch->minutes << " ����� ������� " << CurBrunch->minutes*0.2 << " ������" << endl;     //(*a).method == a->method
				return;
			}
			if (CurBrunch->phone > curNumber) alert(CurBrunch->l, curNumber);				//������� ����� �����
			else alert(CurBrunch->r, curNumber);											//������� ������ �����
		}
	}
};

void step1() {
	cout << endl;
	cout << "��� ����������� ������� \"������\"!" << endl;
	cout << "�������� 1, ����� �������� �������� � ��� ����������� ������ �������" << endl;
	cout << "�������� 2, ����� ���������� ������ �� ���������" << endl;
	cout << "�������� 3, ����� ������� ��������� �� ������ ��������" << endl;
	cout << ">>";
	return;
}

void step2(Brunch *&Tree, int temp) {
	int curPhone;
	int curMinutes;
	switch (temp) {
	case 1:
		cout << "������� ����� ��������: " << endl << ">>";
		try {
			cin >> curPhone;
			cout << endl;
		}
		catch (const std::exception&) {
			cout << "������ 2: ����� �������� �������� ������ �����!\n������� ������." << endl;
			step2(Tree, temp);
			return;
		}
		cout << "������� ������ ��������: " << endl << ">>";
		try {
			cin >> curMinutes;
			cout << endl;
		}
		catch (const std::exception&) {
			cout << "������ 3: ���-�� ����� �������� ������\n������� ������." << endl;
			step2(Tree, temp);
			return;
		}
		Tree->add_Brunch(curPhone, curMinutes, Tree);
		break;
	case 2:
		Tree->show(Tree);
		break;
	case 3:
		cout << "������� ����� ��������: " << endl << ">>";
		try {
			cin >> curPhone;
			cout << endl;
		}
		catch (const std::exception&) {
			cout << "������ 2: ����� �������� �������� ������ �����!\n������� ������." << endl;
			step2(Tree, temp);
			return;
		}
		Tree->alert(Tree,curPhone);
		break;
	default:
		cout << "������ 1: �������, ������ �� ����������!\n������� ������." << endl;
		step1();
		return;
	}
	return;
}

void start(Brunch *&Tree) {
	int temp;
	step1();
	try {
		cin >> temp;
		cout << endl;
	}
	catch (const std::exception&) {
		cout << "������ 1: �������, ������ �� ����������!\n������� ������." << endl;
		step1();
	}

	step2(Tree, temp);
	start(Tree);
}

int main() {
	Brunch *Tree = NULL;  

	setlocale(LC_ALL, "Russian");

	for (int i = 5; i>0; i--) Tree->add_Brunch(i, i*(i+10), Tree);

	start(Tree);

	return 0;
}