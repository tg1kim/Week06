#include <stdio.h>

#pragma warning(disable: 4326 4996 6031)

void main()
{
	int nSalary, nBlwSum = 0, nRatio;
	while (1) {
		printf("���� ? ");
		scanf("%d", &nSalary);
		if (nSalary <= 0)
			break;
		if (nSalary < 12000000) {
			nRatio = 6;
			nBlwSum = 0;
		}
		if (nSalary >= 12000000) {
			nRatio = 15;
			nBlwSum = 120000 * 9;
		}
		if (nSalary >= 46000000) {
			nRatio = 24;
			nBlwSum += (460000 - 120000) * 15;
		}
		if (nSalary >= 88000000) {
			nRatio = 35;
			nBlwSum += (880000 - 460000) * 24;
		}
		if (nSalary >= 150000000) {
			nRatio = 38;
			nBlwSum += (1500000 - 880000) * 35;
		}
		if (nSalary >= 300000000) {
			nRatio = 40;
			nBlwSum += (3000000 - 1500000) * 38;
		}
		if (nSalary >= 500000000) {
			nRatio = 42;
			nBlwSum += (5000000 - 3000000) * 40;
		}
		if (nSalary >= 1000000000) {
			nRatio = 45;
			nBlwSum += (10000000 - 5000000) * 42;
		}
		// nRatio, nBlwSum
		printf("���� ǥ��: %d\n", nSalary);
		printf("�ҵ漼��: %d %%\n", nRatio);
		int nTax = nSalary / 100 * nRatio;
		printf("(������)�ҵ漼: %d\n", nTax);
		printf("����������: %d\n", nBlwSum);
		printf("���⼼��: %d\n\n", nTax - nBlwSum);
	}
	printf("Bye, ...\n");
}