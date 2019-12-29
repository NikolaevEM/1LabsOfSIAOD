/* Lab2 E 20
На междугородной телефонной станции картотека абонентов, содержащая сведе¬ния о телефонах и их владельцах, организована в виде двоичного дерева.
Написать программу, которая:
•	обеспечивает начальное формирование картотеки в виде двоичного дерева;
•	производит вывод всей картотеки;
•	вводит номер телефона и время разговора;
•	выводит извещение на оплату телефонного разговора.
Программа должна обеспечивать диалог с помощью меню и контроль ошибок при вводе.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Brunch {														   //Ветка дерева
	int phone;
	int minutes;
	Brunch *l, *r;														 //Указатели на новые ветки

public:
	void show(Brunch *&CurBrunch) {											 //Обход дерева
		if (CurBrunch != NULL) {												//Пока не встретится пустая ветка
			show(CurBrunch->l);													//Выводим левые ветки
			cout << "Абонент " << (*CurBrunch).phone << " :	 " << CurBrunch->minutes << " минут общения" << endl;     //(*a).method == a->method
			show(CurBrunch->r);													//Выводим правые ветки
		}
	}

	void add_Brunch(int phone, int minutes, Brunch *&NewBrunch) {			//Впихаем ветку. *& - копирует NewBrunch, т.е взаимодействуем со ссылкой
		if (NULL == NewBrunch) {									   //Если ветки нет, то впихаем ветку
			NewBrunch = new Brunch;										//Выделяем память под ветку дерева
			NewBrunch->phone = phone;									//Записываем данные в звено
			NewBrunch->minutes = minutes;
			NewBrunch->l = NewBrunch->r = NULL; ;						//ЗаНУЛЛяем новые ветки
		}

		if (phone < NewBrunch->phone) {									//Если меньше, то данные впихаем в левое
			if (NewBrunch->l != NULL) add_Brunch(phone, minutes, NewBrunch->l); 
			else {						
				NewBrunch->l = new Brunch;								//Выделяем память для новой подветки   
				NewBrunch->l->l = NewBrunch->l->r = NULL;				//Зануляем подведки подведки
				NewBrunch->l->phone = phone;							//Вбиваем данные в новую подветку
				NewBrunch->l->minutes = minutes;
			}
		}

		if (phone > NewBrunch->phone) {										//Если больше, то данные впихаем в правое
			if (NewBrunch->r != NULL) add_Brunch(phone, minutes, NewBrunch->r); 
			else {                                    
				NewBrunch->r = new Brunch;            
				NewBrunch->r->l = NewBrunch->r->r = NULL; 
				NewBrunch->r->phone = phone;                  
				NewBrunch->r->minutes = minutes;
			}
		}
	}

	void del(Brunch *&CurBrunch) {								//Деструктор
		if (CurBrunch != NULL) {             
			del(CurBrunch->l);            
			del(CurBrunch->r);             
			delete CurBrunch;                
			CurBrunch = NULL;         
		}
	}

	void alert(Brunch *&CurBrunch, int curNumber) {								//Извещение
		if (CurBrunch != NULL ) {												//Пока не встретится пустая ветка
			if (CurBrunch->phone == curNumber) {
				cout << "Абонент " << (*CurBrunch).phone << " за " << CurBrunch->minutes << " минут общения " << CurBrunch->minutes*0.2 << " рублей" << endl;     //(*a).method == a->method
				return;
			}
			if (CurBrunch->phone > curNumber) alert(CurBrunch->l, curNumber);				//Выводим левые ветки
			else alert(CurBrunch->r, curNumber);											//Выводим правые ветки
		}
	}
};

void step1() {
	cout << endl;
	cout << "Вас приветсвует система \"Дерево\"!" << endl;
	cout << "Наберите 1, чтобы добавить абонента и его потраченные минуты общения" << endl;
	cout << "Наберите 2, чтобы посмотреть данные об абонентах" << endl;
	cout << "Наберите 3, чтобы вывести извещение об оплате абонента" << endl;
	cout << ">>";
	return;
}

void step2(Brunch *&Tree, int temp) {
	int curPhone;
	int curMinutes;
	switch (temp) {
	case 1:
		cout << "Введите номер абонента: " << endl << ">>";
		try {
			cin >> curPhone;
			cout << endl;
		}
		catch (const std::exception&) {
			cout << "ОШИБКА 2: Номер телефона содержит только цифры!\nВведите заново." << endl;
			step2(Tree, temp);
			return;
		}
		cout << "Введите минуты абонента: " << endl << ">>";
		try {
			cin >> curMinutes;
			cout << endl;
		}
		catch (const std::exception&) {
			cout << "ОШИБКА 3: Кол-во минут является числов\nВведите заново." << endl;
			step2(Tree, temp);
			return;
		}
		Tree->add_Brunch(curPhone, curMinutes, Tree);
		break;
	case 2:
		Tree->show(Tree);
		break;
	case 3:
		cout << "Введите номер абонента: " << endl << ">>";
		try {
			cin >> curPhone;
			cout << endl;
		}
		catch (const std::exception&) {
			cout << "ОШИБКА 2: Номер телефона содержит только цифры!\nВведите заново." << endl;
			step2(Tree, temp);
			return;
		}
		Tree->alert(Tree,curPhone);
		break;
	default:
		cout << "ОШИБКА 1: Вводите, следуя по инструкции!\nВведите заново." << endl;
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
		cout << "ОШИБКА 1: Вводите, следуя по инструкции!\nВведите заново." << endl;
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