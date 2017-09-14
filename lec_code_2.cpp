#include<iostream>
#include<conio.h>
using namespace std;

#define max 10

void push(int *stk,int *top,int element)
{
	if (*top == max-1)
	{
		cout << "stack full\n";
		return;
	}
	stk[++*top] = element;
}

int pop(int *stk,int *top)
{
	if (*top == -1)
	{
		cout << "stack empty\n";
		exit(0);
	}
	return stk[(*top)--];
}

int main()
{
	int arr[max], i, stk[max], top = -1, n, temp;
	cout << "Enter no of elements\n";
	cin >> n;
	cout << "Enter Elements\n";
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	push(stk, &top, 999);
	i = 0;
	while (i<n)
	{
		if (arr[i] < stk[top])
		{
			push(stk, &top, arr[i]);
		}
		else
		{
			while (arr[i] > stk[top])
			{
				temp = pop(stk, &top);
				cout << temp << " has right greater no: " << arr[i] << "\n";
			}
			push(stk, &top, arr[i]);
		}
		i++;
	}
	while (top > 0)
	{
		temp = pop(stk, &top);
		cout << temp << " has right greater no: -1" << "\n";
	}
	getch();
	return 0;
}