/* Дана строка, состоящая из M попарно различных символов.
Вывести все перестановки символов данной строки.
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
using namespace std;

int fact(int n) {
	int s=1;
	for (int i=1;i<n+1;i++)
		s=s*i;
	return s;
}

void swaper(char *a, int i1, int i2) {
	char temp=a[i1];
	a[i1]=a[i2];
	a[i2]=temp;
}

void pereborBezA(char *a, int len) {
	if (len<=2) {  //Если функции дано перебрать 2 элемента, то мы перебираем и печатаем полученные массивы
		printf("%s",a);
		cout << endl;
		swaper(a,0,1);  //Перестановка
		printf("%s",a);
		cout << endl;
		swaper(a,0,1);  //Обратно получаем изначальный массив
		return;
	}
	for (int i=0;i<len;i++) { //На последнее место перебираем все элементы
		swaper(a,i,len-1); //i-тый элемент меняется с последним элементов
		pereborBezA(a,len-1);
		swaper(a,i,len-1);  //Обратно получаем изначальный массив
	}
}

int main() { //frontend
	char *a;
	a = new char[9];
	int sum;
	char temp;
	freopen("input.txt", "r", stdin);  //Чтение файла.
	int len=0;
	while(cin >> temp) {
		a[len]=temp;
		len++;
	}
	fclose(stdin);

	a[len] = 0;  //Ограничиваем длину массива до len, чтобы при printf не выводился мусор

	//freopen("CON", "r", stdin);  //Перенаправить чтение обратно в консоль.
	freopen("output.txt", "w", stdout);
	cout << fact(len) << endl;
	pereborBezA(a,len);
	fclose(stdout);

	//freopen("CON", "w", stdout);  //Перенаправить запись обратно в консоль.
	//system("pause");
	return 0;
}
