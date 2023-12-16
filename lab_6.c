Experiment no.6
Stack
31-10-2022


Write a C program to implement a Priority Queue using arrays with the operations
	i) Insertion of element at rear of priority queue
	ii) Deletion of element at front of priority queue
	iii) Display the elements of priority queue

PROGRAM

#include <stdio.h>
#include<stdlib.h>

struct pqueue
{
	int data;
	int prio;
}queue[100], temp;

int front=-1, rear=-1, n;

void display()
{
	if(rear==-1)
		printf("\nQueue Empty!!");
	else
	{	
	printf("\nQueue:  ");
	for(int i=front;i<=rear;i++)
		printf("%d ",queue[i].data);
	}
}

void addq()
{
	int dat, pri;
	printf("Enter element: ");
	scanf("%d",&dat);
	printf("Enter priority: ");
	scanf("%d",&pri);
	if(rear==-1)
	{
		front=0;
		rear=0;
		queue[rear].data=dat;
		queue[rear].prio=pri;
		display();
	}
	else if(rear==n-1)
	{
		printf("\nQueue Full!!");
		display();
	}
	else
	{
		rear++;
		queue[rear].data=dat;
		queue[rear].prio=pri;
		for(int i=front;i<=rear;i++)
			for(int j=front;j<rear;j++)
				if(queue[j].prio<queue[j+1].prio)
				{
					temp=queue[j];
					queue[j]=queue[j+1];
					queue[j+1]=temp;
				}					
		display();
	}
}

void deleteq()
{
	if(rear==-1)
		printf("\nQueue Empty!!");
	else if(front==rear)
	{
		printf("\nDeleted element is: %d",queue[front].data);
		front=-1; rear=-1;
		printf("\nQueue Empty!!");
	}
	else
	{
		printf("\nDeleted element is: %d",queue[front].data);
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
Enter element: 9
Enter priority: 3

Queue:  9

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 2
Enter priority: 4

Queue:  2 9

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 0
Enter priority: 5

Queue:  0 2 9

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 7
Enter priority: 2

Queue:  0 2 9 7

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 1
Enter element: 8
Enter priority: 1

Queue:  0 2 9 7 8

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 3

Queue:  0 2 9 7 8

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element is: 0
Queue:  2 9 7 8

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 3

Queue:  2 9 7 8

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element is: 2
Queue:  9 7 8

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 3

Queue:  9 7 8

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element is: 9
Queue:  7 8

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2

Deleted element is: 7
Queue:  8

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 2
Deleted element is: 8
Queue Empty!!

*************************
1. Add element
2. Delete element
3. Display
4. exit
Enter your choice: 4
