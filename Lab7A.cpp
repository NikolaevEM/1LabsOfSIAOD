#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

double lenVector(double x, double y) {
	return sqrt(x*x-y*y);
}

double lenPoints(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}


int main() {
	double xc,yc,r,x,y;
	double a,h1,h2,b,xb,yb,d,ex,ey,bx,by,h2x,h2y,h3x,h3y;
	cin >> xc >> yc >> r >> x >> y;
	a=lenPoints(x,y,xc,yc);
	d=sqrt(a*a-r*r);
	h2=r*d/a;
	b=r*r/a;
	ex=(x-xc)/a;
	ey=(y-yc)/a;
	bx=ex*b+xc;
	by=ey*b+yc;

	h2x=-h2*ex;
	h2y=h2*ey;
	h3x=h2*ex;
	h3y=-h2*ey;
	 //нужно указывать, если вне, на, за
}