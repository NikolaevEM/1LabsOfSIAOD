/* ���� ������, ��������� �� M ������� ��������� ��������.
������� ��� ������������ �������� ������ ������.
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
using namespace std;

void swaper(char *a, int i1, int i2) {
	char temp=a[i1];
	a[i1]=a[i2];
	a[i2]=temp;
}

void pereborBezA(char *a, int len) {
	for (int
}

int main() { 
	char *a;
	a = new char[8];
	int sum;
	char temp;
	freopen("input.txt", "r", stdin);  //������ �����.
	int len=0;
	while(cin >> temp) {
		a[len]=temp;
		len++;
	}
	fclose(stdin);
	//freopen("CON", "r", stdin);  //������������� ������ ������� � �������.
	freopen("output.txt", "w", stdout);
	for (int i=0;i<len;i++)
		cout << a[i];
	fclose(stdout);

	//freopen("CON", "w", stdout);  //������������� ������ ������� � �������.
	//system("pause");
	return 0;
}
