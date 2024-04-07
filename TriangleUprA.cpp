#include <stdio.h>

#define	SIZE	10
#pragma warning (disable: 4326 4996 6031)

int B[] = {	 0,	 1,  2,  3,  4,  5,  6,  7,  8,  9,	// 0,  1,  ...
			    11,	12, 13, 14, 15, 16, 17, 18,	19,	// 10, 11, ...
					22,	23, 24, 25, 26, 27,	28, 29,	// 19, 20, ...
						33,	34, 35, 36,	37, 38, 39,	// 27, 28, ...
							44,	45, 46, 47, 48,	49,	// 34, 35, ...
								55, 56, 57, 58, 59,
									66, 67, 68, 69,
										77, 78, 79,
											88, 89,
												99 };
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
		int Aij(int i, int j, int n, int &nValue);
		if (Aij(i, j, SIZE, nValue) == false)
			printf("색인 오류, ....\n");
		else
			printf("A[%d][%d] = %d\n", i, j, nValue);
	}
	printf("Bye, ....\n\n");
}

int Aij(int i, int j, int nSize, int &nValue)
{
	/* 적절한 색인이면 nValue에 값을 저장하고 T/F를 return한다. */
	if (i < 0 || j < 0 || i >= nSize || j >= nSize)
		return false;
	nValue = (i <= j)							// 행렬의 상위삼각이면
		? B[nSize * i - i * (i + 1) / 2 + j]	// 대응되는 1차원 배열에서
		: 0;									// 행열의 아랫 부분은 0이다.
	return true;
}
