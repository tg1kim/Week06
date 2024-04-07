#include <stdio.h>

#define	N1	9
#define	N2	8
#define	N3	7
#define	N4	6
#pragma warning (disable: 4326 4996 6031)

void main()
{
	int B[N1][N2][N3][N4];
	int arSize[4] = {N1, N2, N3, N4};

	for (int i = 0; i < arSize[0]; i++)
		for (int j = 0; j < arSize[1]; j++)
			for (int k = 0; k < arSize[2]; k++)
				for (int l = 0; l < arSize[3]; l++)
					B[i][j][k][l] = i * 1000 + j * 100 + k * 10 + l;
	while (1) {
		int i, j, k, l, nValue;
		printf("index> ");
		scanf("%d", &i);
		if (i < 0)
			break;
		scanf("%d", &j);
		scanf("%d", &k);
		scanf("%d", &l);
		int Aij(int A[], int i, int j, int k, int l, int arSize[], int &nValue);
		if (Aij((int *)B, i, j, k, l, arSize, nValue))
			printf("A[%d][%d][%d][%d] = %d(%d)\n", i, j, k, l, B[i][j][k][l], nValue);
		else
			printf("색인 오류, ....\n");
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

int Aij(int A[], int i, int j, int k, int l, int arSize[], int &nValue)
{	// 적절한 색인이면 nValue에 값을 저장하고 T/F를 반환한다.
	return true;
}
