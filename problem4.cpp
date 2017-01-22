
//The language used in this program is c++
//This program is made with Microsoft Visual Studio Built-in compiler

#include<iostream>
#include<conio.h>
using namespace std;

struct 
{
	int elem, row, column;
}arr[4];

int nextrow(int r,int c,int grid[][3])
{
	r = r + 1;
	if (r > 2)
	{
		return 999;
	}
	return grid[r][c];
}

int nextcolumn(int r, int c, int grid[][3])
{
	c = c + 1;
	if (c > 2)
	{
		return 999;
	}
	return grid[r][c];
}

int previousrow(int r, int c, int grid[][3])
{
	r = r - 1;
	if (r < 0)
	{
		return 999;
	}
	return grid[r][c];
}

int previouscolumn(int r, int c, int grid[][3])
{
	c = c - 1;
	if (c < 0)
	{
		return 999;
	}
	return grid[r][c];
}

void bubble_sort(int n)
{
    int i, j, t, tr, tc;
    for (i = 0; i < (n - 1); i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].elem > arr[j + 1].elem)
			{
				t = arr[j].elem;
				arr[j].elem = arr[j + 1].elem;
				arr[j + 1].elem = t;
				tr = arr[j].row;
				arr[j].row = arr[j + 1].row;
				arr[j + 1].row = tr;
				tc = arr[j].column;
				arr[j].column = arr[j + 1].column;
				arr[j + 1].column = tc;
			}
		}
	}
}

int main()
{
	int grid[3][3], i, j, r, c, pick_elem = 0, temp_elem, k = 3, prev_elem;
	cout << "Enter heights of column row wise\n";
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			cin >> grid[i][j];
		}
	}
	cout << "Enter starting row\n";
	cin >> r;
	cout << "Enter starting column\n";
	cin >> c;
	prev_elem = grid[r][c];
	if ((r <= 2 && r >= 0) && (c >= 0 && c <= 2))
	{
		while (pick_elem < prev_elem)
		{
			temp_elem = nextrow(r, c, grid);
			arr[0].elem = temp_elem;
			arr[0].row = r + 1;
			arr[0].column = c;
			temp_elem = nextcolumn(r, c, grid);
			arr[1].elem = temp_elem;
			arr[1].row = r;
			arr[1].column = c + 1;
			temp_elem = previousrow(r, c, grid);
			arr[2].elem = temp_elem;
			arr[2].row = r - 1;
			arr[2].column = c;
			temp_elem = previouscolumn(r, c, grid);
			arr[3].elem = temp_elem;
			arr[3].row = r;
			arr[3].column = c - 1;
			bubble_sort(4);
			while ((arr[k].elem == 999)||(arr[k].elem > grid[r][c]))
			{
				k--;
			}
			pick_elem = arr[k].elem;
			cout << "(" << r << "," << c << ")" << " -> ";
			prev_elem = grid[r][c];
			r = arr[k].row;
			c = arr[k].column;
			if (k < 0)
			{
				pick_elem = 999;
			}
			k = 3;
		}
	}
	else
	{
		cout << "Invalid input\n";
		exit(1);
	}
	cout << "exit";
	getch();
	return 0;
}