#include <stdio.h>

#define MAX_COL	20
#define MAX_TERMS MAX_COL+1	/* max number of terms + 1 */
#pragma warning (disable: 4326 4996 6031)

typedef struct {
	int row;
	int col;
	int value;
}	Term;

void Transpose(Term a[], Term b[]);
void FastTranspose(Term a[], Term b[]);
void PrintSparseMatrix(Term a[]);

void main()
{
	Term a[MAX_TERMS] = {
			{7, 6, 8 },
			{0, 0, 15},
			{0, 3, 22},
			{0, 5,-15},
			{1, 1, 11},
			{1, 2, 3 },
			{2, 3,-6 },
			{4, 0, 91},
			{5, 2, 28},};
	Term b[MAX_TERMS];
	
	int bOK = 1;
	while (bOK) {
		printf("1:Trans, 2:FastTrans, 3:Print a, 4:Print b, 5:Exit ? ");
		int nCmnd;
		scanf("%d", &nCmnd);
		switch (nCmnd) {
		case 1:
			Transpose(a, b);
			PrintSparseMatrix(b);
			break;
		case 2:
			FastTranspose(a, b);
			PrintSparseMatrix(b);
			break;
		case 3:
			PrintSparseMatrix(a);
			break;
		case 4:
			PrintSparseMatrix(b);
			break;
		case 5:
			bOK = 0;
			break;
		default:
			printf("Invalid Command ....\n");
		}
		putchar('\n');
	}
	printf("Bye, ....\n\n");
} 

void Transpose(Term a[], Term b[])
{	/* b is set to the transpose of a */
	int nT = a[0].value;	/* total number of elements */
	b[0].row = a[0].col;	/* rows in b = columns in a */  
	b[0].col = a[0].row; 	/* columns in b = rows in a */  
   	b[0].value = nT;    
	if (nT > 0) { 			/* non zero matrix */    
		//
		// ??????
		//
	} 
}

void FastTranspose(Term a[], Term b[])
{	/* the transepose of a is placed in b */ 
	int nRowCtr[MAX_COL] = { 0 }, nStartPos[MAX_COL];
	int nN = a[0].col, nT = a[0].value;
	b[0].row = nN; b[0].col = a[0].row;
	b[0].value = nT;
	if (nT > 0) {	/* nonzero matrix */
		// 열의 갯수를 센다
		for (;;)
			;
		nStartPos[0] = 1;		// 1부터 시작
		// 시작 위치를 계산한다
		for (;;)
			;
		// 하나씩 전치하여 올바른 위치에 넣는다
 		for (;;) {
   			;
		}                 
	}
}

void PrintSparseMatrix(Term a[])
{
	int nM = a[0].row;
	int nN = a[0].col;
	int nT = a[0].value;
	int k = 1, nValue;
	for (int i = 0; i < nM; i++) {
		for (int j = 0; j < nN; j++) {
			nValue = (k <= nT && i == a[k].row && j == a[k].col) ? a[k++].value : 0;
			printf("%4d", nValue);
		}
		printf("\n");
	}
}