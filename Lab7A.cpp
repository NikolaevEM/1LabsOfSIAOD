#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int lenVector(int x, int y) {
	return sqrt(x * x - y * y);
}

int lenPoints(int x1, int y1, int x2, int y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

bool checker(int xc, int yc, int r, int x, int y) {
	if (((x - xc) * (x - xc) + (y - yc) * (y - yc)) < r * r) {
		//“очка принадлежит окружности
		cout << 0 << endl;
		return false;
	}
	else if (((x - yc) * (x - yc) + (y - yc) * (y - yc)) == r * r) {
		//“очка лежит на окружности
		cout << 1 << endl;
		cout << x << ' ' << y;
		return false;
	}
	else {
		return true;
	}
}

int main() {
	int xc, yc, r, x, y;
	int a, h1, h2, b, xb, yb, d, ex, ey, bx, by, h2x, h2y, h3x, h3y;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> xc >> yc >> r >> x >> y;

	if (checker(xc, yc, r, x, y)) {
		a = lenPoints(x, y, xc, yc);
		d = sqrt(a * a - r * r);
		h2 = r * d / a;
		b = r * r / a;
		ex = (x - xc) / a;
		ey = (y - yc) / a;
		bx = ex * b + xc;
		by = ey * b + yc;

		h2x = -h2 * ex;
		h2y = h2 * ey;
		h3x = h2 * ex;
		h3y = -h2 * ey;

		cout << 2 << endl;
		cout << h2x << ' ' << h2y << ' ';
		cout << h3x << ' ' << h3y << endl;
	}

	//нужно указывать, если вне, на, за
	fclose(stdout);
	return 1;
}