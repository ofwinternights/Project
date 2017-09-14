#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *stk;

struct stack
{
	int top;
}s;

void push(int n)
{
	if (s.top == n-1)
	{
		printf("Stack full \n");
		return;
	}
	printf("Enter element\n");
	scanf("%d", &stk[++s.top]);
}

int pop()
{
	if (s.top == -1)
	{
		printf("stack Empty\n");
		return;
	}
	printf("Element Deleted %d\n", stk[s.top]);
	return stk[s.top--];
}

void display()
{
	int i = 0;
	if (s.top == -1)
	{
		printf("stack Empty\n");
		return;
	}
	for (i = 0; i <= s.top; i++)
	{
		printf("%d\n", stk[i]);
	}
}

void main()
{
	int x = 0,n=0,z=0;
	s.top = -1;
	printf("Enter size of array\n");
	scanf("%d", &n);
	stk = (int *)malloc(n* sizeof(int));
	while (1)
	{
		printf("Choose an operation\n");
		printf("1.Add\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		scanf("%d", &x);
		switch (x)
		{
		case 1:push(n);
			break;
		case 2:z = pop();
			break;
		case 3:display();
			break;
		case 4:return;
		default:exit(0);
		}
	}
	getch();
}