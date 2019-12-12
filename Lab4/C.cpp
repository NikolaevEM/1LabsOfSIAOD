/* Расположения восьми ферзей, которые не бьют друг – друга пронумерованы в лексикографическом порядке
(симметричные решения считать решением). Найти k-е расположение.
*/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
using namespace std;

bool checkGhorizontal1(int *pole, int len, int currentI) {
	for (int i=1;i<len+1;i++)
		for (int j=1+i;j<len+1;j++)
			if (pole[i]==pole[j] && i!=currentI && j!=currentI) return true;  //по горизонтали бьют
	return false;  //по горизонтали не бьют
}
bool checkGhorizontal2(int *pole, int len, int currentI) {
	for (int i=1;i<len+1;i++)
		if (pole[i]==pole[currentI]) return true;  //по горизонтали бьют
	return false;  //по горизонтали не бьют
}
bool checkDiagonal1(int *pole, int len, int currentI) {
	for (int j=0; j<len+1;j++) {
		for (int i=j-1;i>0;i--)  //проверка влево
			if (pole[i]==pole[j]-i && i!=currentI && j!=currentI) return true;  //по диаг бьют
		for (int i=j+1;i<len+1;i++)  //проверка вправо
			if (pole[i]==pole[j]+i && i!=currentI && j!=currentI) return true;  //по диаг бьют
		return false;  //по диаг не бьют
	}
}
bool checkDiagonal2(int *pole, int len, int currentI) {
	for (int i=currentI-1;i>0;i--)  //проверка влево
		if (pole[i]==pole[currentI]-i) return true;  //по диаг бьют
	for (int i=currentI+1;i<len+1;i++)  //проверка вправо
		if (pole[i]==pole[currentI]+i) return true;  //по диаг бьют
	return false;  //по диаг не бьют
}

void razm(int *pole, int len, int countOfElems, int k) {
	int successessss=0;
	for (int i=1;i<len+1;i++) {
		if (checkGhorizontal1(pole, len, i) && checkDiagonal1(pole, len, i)) { //проверить горизонталь и диагональ
		} else {
			for (int j=1;j<countOfElems+1;j++) {
				pole[i]++;
				if (checkGhorizontal2(pole, len, i) && checkDiagonal2(pole, len, i)) continue;
				else successessss++;
				if (successessss==k) return;
			}
		}
	}
}

int main() { //frontend
	int countOfElems=8;
	int len=8;
	int *pole;
	pole = new int(len);
	int k,sum;
	freopen("input.txt", "r", stdin);  //Чтение файла.
	cin >> k;
	fclose(stdin);

	//freopen("CON", "r", stdin);  //Перенаправить чтение обратно в консоль.
	freopen("output.txt", "w", stdout);
	razm(pole,len,countOfElems,k);
	for (int i=0; i<len; i++)
		cout << pole[i] << ' ';
	fclose(stdout);

	//freopen("CON", "w", stdout);  //Перенаправить запись обратно в консоль.
	//system("pause");
	return 0;
}
