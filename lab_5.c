Experiment no.5
Stack
31-10-2022

Write a C program to implement a Stack using arrays with the operations
	i) Insertion of element at top of stack
	ii) Deletion of element at top of stack
	iii) Display the elements of stack

PROGRAM

#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top=-1,n;

void display()
{
	if(top==-1)
		printf("\nStack Empty!!");
	else
	{
		printf("\nStack:  ");
		for(int i=0;i<=top;i++)
			printf("%d ",stack[i]);
	}
}

void add()
{
	int item;
	printf("Enter element: ");
	scanf("%d",&item);
	
	if(top==n-1)
	{
		printf("\nStack Full!!");	
		display();
	}	
	else
	{
		top++;
		stack[top]=item;
		display();
	}
}

void delete()
{
	if(top==-1)
		printf("\nStack Empty!!");
	else
	{
		printf("\nDeleted element: %d",stack[top]);
		top--;
		display();
	}
}

int main()
{
	printf("Enter size of stack: ");
	scanf("%d",&n);
	while(1)
	{
		printf("\n\n*************************");
		printf("\n1. Add element");
		printf("\n2. Delete element");
		printf("\n3. Display ");
		printf("\n4. exit");
		printf("\nEnter your choice: ");
		int op;
		scanf("%d",&op);
		
		if(op==1)
			add();
		else if(op==2)
			delete();
		else if(op==3)
			display();
		else if(op==4)
			exit(0);
		else
			printf("\nInvalid Entry");
	}
}

OUTPUT	

Enter size of stack: 4
*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 10

Stack:  10

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 3

Stack:  10 3

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 2

Stack:  10 3 2

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 8

Stack:  10 3 2 8

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 7

Stack Full!!
Stack:  10 3 2 8

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element: 8
Stack:  10 3 2

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element: 2
Stack:  10 3

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element: 3
Stack:  10

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element: 10
Stack Empty!!

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Stack Empty!!

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 4	
		
