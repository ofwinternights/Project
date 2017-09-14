#include <iostream>
#include <stdlib.h>
using namespace std;

class list
{
	int data;
	list *next;
public:
	void insertlast();
	void deletelast();
	friend void createhead();
	friend void display();
};

list *h;

void createhead()
{
	h = new list;
	if (h == '\0')
	{
		cout << "No memory allocated" << endl;
		exit(0);
	}
	h->next = '\0';
}

void list::insertlast()
{
	int x;
	list *newnode;
	newnode = new list;
	if (newnode == '\0')
	{
		cout << "No memory allocated" << endl;
		exit(0);
	}
	cout << "Enter an element to be inserted" << endl;
	cin >> x;
	newnode->data = x;
	if (h->next == '\0')
	{
		h->next = newnode;
		newnode->next = '\0';
	}
	else
	{
		list *p;
		p = h->next;
		while (p->next != '\0')
		{
			p = p->next;
		}
		p->next = newnode;
		newnode->next = '\0';
	}
	cout << endl;
	display();
}

void list::deletelast()
{
	if (h->next == '\0')
	{
		cout << "List Empty" << endl;
	}
	else
	{
		list *p, *temp;
		p = h->next;
		temp = h;
		while (p->next != '\0')
		{
			temp = p;
			p = p->next;
		}
		cout << "\nDeleted Element is : " << p->data << "\n";
		free(p);
		temp->next = '\0';
		cout << endl;
		display();
	}
}

void display()
{
	list *p;
	p = h->next;
	if (h->next == '\0')
	{
		cout << "List empty" << endl;
		return;
	}
	while (p->next != '\0')
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << p->data << endl;
}

int main()
{
	int ch;
	list o;
	createhead();
	while (1)
	{
		cout << "Chooose operation" << endl;
		cout << "1.Push" << endl << "2.Pop" << endl << "3.Display" << endl << "4.Exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:o.insertlast();
			break;
		case 2:o.deletelast();
			break;
		case 3:display();
			break;
		case 4:exit(0);
			break;
		default:exit(0);
			break;

		}
	}
}