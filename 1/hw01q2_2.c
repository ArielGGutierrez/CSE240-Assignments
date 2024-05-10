/* This C program demonstrates the switch statement without using breaks. */
#include<stdio.h>
void main() {
	char ch; 
	int a = 10, b = 20; 
	double f;
	int i;
	for(i = 0; i < 5; i = i + 1)
	{
		printf("Enter math operation: ");
		ch = getchar();
		printf("ch = %c\n", ch);
		switch(ch)
		{ 
			case'+': f = a + b; printf("f = %f\n", f); break;
			case'-': f = a - b; printf("f = %f\n", f); break;
			case'*': f = a * b; printf("f = %f\n", f); break;
			case'/': f = (float) a / b; printf("f = %f\n", f); break;
			default: printf("invalid operator\n");
		}
		ch = getchar();
	}
} 
