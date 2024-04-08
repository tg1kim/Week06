#include <stdio.h>
#pragma warning (disable: 4326 4996 6031)

#define N 10

typedef int Item;
typedef struct stack {
	Item items[N];
	int  nTop;
}	Stack, *StackPtr;

void main()
{
	int  IsEmptyStack(StackPtr pStack);
	int  IsFullStack(StackPtr pStack);
	int  Push(StackPtr pStack, Item nItem);
	int  Pop(StackPtr pStack, Item& nItem);
	void PrintStack(StackPtr pStack);
	int  Error(const char *sMsg);

	/** Create Stack **/
	Stack aStack;

	aStack.nTop = -1;
	while (1) {
		Item nItem;
		printf("-2:Exit -1:Pop, 0~:Push ? ");
		scanf("%d", &nItem);
		if (nItem < -1)
			break;
		if (nItem == -1) {
			if (Pop(&aStack, nItem) == false)
				Error("empty");
			else
				printf("%d is deleted\n", nItem);
		}
		else {
			if (Push(&aStack, nItem) == false)
				Error("full");
			else
				printf("%d is inserted\n", nItem);
		}
		PrintStack(&aStack);
	}
}

int IsEmptyStack(StackPtr pStack)
{	// ������ ��������� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int IsFullStack(StackPtr pStack)
{	// ������ ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int Push(StackPtr pStack, Item nItem)
{	// ���ÿ� nItem�� push�ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// top�� �����Ͽ� ����
	return true;
}

int Pop(StackPtr pStack, Item& nItem)
{	// ���ÿ��� pop�Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�
	// �޾Ƴ��� top�� ����
	return true;
}

void PrintStack(StackPtr pStack)
{
	printf("|    |\n");
	for (int i = pStack->nTop; i >= 0; i--)
		printf("|%3d |\n", pStack->items[i]);
	printf("+----+\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}