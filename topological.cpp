#include<iostream>
#include<conio.h>
using namespace std;

int stk[20], top = -1;

int cal_indeg(int a[][20],int n)
{
	int i, j, k, z, s, sum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			sum = sum + a[j][i];
		}
		if (sum == 0)
		{
			for (k = 0; k < n; k++)
			{
				a[k][i] = 999;
			}
			return i;
		}
		sum = 0;
	}
}

void topo(int source,int a[][20],int n)
{
	int i, j;
	if (top == n-1)
	{
		return;
	}
	for (j = 0; j < n; j++)
	{
		a[source][j] = 0;
	}
	source = cal_indeg(a,n);
	stk[++top] = source;
	topo(source, a, n);
}

int main()
{
	int a[20][20], i, j, n, source;
	cout << "Enter no of vertices\n";
	cin >> n;
	cout << "Enter adjacency matrix\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	source = cal_indeg(a,n);
	cout << "\n";
	stk[++top] = source;
	topo(source, a, n);
	cout << "\n";
	while (top >= 0)
	{
		cout << "Node : " << stk[top--]<<"\n";
	}
	getch();
	return 0;
}