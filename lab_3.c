Experiment no.3
Circular Queue
21-10-2022

Write a program to implement a circular queue using arrays with the operations
i) Insertion of elements at rear of queue
ii) Deletion of elements from front of queue
iii) Display contents of queue

PROGRAM

#include <stdio.h>
#include <stdlib.h>

int size, cq[100], front=-1, rear=-1;

void printqueue()
{
	//printf("\nFront=%d Rear=%d", front, rear);
	if(front!=-1)
	{
	printf("\nQueue:  ");
	if(rear<front)
	{
	for(int	i=front;i<size;i++)
		printf("%d ",cq[i]);
	for(int i=0;i<=rear;i++)
		printf("%d ",cq[i]);
	}
	else
		for(int	i=front;i<=rear;i++)
			printf("%d ",cq[i]);
	}
		
}
void addcq()
{
	int item;
	printf("Enter element to insert: ");
	scanf("%d",&item);
	if((rear==size-1&&front==0)||(rear==front-1))
	{
		printf("\nQueue is Full!!");
		return;
	}
	if(front==-1)
		front=0;
		
	rear=(rear+1)%size;
	cq[rear]=item;
	printqueue();
}

void deletecq()
{
	if(front==-1)
		printf("\nQueue is Empty!!");
	else
	{
		int item=cq[front];
		printf("\nDeleted element is: %d",item);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front=(front+1)%size;
		printqueue();
	}
}
		
int main()
{
	printf("Enter the size of circular queue: ");
	scanf("%d",&size);
	while(1)
	{
		int op;
		printf("\n\n================================\n1. Insert an element\n2. Delete an element\n3. Display queue\n4. exit");
		printf("\nEnter your choiche: ");
		scanf("%d",&op);
		if(op==1)
		{
			
			addcq();
		}
		if(op==2)
			deletecq();
		if(op==3)
			printqueue();
		if(op==4)
			exit(0);
	}
}


OUTPUT

Enter the size of circular queue: 5
================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 1
Enter element to insert: 10

Queue:  10

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 1
Enter element to insert: 8

Queue:  10 8

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 1
Enter element to insert: 9
Queue:  10 8 9

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 3
Queue:  10 8 9

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 2
Deleted element is: 10
Queue:  8 9

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 1
Enter element to insert: 7
Queue:  8 9 7

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 1
Enter element to insert: 6
Queue:  8 9 7 6

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 1
Enter element to insert: 5
Queue:  8 9 7 6 5

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 1
Enter element to insert: 0

Queue is Full!!

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 3

Queue:  8 9 7 6 5

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 2
Deleted element is: 8
Queue:  9 7 6 5

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 2
Deleted element is: 9
Queue:  7 6 5

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 2
Deleted element is: 7
Queue:  6 5

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 2
Deleted element is: 6
Queue:  5

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 2

Deleted element is: 5

================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 2

Queue is Empty!!
================================
1. Insert an element
2. Delete an element
3. Display queue
4. exit
Enter your choiche: 4
