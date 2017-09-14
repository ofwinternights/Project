#include<iostream>
#include<conio.h>
using namespace std;

int n, i, instant=0, tempbt=999, temppno;

typedef struct
{
	int pno, at, bt,ct,sno,v;
}v;

v p[10];

int sum()
{
	int bt_sum = 0;
	for (i = 0; i < n; i++)
	{
		bt_sum = bt_sum + p[i].bt;
	}
	return bt_sum;
}

void srtf()
{
	int bt_sum;
	bt_sum = sum();
	while (instant<=bt_sum)
	{
		for (i = 0; i < n; i++)
		{
			if ((p[i].bt < tempbt) && (p[i].at <= instant) && (p[i].bt != 0))
			{
				tempbt = p[i].bt;
				temppno = p[i].pno;
				if (p[i].v == 0)
				{
					p[i].v = 1;
					p[i].sno = instant;
				}
				
			}
		}
		instant=instant+1;
		p[temppno].bt = p[temppno].bt - 1;
		if (p[temppno].bt == 0)
		{
			p[temppno].ct = instant;
		}
		tempbt = 999;
	}
	
}

int main()
{
	cout << "Enter no. of processes\n";
	cin >> n;
	cout << "Enter process no, at & bt";
	for (i = 0; i < n; i++)
	{
		cin >> p[i].pno;
		cin >> p[i].at;
		cin >> p[i].bt;
		p[i].v = 0;
	}
	srtf();
	for (i = 0; i < n; i++)
	{
		cout << "process " << p[i].pno << " start time " << p[i].sno << " end time " << p[i].ct << "\n";
	}
	getch();
	return 0;
}