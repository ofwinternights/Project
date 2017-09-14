#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



void queens(int);

void printboard(int);

int x[20], soln = 1;



int main() {

	int n;

	printf("enter the no of queens to place:");

	scanf("%d", &n);

	queens(n);

	getch();

	return 0;

}

void queens(int n)

{

	int i, k = 1;

	x[k] = 0;

	while (k != 0)

	{

		x[k] = x[k] + 1;

		while ((x[k] <= n)&&(!place(k, x)))

			x[k] = x[k] + 1;

		if (x[k] <= n)

		{

			if (k == n)

				printboard(n);

			else {

				k++;

				x[k] = 0;

			}

		}

		else k--;

	}

	printf("\n the number of possible solutions are %d", soln - 1);

}

int place(int k, int x[]) {

	int i;

	for (i = 1; i<k; i++)

		if ((x[i] == x[k]) || (i - x[i] == k - x[k]) || (i + x[i] == k + x[k]))

			return 0;

	return 1;

}

void printboard(int n)

{

	int i, j;

	printf("\n solution set %d:", soln);

	for (i = 1; i <= n; i++)

		printf("%d\t", x[i]);

	printf("\n\n placement are as shown below:\n");

	for (i = 1; i <= n; i++) {

		for (j = 1; j <= n; j++)

			(j == x[i]) ? printf("Q%d\t", i) : printf("-\t");

		printf("\n");



	}soln++;



}
