
#include<iostream>
#include<fstream>

using namespace std;

int obhod(int end, int lenReb, int **list, int **m, int cur) {
	for (int i=0;i<lenReb;i++) {
		if (m[i][0]==cur) {   //Если нашли смежную вершину
			list[m[i][1]][0]=1;
			if (list[m[i][1]][2]>1+list[cur][2]) { //Если у соседней вершины minLen больше
				list[m[i][1]][0]=cur;
				list[m[i][1]][2]+=1+list[cur][2];
				if (cur!=m[i][1])   //если соседняя вершина не финальная
					obhod(end, lenReb, list, m, m[i][1]);   //Исследуем соседнюю вершину
			}
		}
	}

	return 1;
}

int printMin(int *answer, int **list, int cur, int start) {
	if (cur!=start)
		printMin(answer, list, list[cur][2], start);

	return 1;
}

int main()
{
	fstream fin("input.txt");
	ofstream fout("output.txt");
    int lenVer, lenReb, start , end, cur;
	int **m;
	int **list;

	fin >> lenVer, lenReb;
	m = new int*[lenReb];
	list = new int*[lenVer];

	for (int i=0;i<lenReb;i++) {  //чтение данных
		m[i] = new int[2];
		fin >> m[i][0] >> m[i][1];
	}

	fin >> start >> end;  //чтение конца и начала

	for (int i=0;i<lenVer;i++) {  //Заполнения списка list [visit] [way] [minLen]
		list[i] = new int[3];
		list[i][0]=0;
		list[i][2]=0;
	}

	list[start][0] = 1;
	list[start][1] = 0;
	cur = 0;

	obhod(end, lenReb, list, m, cur);
	int *answer;
	answer = new int[list[end][2]];
	answer[0] = end;
	printMin(answer, list, end, start);

	for (int i=list[end][2];i>0;i--) {  //Заполнения списка list [visit] [way] [minLen]
		fout << answer[i];
	}
 
    return 0;
}