#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void subsets(int n, int d, int w[])

{

	int s, k, i, x[10];

	for (i = 1; i <= n; i++)

	{

		x[i] = 0;

	}

	s = 0;

	k = 1;

	x[k] = 1;

	while (1)

	{
		if (k <= n&&x[k] == 1) {

			if (s + w[k] == d)

			{

				printf("solution is \n");

				for (i = 1; i <= n; i++)

				{

					if (x[i] == 1)

						printf("%d\t", w[i]);

				}

				printf("\n");

				x[k] = 0;

			}

			else if (s + w[k]<d)

				s += w[k];

			else

				x[k] = 0;



		}

		else

		{

			k--;

			while (k>0 && x[k] == 0)

				k--;

			if (k == 0)

				break;

			x[k] = 0;

			s = s - w[k];

		}

		k++;

		x[k] = 1;

	}

}

int main()

{

	int n, d, i, w[10];

	printf("enter the no of elements:");

	scanf("%d", &n);

	printf("enter the elements \n");

	for (i = 1; i <= n; i++)

		scanf("%d", &w[i]);



	printf("enter the sum value:");

	scanf("%d", &d);

	subsets(n, d, w);

	getch();

	return 0;

}
