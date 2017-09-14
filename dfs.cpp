#include<iostream>
#include<conio.h>
using namespace std;

void dfs(int arr[][20],int n,int visited[],int source)
{
	int i, prd = 1;
	for (i = 0; i < n; i++)
	{
		prd = prd*visited[i];
	}
	if (prd == 1)
	{
		return;
	}
	cout << "node traversed " << source << "\n";
	visited[source] = 1;
	for (i = 0; i < n; i++)
	{
		if ((arr[source][i] == 1) && (visited[i] == 0))
		{
			dfs(arr, n, visited, i);
		}
	}
}

int main()
{
	int i, j, arr[20][20], n, visited[20], source, prd = 1;
	cout << "Enter no. of nodes\n";
	cin >> n;
	cout << "Enter the adjacency matrix row wise \n";
	for (i = 0; i < n; i++)
	{
		visited[i] = 0;
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << "Enter source \n";
	cin >> source;
	dfs(arr, n, visited, source);
	for (i = 0; i < n; i++)
	{
		prd = prd*visited[i];
	}
	if (prd == 0)
	{
		cout << "graph is not connected \n";
	}
	else
	{
		cout << "graph is connected \n";
	}
	getch();
	return 0;
}