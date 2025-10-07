#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

void main()
{
	int nSalary, nBlwSum, nRatio;
	while (1) {
		printf("연봉 ? ");
		scanf("%d", &nSalary);
		if (nSalary <= 0)
			break;
		if (nSalary <= 12000000) {
			nRatio = 6;
			nBlwSum = 0;
		}
		else if (nSalary <= 46000000) {
			nRatio = 15;
			nBlwSum = 1080000;
		}
		else if (nSalary <= 88000000) {
			nRatio = 24;
			nBlwSum = 5220000;
		}
		else if (nSalary <= 150000000) {
			nRatio = 35;
			nBlwSum = 14900000;
		}
		else if (nSalary <= 300000000) {
			nRatio = 38;
			nBlwSum = 19400000;
		}
		else if (nSalary <= 500000000) {
			nRatio = 40;
			nBlwSum = 25400000;
		}
		else if (nSalary <= 1000000000) {
			nRatio = 42;
			nBlwSum = 35400000;
		}
		else {
			nRatio = 45;
			nBlwSum = 65400000;
		}
		// nRatio, nBlwSum
		printf("과세 표준: %d\n", nSalary);
		printf("소득세율: %d %%\n", nRatio);
		int nTax = nSalary / 100 * nRatio;
		printf("(공제전)소득세: %d\n", nTax);
		printf("누진공제액: %d\n", nBlwSum);
		printf("산출세액: %d\n\n", nTax - nBlwSum);
	}
	printf("Bye, ...\n");
}