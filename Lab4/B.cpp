/* ���� ������, ��������� �� M ������� ��������� ��������.
������� ��� ������������ �������� ������ ������.
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
	if (len<=2) {  //���� ������� ���� ��������� 2 ��������, �� �� ���������� � �������� ���������� �������
		printf("%s",a);
		cout << endl;
		swaper(a,0,1);  //������������
		printf("%s",a);
		cout << endl;
		swaper(a,0,1);  //������� �������� ����������� ������
		return;
	}
	for (int i=0;i<len;i++) { //�� ��������� ����� ���������� ��� ��������
		swaper(a,i,len-1); //i-��� ������� �������� � ��������� ���������
		pereborBezA(a,len-1);
		swaper(a,i,len-1);  //������� �������� ����������� ������
	}
}

int main() { //frontend
	char *a;
	a = new char[9];
	int sum;
	char temp;
	freopen("input.txt", "r", stdin);  //������ �����.
	int len=0;
	while(cin >> temp) {
		a[len]=temp;
		len++;
	}
	fclose(stdin);

	a[len] = 0;  //������������ ����� ������� �� len, ����� ��� printf �� ��������� �����

	//freopen("CON", "r", stdin);  //������������� ������ ������� � �������.
	freopen("output.txt", "w", stdout);
	cout << fact(len) << endl;
	pereborBezA(a,len);
	fclose(stdout);

	//freopen("CON", "w", stdout);  //������������� ������ ������� � �������.
	//system("pause");
	return 0;
}
