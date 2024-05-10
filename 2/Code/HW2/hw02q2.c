#include <stdio.h>
#pragma warning(disable : 4996)

int subf(int a, int b)
{
	return a - b;
}

#define subm(a,b) (a - b)

int cubef(int a)
{
	return a* a* a;
}

#define cubem(a) (a*a*a)

int distancef(int a, int b)
{
	if (a > b)
	{
		return a - b;
	}
	else
	{
		return b - a;
	}
}

#define distancem(a, b) ((a > b) ? (a - b) : (b - a))

int maxf(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

#define maxm(a, b) ((a>b) ? (a) : (b))

void main()
{
	int a = 7, b = 2;
	printf("subf(a, b) = %d\n", subf(a, b));
	printf("subm(a, b) = %d\n", subm(a, b));
	printf("subf(a++, b--) = %d\n", subf(a++, b--));

	a = 7; b = 2;// reset a,b values
	printf("subm(a++, b--) = %d\n", subm(a++, b--));

	a = 7; b = 2;
	printf("cubef(a) = %d\n", cubef(a));
	printf("cubem(a) = %d\n", cubem(a));
	printf("cubef(--a) = %d\n", cubef(--a));

	a = 7; b = 2;
	printf("cubem(--a) = %d\n", cubem(--a));

	a = 7; b = 2;
	printf("distancef(a, b) = %d\n", distancef(a, b));
	printf("distancem(a, b) = %d\n", distancem(a, b));
	printf("distancef(--a, --b) = %d\n", distancef(--a, --b));

	a = 7; b = 2;
	printf("distancem(--a, --b) = %d\n", distancem(--a, --b));

	a = 7; b = 2;
	printf("maxf(a, b) = %d\n", maxf(a, b));
	printf("maxm(a, b) = %d\n", maxm(a, b));
	printf("maxf(a++, b) = %d\n", maxf(a++, b));

	a = 7; b = 2;
	printf("maxm(a++, b) = %d\n", maxm(a++, b));
}

