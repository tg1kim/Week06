// 윤년 판단 프로그램

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int year;
	printf("연도를 입력하시오: ");
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 || year % 400 == 0)
		printf("%d년은 윤년입니다.\n", year);
	else 
		printf("%d년은 윤년이 아닙니다.\n", year);
}
