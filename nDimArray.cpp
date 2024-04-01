#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

#define N		7
#define	Size	10000000							// 10의 N승

void main()
{
	int  DefineArray(int arDesc[]);
	void InitArray(int A[], int arDesc[]);
	int  ReadIndex(int arDesc[]);
	void PrintIndex(int arDesc[]);
	int  Aij(int A[], int arDesc[], int &nValue, int &nErrNdx);

	static int Arr[Size];
	int arDesc[2 * N + 1];									// 배열 설명자
	printf("-1을 입력하면 중단하고 다음 단계로 넘어간다.\n\n");
	int nDim, nVal, nErrNdx;
	while (1) {
		if ((nDim = DefineArray(arDesc)) <= 0)				// 배열의 차원을 읽고 배열을 정의
			break;
		InitArray(Arr, arDesc);								// 정의된 차원대로 초기화
		while (1) {
			if (ReadIndex(arDesc) == false)					// 배열의 색인들을 입력
				break;
			PrintIndex(arDesc);
			if (Aij(Arr, arDesc, nVal, nErrNdx))			// 색인에 대응하는 배열의 값
				printf(" = %d", nVal);						// 해당 색인의 배열 값
			else
				printf(" : %d번째 색인오류", nErrNdx);
			printf("\n\n");
		}
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

void InitArray(int A[], int arDesc[])
{	// 정의된 배열에 따라 값을 색인에 맞추어 초기화 한다.
	int nCtr = 1;
	int nDim = arDesc[0];								// 배열의 차원
	int *arNdx = arDesc + 1;							// 각 차원의 색인들
	int *arBound = arDesc + nDim + 1;					// 각 차원의 크기들
	for (int i = 0; i < nDim; i++)
		nCtr *= arBound[i];								// 배열의 크기를 계산
	for (int i = 0; i < nCtr; i++) {
		int nBase = 1, nSize = 1, nValue = 0;
		for (int j = nDim - 1; j >= 0; j--) {
			arNdx[j] = (i / nSize) % arBound[j];		// 각 차원의 색인
			nValue += arNdx[j] * nBase;					// 그 색인에 대응하는 값
			nSize *= arBound[j];
			nBase *= 10;
		}
		A[i] = nValue;									// 배열에 초기화
	}
}

int DefineArray(int arDesc[])
{	// 배열의 차원과 각 차원의 크기도 입력받아 배열의 차원을 반환한다(에러: -1)
	printf("배열을 새롭게 정의합니다.\n");
	printf("배열의 차원(-1, 1 ~ 7) ? ");
	int nDim;
	scanf("%d", &nDim);
	if (nDim < 0 || nDim > 7)
		return false;
	arDesc[0] = nDim;
	printf("\n%d차원 배열의 크기를 입력합니다.\n", nDim);
	int *arBound = arDesc + nDim + 1;					// 각 차원의 크기들
	for (int i = 0; i < nDim; i++) {
		int OK;
		do {
			printf("int A");
			for (int j = 0; j < i; j++)
				printf("[%d]", arBound[j]);
			printf("[?]");
			for (int j = i + 1; j < nDim; j++)
				printf("[ ]");
			printf(" (-1, 2 ~ 10) ? ");
			scanf("%d", arBound + i);					// 각 차원의 크기 입력
			OK = arBound[i] >= 2 && arBound[i] <= 10;	// 차원의 크기 체크
		} while (OK == false);
	}
	printf("\n\t정의된 배열: int A");
	for (int i = 0; i < nDim; i++)						// 정의된 배열을 출력
		printf("[%d]", arBound[i]);
	printf(";\n\t검색할 배열의 색인을 입력합니다.\n\n");
	return nDim;
}

int ReadIndex(int arDesc[])
{	// 배열 설명자에 따라 각 색인을 입력하여 T/F를 반환한다.
	int nDim = arDesc[0];								// 배열의 차원
	int *arNdx = arDesc + 1;							// 각 차원의 색인들
	int *arBound = arDesc + nDim + 1;					// 각 차원의 크기들
	for (int i = 0; i < nDim; i++) {					// 각 차원의 색인을 입력
		printf("\tA");
		for (int j = 0; j < i; j++)
			printf("[%d]", arNdx[j]);
		printf("[?]");
		for (int j = i + 1; j < nDim; j++)
			printf("[ ]");
		printf(" (-1, 0 ~ %d) ? ", arBound[i] - 1);		// 색인의 범위
		scanf("%d", arNdx + i);							// 색인 입력
		if (arNdx[i] < 0)								// 색인이 음수이면
			return false;								// 중단
	}
	return  true;
}

void PrintIndex(int arDesc[])
{
	int nDim = arDesc[0];								// 배열의 차원
	int *arNdx = arDesc + 1;							// 각 차원의 색인들
	printf("\tA");
	for (int i = 0; i < nDim; i++)						// 배열의 각 색인을 출력
		printf("[%d]", arNdx[i]);
}

int Aij(int A[], int arDesc[], int &nValue, int &nErrNdx)
{	// 배열 설명자에 있는 색인에 해당하는 원소를 nValue에 저장하고 T/F를 반환한다.
	// 색인에 오류가 있으면 nErrNdx에 색인 번호를 넣는다.
	// 예를들어 [1][2][30][4]에서 30이 오류이면 왼쪽에서 0부터 세면 2이므로 ErrNdx = 2이 된다.
	// arDesc은 예제 ArrIndex4에서 모든 매개변수 nDim, nNdx, nBound를 순서대로 넣은 것이다.
	// arDesc[0]: 배열의 차원(n)[nDim]
	// arDesc[1]  ~  arDesc[n]:  배열 각 차원의 색인[nNdx]
	// arDesc[n+1] ~ arDesc[2n]: 배열 각 차원의 크기[nBound]
	return true;
}
