#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

typedef struct node *nptr;

typedef struct node
{
	int data;
	nptr *left;
	nptr *right;
};

nptr root;

void createroot()
{
	root = (nptr)malloc(sizeof(struct node));

	if (root == '\0')
	{
		printf("Memory allocaton failed\n");
		exit(0);
	}
	root->data = '\0';
	root->left = '\0';
	root->right = '\0';
}

void insert(int element)
{
	nptr p;
	int x = 0;
	p = root;
	if (root->data == '\0')
	{
		root->data = element;
	}
	else
	{
		while (((element<p->data) && (p->left != '\0')) || ((element>p->data) && (p->right != '\0')) && (x == 0))
		{
			x = 1;
			while ((element<p->data) && (p->left != '\0'))
			{
				p =(nptr)p->left;
				x = 0;
			}
			while ((element>p->data) && (p->right != '\0'))
			{
				p =(nptr)p->right;
				x = 0;
			}
		}
		nptr temp;
		temp = (nptr)malloc(sizeof(struct node));
		temp->data = element;
		temp->left = '\0';
		temp->right = '\0';
		if (element<p->data)
			p->left =(nptr*)temp;
		else
			p->right =(nptr *)temp;
	}
}

void inorder(nptr r)
{
	nptr p;
	p = r;
	if (p != '\0')
	{
		inorder((nptr)p->left);
		printf("%d\t", p->data);
		inorder((nptr)p->right);
	}
}

int main()
{
	int ch;
	int element;
	createroot();
	while (1)
	{
		cout << "Enter choice\n";
		cout << "1.Add\n2.traverse\n3.exit\n";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter element\n";
			cin >> element;
			insert(element);
			break;
		case 2: inorder(root);
			break;
		case 3:exit(0);
		default:exit(0);
		}
	}
	getch();
}