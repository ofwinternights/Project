#include<stdio.h>
#include<conio.h>

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void display(int *arr,int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}

void replenish(int *arr, int *rep_arr,int n)
{
	int i;
	for (i = 0; i < n; i++)
		arr[i] = rep_arr[i];
}

void perm(int *arr, int *rep_arr, int *rep_rep_arr, int n)
{
	int i = 0, j, k, x = 0, temp;
	while (i <= n - 1)
	{
		SWAP(arr[0], arr[x], temp);
		SWAP(rep_arr[0], rep_arr[x], temp);
		display(arr, n);
		for (j = 1; j < n - 1; j++)
		{
			for (k = j + 1; k <= n - 1; k++)
			{
				SWAP(arr[j], arr[k], temp);
				display(arr, n);
				replenish(arr, rep_arr, n);
			}
		}
		replenish(arr, rep_rep_arr, n);
		x++;
		i++;
	}
}

int main()
{
	int arr[5], rep_arr[5], rep_rep_arr[5], i, n;
	printf("Enter no of elements\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		rep_arr[i] = arr[i];
		rep_rep_arr[i] = arr[i];
	}
	perm(arr, rep_arr, rep_rep_arr, n);
	getch();
	return 0;
}