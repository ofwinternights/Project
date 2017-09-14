#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node *nptr;

typedef struct node
{
	int data;
	nptr previous;
	nptr next;
};

nptr h;

void createhead()
{
	h = (nptr)malloc(sizeof(struct node));
	if (h == '\0')
	{
		printf("Memory not allocated \n");
		exit(0);
	}
	else
	{
		h->data = '\0';
		h->previous = '\0';
		h->next = '\0';
	}
}

void insertfront()
{
	int x;
	nptr new;
	new = (nptr)malloc(sizeof(struct node));
	if (new == '\0')
	{
		printf("Memory not allocated \n");
		exit(0);
	}
	else if (h->next == '\0')
	{
		printf("Enter Element to be inserted \n");
		scanf("%d", &x);
		new->data = x;
		new->next = h->next;
		new->previous = h;
		h->next = new;
	}
	else
	{
		printf("Enter Element to be inserted \n");
		scanf("%d", &x);
		new->data = x;
		h->next->previous = new;
		new->next = h->next;
		new->previous = h;
		h->next = new;
	}
}

void insertnode()
{
	int key,x;
	nptr new,p;
	printf("Enter element to be found \n");
	scanf("%d", &key);
	p = h->next;
	while ((p->data!=key)&&(p->next!='\0'))
	{
		p = p->next;
	}
	if (p->data == key)
	{
		printf("Node found \n");
		new = (nptr)malloc(sizeof(struct node));
		if (new == '\0')
		{
			printf("Memory not allocated \n");
			exit(0);
		}
		printf("Enter element to be inserted \n");
		scanf("%d", &x);
		new->data = x;
		new->previous = p->previous;
		new->next = p;
		p->previous->next = new;
		p->previous = new;
	}
	else
	{
		printf("no such element found \n");
	}
}

void deletenode()
{
	int key;
	nptr p;
	p = h;
	printf("Enter Element to be deleted \n");
	scanf("%d", &key);
	while ((p->data != key) && (p->next != '\0'))
	{
		p = p->next;
	}
	if (p->data == key)
	{
		printf("Element Deleted \n");
		if (p->next == '\0')
		{
			p->previous->next = p->next;
			free(p);
		}
		else
		{
			p->previous->next = p->next;
			p->next->previous = p->previous;
			free(p);
		}
	}
	else
	{
		printf("No such Element found \n");
	}
}

void display()
{
	nptr p;
	p = h->next;
	if (h->next == '\0')
	{
		printf("node empty \n");
		return;
	}
	while (p->next != '\0')
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("%d\t\n", p->data);
}

void main()
{
	int ch;
	createhead();
	while (1)
	{
		printf("Chooose operation\n");
		printf("1.Add element\n2.Add node\n3.delete\n4.Display\n5.Exit\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:insertfront();
			break;
		case 2:insertnode();
			break;
		case 3:deletenode();
			break;
		case 4:display();
			break;
		case 5:exit(0);
			break;
		default:exit(0);
			break;
		}
	}
	getch();
}

