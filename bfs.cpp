#include<iostream>
#include<conio.h>
using namespace std;

int queue[20], front = 0, rear = -1, cnt=-1;

void bfs(int source, int a[][20], int *visited,int n)
{
	int i,j;
	cnt++;
	if ((cnt == n) || (source == 999))
	{
		return;
	}
	visited[source] = 1;
	cout << "Node traversed: " << source << "\n";
	for (j = 0; j < n; j++)
	{
		if ((a[source][j] != 0)&&(visited[j]==0))
		{
			queue[++rear] = j;
			visited[j] = 1;
		}
	}
	bfs(queue[++front], a, visited, n);
}


int main()
{
	int a[20][20],source, i, j, n,visited[10];
	cout << "Enter no of nodes\n";
	cin >> n;
	cout << "Enter adjacency matrix\n";
	for (i = 0; i < n; i++)
	{
		visited[i] = 0;
		queue[i] = 999;
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "Enter source\n";
	cin >> source;
	queue[++rear] = source;
	bfs(source, a, visited, n);
	getch();
	return 0;
}