#include <stdio.h>
#include <math.h>

int main()
//{
//	int a;
//	printf("->");
//	scanf("%d", &a);
//	printf("%d", a);
//}

//{
//	char a[10];
//	printf("->");
//	scanf("%s", &a);
//	printf("%s", a);
//}

//{
//	int r;
//	float area;
//	printf("Enter Radius\n->");
//	scanf("%d", &r);
//	area = 3.14*r*r;
//	printf("Area of circle =%f", area);
//}

//{
//	int a, b, c, out;
//	printf("Enter 2 numbers\n->");
//	scanf("%d %d", &a, &b);
//	out = pow(a,2) + 2*a*b + pow(b,2);
//	printf("a^2 + 2ab + b^2 = %d", out);
//}

//{
//	int a, b, c, out;
//	printf("Enter 2 numbers\n->");
//	scanf("%d %d", &a, &b);
//	out = pow(a,2) - 2*a*b + pow(b,2);
//	printf("a^2 - 2ab + b^2 = %d", out);
//}

//{
//	int a, b, c, out;
//	printf("Enter 2 numbers\n->");
//	scanf("%d %d %d", &a, &b, &c);
//	out = pow(a,3) + pow(b,3) + pow(c,3) - 3*a*b*c;
//	printf("a^3 + b^3 + c^3 - 3abc = %d", out);
//}

//{
//	int p, t, r;
//	float si;
//	printf("Enter Principle: \n->");
//	scanf("%d", &p);
//	printf("Enter Time: \n->");
//	scanf("%d", &t);
//	printf("Enter Rate of Interest: \n->");
//	scanf("%d", &r);
//	si = (p*t*r)/100;
//	printf("Simple Interest =%f", si);
//}

//{
//	int a, b, c, out;
//	printf("Enter 2 numbers\n->");
//	scanf("%d %d %d", &a, &b, &c);
//	out = pow(a,3) + pow(b,3) + pow(c,3) - 3*a*b*c;
//	printf("a^3 + b^3 + c^3 - 3abc = %d", out);
//}

//{
//int time = 20;
//(time < 18) ? printf("Good day.") : printf("Good evening.");
//}

{
	float temp,f;
	printf("Temperature in Celsius");
	scanf("%f", &temp);
	f = temp*(1.8) + 32;
	printf("Temperature in Farhenheit = %f", f);
}
