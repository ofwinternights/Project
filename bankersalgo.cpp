#include<iostream>
#include<conio.h>
using namespace std;

int p, r, i, j, maxneed[10][10], all[10][10], need[10][10], avail[1][10], cnt = 0, k, v = 0, ans = 0, pno, t[1][10], pem_avail[1][10];

void banker()
{
	i = 0;
	j = 0;
	v = 0;
	cnt = 0;
	while (cnt < p)
	{
		while ((j < r) && (i < p))
		{
			if (need[i][j] <= avail[0][j])
			{
				j++;
			}
			else
			{
				j = 0;
				i++;
			}
			if (j == r )
			{
				cout << " process " << i;
				for (k = 0; k < r; k++)
				{
					avail[0][k] = avail[0][k] + all[i][k];
				}
				need[i][0] = 999;
				v = 1;
			}
		}
		j = 0;
		i=0;
		cnt++;
	}
	if (v == 0)
	{
		cout << "Request can't be allocated\n";
		getch();
		exit(0);
	}
}

void calculateneed()
{
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < r; j++)
		{
			need[i][j] = maxneed[i][j] - all[i][j];
		}
	}
}

int main()
{
	cout << "Enter no of processes\n";
	cin >> p;
	cout << "Enter no of resources\n";
	cin >> r;
	cout << "Enter maximum matrix\n";
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < r; j++)
		{
			cin >> maxneed[i][j];
		}
	}
	cout << "Enter available resources\n";
	for (i = 0; i < r; i++)
	{
		cin >> avail[0][i];
		pem_avail[0][i] = avail[0][i];
	}
	cout << "Enter allocated matrix\n";
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < r; j++)
		{
			cin >> all[i][j];
		}
	}
	cout << "Need matrix is \n";
	calculateneed();
	banker();
	while (ans == 0)
	{
		cout << "\nwould you like to add new request (press 0 to add)\n";
		cin >> ans;
		if (ans == 0)
		{
			cout << "Enter process no\n";
			cin >> pno;
			cout << "Enter new request of resources to add\n";
			calculateneed();
			for (i = 0; i < r; i++)
			{
				avail[0][i] = pem_avail[0][i];
				cin >> t[pno][i];
				if (t[pno][i]>need[pno][i])
				{
					cout << "Invalid entry\n";
					getch();
					exit(0);
				}
				else
				{
					if (avail[0][i] >= t[pno][i])
					{
						avail[0][i] = avail[0][i] - t[pno][i];
						need[pno][i] = need[pno][i] - t[pno][i];
						all[pno][i] = all[pno][i] + t[pno][i];
					}
					else
					{
						cout << "can't be allocated \n";
						getch();
						exit(0);
					}
				}
			}
			banker();
		}
		else
		{
			exit(0);
		}
	}
	getch();
	return 0;
}