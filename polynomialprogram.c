#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct poly *ptr;

typedef struct poly
{
	int coeff;
	int exp;
	ptr next;
};

ptr h[3];
ptr temp[2];
int high[2];
int count,past;
int a[2],n,z;

void createhead()
{
	h[0] = (ptr)malloc(sizeof(struct poly));
	h[1] = (ptr)malloc(sizeof(struct poly));
	h[2] = (ptr)malloc(sizeof(struct poly));
	if ((h[0] == '\0') || (h[1] == '\0'))
	{
		printf("Memory allocation failed \n");
		exit(0);
	}
	h[0]->next = '\0';
	h[1]->next = '\0';
	h[2]->next = '\0';
}

void insert(int x)
{
	int n,i;
	printf("Enter no. of terms\n");
	scanf("%d", &a[x]);
	printf("Enter in increasing order of exponent \n");
	for (i = 0; i < a[x]; i++)
	{
		ptr new;
		new = (ptr)malloc(sizeof(struct poly));
		if (new == '\0')
		{
			printf("Memory allocation failed\n");
			exit(0);
		}
		printf("Enter exponent \n");
		scanf("%d", &new->exp);
		printf("Enter coefficient \n");
		scanf("%d", &new->coeff);
		new->next = h[x]->next;
		h[x]->next = new;
	}
	ptr p;
	p = h[x]->next;
	while ((p->next) != '\0')
	{
		p = p->next;
	}
	p->next = h[x]->next;
	printf("\n\n");
}

void findhigh()
{
	ptr p;
	ptr q;
	p = h[0]->next;
	q = h[1]->next;
	high[0] = -1;
	high[1] = -1;
	while ((p->next) != (h[0]->next))
	{
		if (((p->exp) > high[0])&&((p->exp)<past))
		{
			high[0] = p->exp;
			temp[0] = p;
			p = p->next;
		}
		else
		{
			p = p->next;
		}
	}
	if (((p->exp) > high[0])&&((p->exp)<past))
	{
		temp[0] = p;
		high[0] = p->exp;
	}
	while ((q->next) != (h[1]->next))
	{
		if (((q->exp) > high[1])&&((q->exp)<past))
		{
			high[1] = q->exp;
			temp[1] = q;
			q = q->next;
		}
		else
		{
			q = q->next;
		}
	}
	if (((q->exp) > (high[1]))&&((q->exp)<past))
	{
		temp[1] = q;
		high[1] = q->exp;
	}
	if ((high[1] != -1)&&(past!=100))
	{
		printf("+");
	}
	if (high[0] > high[1])
	{
		past = high[0];
		count++;
		printf("%dX^%d",temp[0]->coeff,past);
	}
	else if(high[0]<high[1])
	{
		past = high[1];
		count++;
		printf("%dX^%d",temp[1]->coeff,past);
	}
	else
	{
		if (high[1] == -1)
		{
			return;
		}
		past = high[1];
		count++;
		printf("%dX^%d",temp[0]->coeff+temp[1]->coeff,past);
	}
}

void display(int x)
{
	ptr p;
	p = h[x]->next;
	while ((p->next) != (h[x]->next))
	{
		printf("%dX^%d", p->coeff, p->exp);
		printf("+");
		p = p->next;
	}
	printf("%dX^%d", p->coeff, p->exp);
	printf("\n");
}

void main()
{
	high[0] = -1;
	high[1] = -1;
	count = 0;
	int i=0;
	past = 100;
	createhead();
	printf("Enter first polynomial \n");
	insert(0);
	printf("Enter second polynomial \n");
	insert(1);
	display(0);
	display(1);
	z = a[0] + a[1];
	i = 0;
	while(i<z)
	{
		findhigh();
		i++;
	}
	getch();
}