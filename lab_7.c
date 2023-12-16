Experiment no.7
Infix Expression
04-11-2022


Write a C program to convert infix expresion to postfix expression

PROGRAM

#include<stdio.h>
#include<string.h>

char stack[100], B[100];
int top=-1, j=0;
int priority(char a)
{
	if(a=='*'||a=='/'||a=='%')
		return 3;
	else if(a=='('||a==')')
		return 5;
	else if(a=='^')
		return 4;
	
	return 2;
}
void pop()
{
	B[j]=stack[top];
	top--; j++;
}
void push(char a)
{
	if(a==')')
	{
		while(stack[top]!='(')
			pop();
			
		top--;
	}
	else
	{
		top++;
		stack[top]=a;
	}
}

int main()
{
	char A[100];
	printf("Enter the infix Expression: ");
	scanf("%s",A);
	
	for(int i=0;i<strlen(A);i++)
	{
		if((A[i]>='A'&&A[i]<='Z')||(A[i]>='a'&&A[i]<='a'))
		{
			B[j]=A[i];
			j++;
		}
		else
		{
			while(priority(A[i])<=priority(stack[top])&&top>-1&&stack[top]!='(')
				pop();
				
			push(A[i]);
		}
	}
	
	while(top>-1)
		pop();
	
	printf("Postfix Expression: %s\n\n",B);
}

OUTPUT

Enter the infix Expression: A/B*C+(D-E)
Postfix Expression: AB/C*DE-+

