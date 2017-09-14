#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int prd = 1, tcost = 0;

void prim(int arr[][10], int trace[][10], int source, int n, int visited[],int count)
{
	count++;
	int i, min = trace[0][0], index = 0;
	if (count == n)
	{
		return;
	}
	for (i = 1; i<n; i++)
	{
		if (min>trace[0][i])
		{
			min = trace[0][i];
			index = i;
		}
	}
	cout << "from :" << trace[1][index] << " -> to :" << index << "\n";
	cout << "cost :" << min << "\n";
	tcost = tcost + min;
	visited[index] = 1;
	trace[0][index] = 999;
	trace[1][index] = index;
	for (i = 0; i<n; i++)
	{
		if ((trace[0][i]>arr[index][i]) && (visited[i] == 0))
		{
			trace[0][i] = arr[index][i];
			trace[1][i] = index;
		}
	}
	prim(arr, trace, index, n, visited,count);
}

int main()
{
	int arr[10][10], source, n, i, j, trace[2][10], visited[10],count=0;
	cout << "Enter no of nodes \n";
	cin >> n;
	cout << "Enter adjacency matrix \n";
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << "Enter source\n";
	cin >> source;
	for (i = 0; i<n; i++)
	{
		visited[i] = 0;
		trace[0][i] = arr[source][i];
		trace[1][i] = source;
	}
	visited[source] = 1;
	prim(arr, trace, source, n, visited,count);
	cout << "\ntotal cost :" << tcost;
	getch();
	return 0;
}


