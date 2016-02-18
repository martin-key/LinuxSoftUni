#include <stdio.h>
#include <math.h>



double calcDist(int _x1,int _y1,int _x2,int _y2)
{
	return sqrt((_x1 - _x2)*(_x1 - _x2) + (_y1 - _y2) * (_y1 - _y2));
}

double calcAngleA(double sideA, double sideB, double sideC)
{
	return acos((sideB*sideB + sideC*sideC - sideA*sideA)/(2*sideB*sideC))*180/M_PI;
}

int main()
{
	int x1,y1,x2,y2,x3,y3;
	scanf("%d,%d;%d,%d;%d,%d;", &x1,&y1,&x2,&y2,&x3,&y3);
	double a,b,c;
	a = calcDist(x2,y2,x3,y3);
	b = calcDist(x1,y1,x3,y3);
	c = calcDist(x1,y1,x2,y2);
	//printf("%f,%f,%f\n", a,b,c); // in order to check length of the sides
	printf("%d,%d,%d\n", (int)calcAngleA(a,b,c), (int)calcAngleA(b,a,c), (int)calcAngleA(c,a,b));
	return 0;
}
