#include <iostream>
#include <stdlib.h>
using namespace std;

class list
{
	int data;
	list *next;
public:
	void insertfront();
	void deletefront();
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

void list::insertfront()
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
	newnode->next = h->next;
	h->next = newnode;
	cout << endl;
	display();
}

void list::deletefront()
{
	if (h->next == '\0')
	{
		cout << "List Empty" << endl;
	}
	else
	{
		list *p;
		p = h->next;
		h->next = p->next;
		free(p);
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

void findMiddle()
{
	list *slow;
	list *fast;

}

int main()
{
	int ch;
	list o;
	createhead();
	while (1)
	{
		cout << "Chooose operation" << endl;
		cout << "1.Add" << endl << "2.Delete" << endl << "3.Display" << endl << "4.Exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:o.insertfront();
				break;
		case 2:o.deletefront();
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