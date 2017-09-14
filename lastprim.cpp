#include<iostream>
#include<conio.h>
using namespace std;

void prim(int cost[][10], int n,int source,int a[][10],int visited[])
{
	int i, j, nextsource;
	int min = 999;
	int prd = 1;
	for (i = 1; i <= n; i++)
	{
		prd = prd*visited[i];
	}
	if (prd == 1)
	{
		return;
	}
	for (i = 1; i <= n; i++)
	{
		if (min > a[0][i])
		{
			min = a[0][i];
			nextsource = i;
		}
	}
	cout << "from " <<a[1][nextsource] << " -> " << nextsource << "\n";
	a[0][nextsource] = 999;
	a[1][nextsource] = nextsource;
	for (i = 1; i <= n; i++)
	{
		if ((cost[nextsource][i] <= a[0][i]) && (visited[i] == 0))
		{
			a[0][i] = cost[nextsource][i];
			a[1][i] = nextsource;
		}
	}
	visited[nextsource] = 1;
	prim(cost, n, nextsource, a, visited);
}

int main()
{
	int n, i, j, cost[10][10],source,visited[10],a[2][10];
	cout << "Enter no of vertices\n";
	cin >> n;
	cout << "Enter cost matrix\n";
	for (i = 1; i <= n; i++)
	{
		visited[i] = 0;
		for (j = 1; j <= n; j++)
		{
			cin >> cost[i][j];
		}
	}
	cout << "Enter source\n";
	cin >> source;
	visited[source] = 1;
	for (i = 1; i <= n; i++)
	{
		a[0][i] = cost[source][i];
		a[1][i] = source;
	}
	prim(cost, n, source, a, visited);
	getch();
	return 0;
}