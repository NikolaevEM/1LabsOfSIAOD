/* Дано n предметов, каждый из которых характеризуется весом wi и полезностью pi.
Необходимо выбрать некоторый набор этих предметов так, чтобы суммарный вес этого
набора не превышал W, а суммарная полезность была максимальна. 
Ваша задача состоит в том, чтобы написать программу, решающую задачу о рюкзаке. 
Формат входного файла 
Первая строка входного файла содержит натуральные числа n (1≤ n≤20) и W (1≤ W≤ 109).
Каждая из последующих n строк содержит описание одного предмета. Каждое описание
состоит из двух чисел: wi — веса предмета и pi — его полезности (1≤ wi,pi≤109). 
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {  //Нужно переписать программу, слишком много памяти жрет
	int temp,n,m,s=0,w;
	int **in;		// Данные w и p камней
	int ***tabl;  /* - Наша таблица. tabl[kam][maxW][field]:
					kam - номер камня
					maxW - макс вес сумки по допущению
					field - содержит суммарный w и p камней */

	freopen("input.txt", "r", stdin);  //Чтение файла.
	cin >> n;
	in = new int*[n];
	tabl = new int**[n];
	cin >> w;
	for (int kam=0; kam<n; kam++) {  //Инициализация массивов, ввод данных
		in[kam] = new int[2];
		tabl[kam] = new int*[w+1];
		cin >> temp;
		in[kam][0]=temp;
		cin >> temp;
		in[kam][1]=temp;
	}
	fclose(stdin);
	//freopen("CON", "r", stdin);  //Перенаправить чтение обратно в консоль.

	for (int maxW=0; maxW<w+1; maxW++) {  //заполнение первой строки таблицы, т.е рассматриваем первый камень
		tabl[0][maxW] = new int[2];
		if (maxW >= in[0][0]) {  //Если можно впихнуть камень
			tabl[0][maxW][0]=in[0][0];
			tabl[0][maxW][1]=in[0][1];
		} else {
			tabl[0][maxW][0]=0;
			tabl[0][maxW][1]=0;
		}
	}

	for (int kam=1; kam<n; kam++)
		for (int maxW=0; maxW<w+1; maxW++) {  //заполнение всей таблицы
			tabl[kam][maxW] = new int[2];
			if (maxW-in[kam][0]>=0 && maxW >= in[kam][0]+tabl[kam-1][maxW-in[kam][0]][0]) {  //Если можно впихнуть этот камень
				if (tabl[kam-1][maxW][1] < tabl[kam-1][maxW-in[kam][0]][1] + in[kam][1]) {  //Выбираем из 2 вар макс
					tabl[kam][maxW][0]=tabl[kam-1][maxW-in[kam][0]][0] + in[kam][0];  //Ячейка = предыдущие данные[maxW-w камня] + данные камня
					tabl[kam][maxW][1]=tabl[kam-1][maxW-in[kam][0]][1] + in[kam][1];
				}
				else {
					tabl[kam][maxW][0]=tabl[kam-1][maxW][0];  //Ячейка = предыдущие данные
					tabl[kam][maxW][1]=tabl[kam-1][maxW][1];
				}
			}
			else {  //Если нельзя впихнуть еще 1 камень
				tabl[kam][maxW][0]=tabl[kam-1][maxW][0];  //Ячейка = предыдущие данные
				tabl[kam][maxW][1]=tabl[kam-1][maxW][1];
			}
		}

	int max=0;
	for (int maxW=0; maxW<w+1; maxW++) {
		if (max < tabl[n-1][maxW][1])
			max = tabl[n-1][maxW][1];
	}

	freopen("output.txt", "w", stdout);
	cout << max;  //выводим самый последний результат сумки с макс предельным весом
	fclose(stdout);

	//freopen("CON", "w", stdout);  //Перенаправить запись обратно в консоль.
	//system("pause");
	return 0;
}