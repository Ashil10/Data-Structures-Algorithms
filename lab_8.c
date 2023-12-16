Experiment no.8
Binary Search
04-11-2022


Write a C program to search for elements using Linear Search and Binary Search

PROGRAM

#include <stdio.h>
#include <stdlib.h>

void sort(int n, int A[n])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			if(A[j]>A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
}

int BinarySearch(int A[],int beg, int end, int val)
{
	int mid;
	if(end>=beg)
	{
		mid=(beg+end)/2;
		
		if(A[mid]==val)
			return mid;
		else if(A[mid]<val)
			return BinarySearch(A,mid+1,end,val);
		else
			return BinarySearch(A,beg,mid-1,val);
	}
	return -1;
}

int LinearSearch(int n, int A[n], int val)
{
	for(int i=0;i<n;i++)
		if(A[i]==val)
			return i;
	
	return -1;
}

int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int A[n], B[n];
	printf("Enter the elements in order: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		B[i]=A[i];
	}
	while(1)
	{
		printf("\n\n===========================");
		printf("\n1. Linear Search");
		printf("\n2. Binary Search");
		printf("\n3. exit");
		printf("\nEnter your choice: ");
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int val;
			printf("Enter element to search: ");
			scanf("%d",&val);
			
			int linear_pos;
			linear_pos=LinearSearch(n,A,val);
		
			printf("\nList: ");
			for(int i=0;i<n;i++)
				printf(" %d ",A[i]);
			
			if(linear_pos==-1)
				printf("\nElement not found");
			else
				printf("\nElement found at position %d",linear_pos+1);
		}
		if(op==2)
		{
			int val;
			printf("Enter element to search: ");
			scanf("%d",&val);
			
			sort(n,B);
			
			int binary_pos;
			binary_pos=BinarySearch(B,0,n-1,val);
	
			printf("\nSorted List: ");
			for(int i=0;i<n;i++)
				printf(" %d ",B[i]);
			if(binary_pos==-1)
				printf("\nElement not found");
			else
				printf("\nElement found at position %d",binary_pos+1);
		}
		if(op==3)
			exit(0);
	}
}

OUTPUT

Enter number of elements: 10
Enter the elements in order: 1 2 3 4 5 6 7 8 9 10

===========================
1. Linear Search
2. Binary Search
3. exit
Enter your choice: 1
Enter element to search: 7

List:  1  2  3  4  5  6  7  8  9  10
Element found at position 7

===========================
1. Linear Search
2. Binary Search
3. exit
Enter your choice: 2
Enter element to search: 11

Sorted List:  1  2  3  4  5  6  7  8  9  10
Element not found

===========================
1. Linear Search
2. Binary Search
3. exit
Enter your choice: 2
Enter element to search: 5

Sorted List:  1  2  3  4  5  6  7  8  9  10
Element found at position 5

===========================
1. Linear Search
2. Binary Search
3. exit
Enter your choice: 3
