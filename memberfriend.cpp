#include <iostream>
#include <conio.h>
using namespace std;

class B;

class A
{
	int i, j;
public:
	void sum(B&);
};

class B
{
	int m, n;
public:
	friend void A::sum(B&);
};

void A::sum(B& c)
{
	int res;
	i = 10, j = 20;
	c.m = c.n = 10;
	res = i + j + c.m + c.n;
	cout << "sum =" << res;
}

int main()
{
	A a;
	B b;
	a.sum(b);
	getch();
	return 0;
}