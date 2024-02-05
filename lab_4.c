Experiment no.4
Queue
31-10-2022

Write a C program to implement a queue using arrays with the operations
	i) Insertion of element at rear of queue
	ii) Deletion of element at front of queue
	iii) Display the elements of queue

PROGRAM

#include <stdio.h>
#include<stdlib.h>

int queue[100];
int front=-1,rear=-1,n;

void display()
{
	if(rear==-1)
		printf("\nQueue Empty!!");
	else
	{	
	printf("\nQueue:  ");
	for(int i=front;i<=rear;i++)
		printf("%d ",queue[i]);
	}
}

void addq()
{
	printf("Enter element: ");
	int item;
	scanf("%d",&item);
	if(rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=item;
		display();
	}
	else if(rear==n-1)
		printf("\nQueue Full!!");
	else
	{
		rear++;
		queue[rear]=item;
		display();
	}
}

void deleteq()
{
	if(rear==-1)
		printf("\nQueue Empty!!");
	else if(front==rear)
	{
		printf("\nDeleted element is: %d",queue[front]);
		front=-1; rear=-1;
		printf("\nQueue empty!!");
	}
	else
	{
		printf("\nDeleted element is: %d",queue[front]);
		front++;
		display();
	}
}

int main()
{
	printf("Enter size of queue: ");
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
			addq();
		else if(op==2)
			deleteq();
		else if(op==3)
			display();
		else if(op==4)
			exit(0);
		else
			printf("\nInvalid Entry");
	}
}


OUTPUT

Enter size of queue: 5
*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 1

Queue:  1

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 2

Queue:  1 2

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 3

Queue:  1 2 3

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 4

Queue:  1 2 3 4

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 5

Queue:  1 2 3 4 5

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 6

Queue Full!!

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element is: 1
Queue:  2 3 4 5

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element is: 2
Queue:  3 4 5

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element is: 3
Queue:  4 5

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element is: 4
Queue:  5

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element is: 5
Queue empty!!

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Queue Empty!!

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 3

Queue Empty!!

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 4
