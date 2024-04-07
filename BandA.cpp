#include <stdio.h>

#define	SIZE	10
#pragma warning (disable: 4326 4996 6031)

int B[] = {	00, 01,										// 0, 1,
			10, 11, 12,									// 2, 3, 4,
				21, 22,	23,								// 5, 6, 7,
					32,	33,	34,							// 8, ....
						43,	44,	45,
							54,	55,	56,
								65,	66,	67,
									76,	77,	78,
										87,	88,	89,
											98,	99	};

void main()
{
	while (1) {
		int i, j, nValue;
		printf("index> ");
		scanf("%d", &i);
		if (i < 0)
			break;
		scanf("%d", &j);
		int Aij(int i, int j, int nSize, int *pValue);
		if (Aij(i, j, SIZE, &nValue) == false)
			printf("색인 오류, ....\n");
		else
			printf("A[%d][%d] = %d\n", i, j, nValue);
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

int Aij(int i, int j, int nSize, int *pValue)
{	// 2차원 배열 A가 1차원 배열 B로 저장할 때 A[i][j]에 해당하는 B[?]를 pValue에 저장하고 T/F를 반환한다.
	if (i < 0 || i >= nSize || j < 0 || j >= nSize)
		return false;
	*pValue = (i - 1 <= j && j <= i + 1)	// 밴드
		? B[2 * i + j]						// 밴드 내의 원소로 매핑
		: 0;								// 밴드 이외의 원소
	return true;
}
