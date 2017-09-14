//STACK USING LINKED LIST

#include<iostream>
#include<conio.h>

using namespace std;

typedef struct node *nptr;

typedef struct node
{
	int data;
	nptr *downLink;
	nptr *rightLink;
};

nptr createnode()
{
	nptr vertex = (nptr)malloc(sizeof(struct node));
	if (vertex == '\0')
	{
		cout << "Memory allocation failed\n";
		exit(0);
	}
	cout <<"address "<< &vertex<<"\n";
	return vertex;
}

nptr push(nptr vertex)
{
	int element;
	cout << "Enter Element :";
	cin >> element;
	cout << "\n\n";
	vertex->data = element;
	vertex->downLink = '\0';
	vertex->rightLink = '\0';
	return vertex;
}

int main()
{
	int ch;
	nptr *top = '\0', *temp;
	nptr vertex;
	while(1)
	{
		cout << "1.Push Element\n2.Pop Element\n3.Peek\n4.Get Minimum Element\n5.Exit\nEnter : ";
		cin >> ch;
		cout << "\n\n";
		switch (ch)
		{
		case 1: vertex = createnode();
			vertex = push(vertex);
			if (top != '\0')
			{
				vertex->downLink = top;
			}
			top = &vertex;
			break;
		case 2:cout<< (*top)->downLink;
			top = (*top)->downLink;
			break;
		case 3: cout << (*top)->data<<"\n\n";
			break;
		case 4: cout << "hi";
			break;
		default:exit(0);
		}
	}
	
	getch();
	return 0;
}