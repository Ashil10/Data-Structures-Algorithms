Experiment no.9
Stack and Queue using Linked List
07-11-2022

Write a C Program to implement stack and queue using linked list

PROGRAM

#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

typedef struct NODE node;

node *top=NULL;

void displaystack()
{
	if(top==NULL)
		printf("\nStack Empty!!");
	else
	{
		node *temp=top;
		printf("\nStack:  ");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

void addstack()
{
	printf("\nEnter element to insert: ");
	int item;
	scanf("%d",&item);
	
	node*c;
	c=(node*)malloc(sizeof(node));
	c->data=item;
	if(top==NULL)
	{
		top=c;
		c->next=NULL;
	}
	else
	{
		c->next=top;
		top=c;
	}
	displaystack();
}

void deletestack()
{
	if(top==NULL)
		printf("\nStack Empty!!");
	else
	{
		node *c;
		c=top;
		printf("\nDeleted element: %d",c->data);
		top=top->next;
		free(c);
		displaystack();
	}
}

node *front=NULL, *rear=NULL;

void displayqueue()
{
	if(front==NULL)
		printf("\nQueue Empty!!");
	else
	{
		node *temp;
		temp=front;
		printf("\nQueue: ");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

void addqueue()
{
	printf("\nEnter element to insert: ");
	int item;
	scanf("%d",&item);
	
	node *c;
	c=(node*)malloc(sizeof(node));
	c->data=item;
	c->next=NULL;
	if(front==NULL)
	{
		front=c;
		rear=c;
	}
	else
	{
	rear->next=c;
	rear=c;
	}
	displayqueue();
}
void deletequeue()
{
	if(front==NULL)
		printf("\nQueue Empty!!");
	else
	{
		node *c;
		c=front;
		printf("\nDeleted element: %d",front->data);
		front=front->next;
		free(c);
		displayqueue();
	}
}

int main()
{
	while(1)
	{
	printf("======================");
	printf("\n1. STACK");
	printf("\n2. QUEUE");
	printf("\n3. exit");
	printf("\nEnter Choice: ");
	int x;
	scanf("%d",&x);
	if(x==1)
	{
		printf("\n\nSTACK");
		while(1)
		{
		printf("\n--------------------");
		printf("\n1.Add element");
		printf("\n2.Delete element");
		printf("\n3.Display Stack");
		printf("\n4.Close Stack");
		printf("\nEnter Choice: ");
		int op;
		scanf("%d",&op);
		if(op==1)
			addstack();
		else if(op==2)
			deletestack();
		else if(op==3)
			displaystack();
		else if(op==4)
		{
			printf("\nSTACK CLOSED");
			break;
		}
		else
			printf("\nInvalid Entry");
		}
	}
	else if(x==2)
	{
		printf("\n\nQUEUE");
		while(1)
		{
		printf("\n--------------------");
		printf("\n1.Add element");
		printf("\n2.Delete element");
		printf("\n3.Display Queue");
		printf("\n4.Close Queue");
		printf("\nEnter Choice: ");
		int op;
		scanf("%d",&op);
		if(op==1)
			addqueue();
		else if(op==2)
			deletequeue();
		else if(op==3)
			displayqueue();
		else if(op==4)
		{
			printf("\nSTACK CLOSED");
			break;
		}
		else
			printf("\nInvalid Entry");
		}
	}
	else if(x==3)
		exit(0);
	else
		printf("\nInvalid Entry");
	printf("\n\n");
	}
}


OUTPUT

======================
1. STACK
2. QUEUE
3. exit
Enter Choice: 1


STACK
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 1

Enter element to insert: 1

Stack:  1
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 1

Enter element to insert: 2

Stack:  2 1
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 1

Enter element to insert: 3

Stack:  3 2 1
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 1

Enter element to insert: 4

Stack:  4 3 2 1
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 1

Enter element to insert: 5

Stack:  5 4 3 2 1
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 2

Deleted element: 5
Stack:  4 3 2 1
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 2

Deleted element: 4
Stack:  3 2 1
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 2

Deleted element: 3
Stack:  2 1
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 2

Deleted element: 2
Stack:  1
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 2

Deleted element: 1
Stack Empty!!
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 2

Stack Empty!!
--------------------
1.Add element
2.Delete element
3.Display Stack
4.Close Stack
Enter Choice: 4

STACK CLOSED

======================
1. STACK
2. QUEUE
3. exit
Enter Choice: 2


QUEUE
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 1

Enter element to insert: 1

Queue: 1
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 1

Enter element to insert: 2

Queue: 1 2
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 1

Enter element to insert: 3

Queue: 1 2 3
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 1

Enter element to insert: 4

Queue: 1 2 3 4
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 1

Enter element to insert: 5

Queue: 1 2 3 4 5
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 2

Deleted element: 1
Queue: 2 3 4 5
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 2

Deleted element: 2
Queue: 3 4 5
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 2

Deleted element: 3
Queue: 4 5
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 2

Deleted element: 4
Queue: 5
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 2

Deleted element: 5
Queue Empty!!
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 2

Queue Empty!!
--------------------
1.Add element
2.Delete element
3.Display Queue
4.Close Queue
Enter Choice: 4

STACK CLOSED

======================
1. STACK
2. QUEUE
3. exit
Enter Choice: 3
