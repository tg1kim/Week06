#include <stdio.h>

#define	SIZE	10
#pragma warning (disable: 4326 4996 6031)

int B[] = {	00,										// 0
			10,	11,									// 1, 2
			20,	21,	22,								// 3, 4, 5
			30,	31,	32,	33,							// 6, 7, 8, 9
			40,	41,	42,	43,	44,						// 10, 11, ...
			50,	51,	52,	53,	54,	55,
			60,	61,	62,	63,	64,	65,	66,
			70,	71,	72,	73,	74,	75,	76,	77,
			80,	81,	82,	83,	84,	85,	86,	87,	88,
			90,	91,	82,	93,	94,	95,	96,	97,	98,	99 };
	// 2차원 하위삼각행렬을 이렇게 1차원 B에 저장했습니다.
	// 값이 지정되지 않은 곳은 0으로 간주합니다.

void main()
{
	while (1) {
		int i, j, nValue;
		printf("index> ");
		scanf("%d", &i);
		if (i < 0)
			break;
		scanf("%d", &j);
		int Aij(int i, int j, int nSize, int &nValue);
		if (Aij(i, j, SIZE, nValue) == false)
			printf("색인 오류, ....\n");
		else
			printf("A[%d][%d] = %d\n", i, j, nValue);
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

int Aij(int i, int j, int nSize, int &nValue)
{	// 적절한 색인이면 nValue에 값을 저장하고 T/F를 return한다.
	if (i < 0 || i >= nSize || j < 0 || j >= nSize)
		return false;
	nValue = (i >= j)				// 행렬의 하위삼각이면
		? B[i * (i + 1) / 2 + j]	// 대응되는 1차원 배열에서
		: 0;						// 행열의 윗 부분은 0이다.
	return true;
}
