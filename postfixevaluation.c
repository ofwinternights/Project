#include<stdio.h>
#include<conio.h>
struct stack
{
	float data[10];
	int top;
}s;

void push(float x)
{
	s.data[++s.top]=x;
}

int pop()
{
	return(s.data[s.top--]);
}

float fix(char symbol, float op1, float op2)
{
	switch(symbol)
	{
	case '+':return(op1 + op2);
	case '-':return(op1 - op2);
	case '/':return(op1 / op2);
	case '*':return(op1 * op2);
	}
	return 0;
}

void main()
{
	s.top = -1;
	char postfix[10],symbol;
	int len, i = 0;
	float op2, op1, r;
	printf("Enter postfix expression\n");
	scanf("%s",postfix);
	len = strlen(postfix);
	for (i = 0; postfix[i] != '\0'; i++)
	{
		symbol = postfix[i];
		if((symbol=='-')||(symbol == '+')||(symbol == '*')||(symbol == '/'))
		{
			op2 = pop();
			op1 = pop();
			r = fix(symbol, op1, op2);
		}
		else
		{
			push(r);
			push(symbol-'0');
		}
	}
	r = pop();
	printf("answer is%f\t", r);
	getch();
}