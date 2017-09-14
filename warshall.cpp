#include<iostream>
#include<conio.h>
using namespace std;

void warshall(int a[][20], int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				a[j][k] = a[j][k] || (a[j][i] && a[i][k]);
			}
		}
	}
}

int main()
{
	int a[20][20], n, i, j;
	cout << "Enter the no. of nodes\n";
	cin >> n;
	cout << "Enter tha adjacency matrix \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "Matrix entered is \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j]<<"\t";
		}
		cout << "\n";
	}
	warshall(a, n);
	cout << "\n";
	cout << "Transitive closure of matrix is \n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j]<<"\t";
		}
		cout << "\n";
	}
	getch();
	return 0;
}