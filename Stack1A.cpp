#include <stdio.h>
#pragma warning (disable: 4326 4996 6031)

#define N 10

typedef int Item;

void main()
{
	int  IsEmptyStack(int nTop);
	int  IsFullStack(int nTop);
	int  Push(Item aStack[], int& nTop, Item nItem);
	int  Pop(Item aStack[], int& nTop, Item& nItem);
	void PrintStack(Item aStack[], int nTop);
	int  Error(const char *sMsg);

	/** Create Stack **/
	Item aStack[N];
	int nTop;

	nTop = -1;
	while (1) {
		Item nItem;
		printf("-2:Exit -1:Pop, *:Push ? ");
		scanf("%d", &nItem);
		if (nItem < -1)
			break;
		if (nItem == -1) {
			if (Pop(aStack, nTop, nItem) == false)
				Error("empty");
			else
				printf("%d is deleted\n", nItem);
		}
		else {
			if (Push(aStack, nTop, nItem) == false)
				Error("full");
			else
				printf("%d is inserted\n", nItem);
		}
		PrintStack(aStack, nTop);
	}
}

int IsEmptyStack(int nTop)
{	// 스택이 비었는지에 따라 T/F를 반환한다.
	return nTop < 0;
}

int IsFullStack(int nTop)
{	// 스택이 가득 찼는지에 따라 T/F를 반환한다.
	return nTop >= N - 1;
}

int Push(Item aStack[], int& nTop, Item nItem)
{	// 스택에 nItem을 push하는데 승패에 따라 T/F를 반환한다.
	if (IsFullStack(nTop))
		return false;
	aStack[++nTop] = nItem;	// top을 증가하여 삽입
	return true;
}

int Pop(Item aStack[], int& nTop, Item& nItem)
{	// 스택에서 pop하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	if (IsEmptyStack(nTop))
		return false;
	nItem = aStack[nTop--];	// 받아내고 top을 감소
	return true;
}

void PrintStack(Item aStack[], int nTop)
{
	printf("|    |\n");
	for (int i = nTop; i >= 0; i--)
		printf("|%3d |\n", aStack[i]);
	printf("+----+\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}
