#include<stdio.h>
#include<conio.h>

#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void sort(int *arr,int n)
{
	int i, j, min, temp;
	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[i], arr[min], temp);
	}
}

int main()
{
	int arr[10], i;
	int n;
	printf("Enter no of elements\n");
	scanf("%d", &n);
	printf("Enter elements\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, n);
	for (i = 0; i < n; i++)
	{
		printf("%d\t",arr[i]);
	}
	getch();
	return 0;
}