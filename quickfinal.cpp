#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;

#define max 200

void exch(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void quicksort(int a[max], int low, int high)
{
	int i, j, key;
	i = low + 1;
	j = high;
	key = low;
	if (low >= high)
		return;
	else
	{
		while (i <= j)
		{
			while (a[i] <= a[key])
				i = i + 1;
			while (a[j] > a[key])
				j = j - 1;
			if (i < j)
				exch(&a[i], &a[j]);
		}
		exch(&a[j], &a[key]);
		quicksort(a, low, j - 1);
		quicksort(a, j + 1, high);
	}
}


int main()
{
    int i, n, a[max];
	double start, finish;
	srand(time(NULL));
	cout << "enter the no of integers\n";
	cin >> n;
	cout << "the randomly generated elements of list are\n";
	for (i = 1; i <= n; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " \t";
	}
	cout << endl;
	start = clock();
	quicksort(a, 1, n);
	finish = clock();
	cout << " the sorted elements are\n";
	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " \t";
	}
	cout << endl;
	cout << "the time for quicksort is " << finish - start << "\n";
	getch();
	return 0;
}