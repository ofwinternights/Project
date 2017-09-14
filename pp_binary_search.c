#include<stdio.h>
#include<conio.h>

#define COMPARE(x,y) (((x)<(y))?-1:((x)==(y))?0:1)

int binary_search(int *arr, int key, int left, int right)
{
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		switch (COMPARE(arr[middle], key))
		{
		case -1:left = middle + 1;
			break;
		case 0:return middle;
			break;
		case 2:left = middle - 1;
			break;
		}
	}
	return -1;
}

int main()
{
	int n, arr[10], i, key, result;
	printf("Enter no of elements\n");
	scanf("%d", &n);
	printf("Enter sorted elements\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter element to be found\n");
	scanf("%d", &key);
	result = binary_search(arr, key, 0, n - 1);
	if (result == -1)
		printf("element not found\n");
	else
		printf("element found at position %d", result);
	getch();
	return 0;
}