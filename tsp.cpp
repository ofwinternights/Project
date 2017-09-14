#include<iostream>
#include<conio.h>
using namespace std;

int cnt = 0, sum = 0, fsum=999;

void permute(int a[], int i, int j, int n, int source, int cost[][10])
{
	sum = 0;
	int src = source;
	if (cnt != 0)
	{
		cout << source << "\t";
		for (int k = 1; k <= n - 1; k++)
		{
			cout << a[k] << "\t";
			sum = sum + cost[src][a[k]];
			src = a[k];
		}
		sum = sum + cost[src][source];
		cout << "cost is : " << sum;
		if (sum < fsum)
		{
			fsum = sum;
		}
		cout << "\n";
	}
	cnt++;
	int temp;
	j++;
	if (j == n)
	{
		return;
	}
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	permute(a, i, j, n, source, cost);
}

void nearest(int source,int cost[][10],int n,int visited[])
{
	int i, index=1, min = 999,src = source;
	cnt++;
	if (cnt == n)
	{
		sum = sum + cost[index][src];
		return;
	}
	for (i = 1; i <= n; i++)
	{
		if ((min > cost[source][i]) && (cost[source][i] != 0) && (visited[i]==0))
		{
			min = cost[source][i];
			index = i;
		}
	}
	visited[index] = 1;
	sum = sum + min;
	min = 999;
	cout << index << "\t";
	nearest(index, cost, n, visited);
}

int main()
{
	int i, j, n, cost[10][10], a[10], source, visited[10];
	cout << "Enter no of vertices\n";
	cin >> n;
	cout << "Enter source\n";
	cin >> source;
	cout << "Enter cost matrix\n";
	for (i = 1; i <= n; i++)
	{
		visited[i] = 0;
		for (j = 1; j <= n; j++)
		{
			cin >> cost[i][j];
		}
	}
	j = 1;
	for (i = 1; i <= n; i++)
	{
		if (i != source)
		{
			a[j] = i;
			j++;
		}
	}
	for (i = 1; i < n; i++)
	{
		cnt = 0;
		permute(a, 1, 1, n, source, cost);
	}
	cout << "optimal solution is : " << fsum;
	cnt = 0;
	sum = 0;
	visited[source] = 1;
	cout << "\n nearest neighbour";
	cout << "\n"<< source << "\t";
	nearest(source, cost, n, visited);
	cout << "\n nearest neighbour solution is : " << sum;
	getch();
	return 0;
}