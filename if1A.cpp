#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int number;
	printf("정수를 입력하시오: ");
	scanf("%d", &number);
	if (number > 0) 
		printf("양수입니다.\n");
	printf("입력된 값은 %d입니다.\n", number);
}