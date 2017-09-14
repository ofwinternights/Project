#include<iostream>
#include<conio.h>
using namespace std;

int p[20], w[20], v[20][20], i, j, n, m;

int max(int a, int b)
{
	return a > b ? a : b;
}

void knapsack(int p[20], int w[20], int v[20][20], int n, int m)
{
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			if ((i == 0) || (j == 0))
			{
				v[i][j] = 0;
			}
			else if (w[i] > j)
			{
				v[i][j] = v[i - 1][j];
			}
			else
			{
				v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]]+ p[i]);
			}
		}
	}
}

void optimal(int v[20][20], int w[20])
{
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			cout << v[i][j] << "\t";
		}
		cout << "\n";
	}
	j = m;
	for (i = n; i >= 1; i--)
	{
		if (v[i][j] != v[i - 1][j])
		{
			cout << "object " << i << " is selected\n";
			j = j - w[i];
		}
		else
		{
			cout << "object "<<i<< "is not selected\n";
		}
	}
}

int main()
{
	cout << "Enter no of objects\n";
	cin >> n;
	cout << "Enter the weight of objects\n";
	for (i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	cout << "Enter the profits of objects \n";
	for (i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	cout << "Enter the capacity of knapsack\n";
	cin >> m;
	knapsack(p, w, v, n, m);
	optimal(v, w);
	cout << "maximum profit is " << v[n][m];
	getch();
	return 0;
}