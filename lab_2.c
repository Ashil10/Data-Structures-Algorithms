Experiment no.2
Sparse Matrix
17-10-2022

Write a C program to enter two matrices in normal form. Write a function to convert two matrices to tuple and display it. Also find the tranpose of the two matrices represented in tuple form and display it. Find the sum of two matrices and display in tuple form.

#include<stdio.h>
#include<stdlib.h>

void totuple(int t[][3],int a,int b,int A[a][b])
{
	int x=0, n=1;
	t[0][0]=a;
	t[0][1]=b;
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			if(A[i][j]!=0)
			{
				t[n][0]=i;
				t[n][1]=j;
				t[n][2]=A[i][j];
				x++; n++;
			}
	t[0][2]=x;
}

void matrixadd(int t1[][3], int t2[][3], int s[][3])
{
	int p=1,q=1;
	int free=1;
	if((t1[0][0]!=t2[0][0])||(t1[0][1]!=t2[0][1]))
		printf("Matrices are not Compatible\n");
	else
	{
		s[0][0]=t1[0][0];
		s[0][1]=t1[0][1];
		while((p<=t1[0][2])&&(q<=t2[0][2]))
		{
			int x1=t1[p][0];
			int x2=t1[p][1];
			int y1=t2[q][0];
			int y2=t2[q][1];
			
			if((x1==y1)&&(x2==y2))
			{
				int sum=t1[p][2]+t2[q][2];
				if(sum!=0)
				{
					s[free][0]=t1[p][0];
					s[free][1]=t1[p][1];
					s[free][2]=sum;
					free++;
				}
				p++; q++;
			}
			else if((x1<y1)||((x1==y1)&&(x2<y2)))
			{
				s[free][0]=t1[p][0];
				s[free][1]=t1[p][1];
				s[free][2]=t1[p][2];
				free++; p++;
			}
			else if((x1>y1)||((x1==y1)&&(x2>y2)))
			{
				s[free][0]=t2[q][0];
				s[free][1]=t2[q][1];
				s[free][2]=t2[q][2];
				free++; q++;
			}
		}
		while(p<=t1[0][2])
		{
			s[free][0]=t1[p][0];
			s[free][1]=t1[p][1];
			s[free][2]=t1[p][2];
			free++; p++;
		}
		while(q<=t2[0][2])
		{	
			s[free][0]=t2[q][0];
			s[free][1]=t2[q][1];
			s[free][2]=t2[q][2];
			free++; q++;
		}
		
		s[0][2]=free-1;
	}
}

void transpose(int t[][3], int tr[][3])
{
	int n=1;
	tr[0][1]=t[0][0];
	tr[0][0]=t[0][1];
	tr[0][2]=t[0][2];
	for(int i=0;i<t[0][1];i++)
		for(int j=0;j<=t[0][2];j++)
			if(t[j][1]==i)
			{
				tr[n][0]=t[j][1];
				tr[n][1]=t[j][0];
				tr[n][2]=t[j][2];
				n++;
			}
}

void tomatrix(int tr[][3], int B[][100])
{
	int a=tr[0][0];
	int b=tr[0][1];
	int x=1;
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			if((i==tr[x][0])&&(j==tr[x][1]))
			{
				B[i][j]=tr[x][2];
				x++;
			}
			else
				B[i][j]=0;
}

void insert(int m, int n, int A[m][n])
{
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&A[i][j]);
}
void display(int m, int n, int A[m][n])
{
	for(int i=0;i<m;i++)
	{
		printf("\n");
		for(int j=0;j<n;j++)
			printf("   %d   ",A[i][j]);
	}
}

int main()
{
	int m1, n1, m2, n2;
	printf("Enter the order of first matrix: ");
	scanf("%d%d",&m1,&n1);
	printf("Enter the order of second matrix: ");
	scanf("%d%d",&m2,&n2);
	
	int A[m1][n1], B[m2][n2];
	printf("Enter the elements of first matrix in order: \n");
	insert(m1,n1,A);
	printf("Enter the elements of second matrix in order: \n");
	insert(m2,n2,B);
	
	printf("\nFirst Matrix: ");
	display(m1,n1,A);
	printf("\nSecond Matrix: ");
	display(m2,n2,B);
	
	int T1[100][3],T2[100][3],tr1[100][3], tr2[100][3],Atr[100][100], Btr[100][100];
	
	while(1)
	{
		printf("\n\n*********************************************");
		printf("\nMenu-");	
		printf("\n   1. Display 2 matrices in tuple form");
		printf("\n   2. Add 2 matrices and display in tuple form");
		printf("\n   3. Display transpose of 2 matrices in tuple form");
		printf("\n   4. Display transpose of 2 matrices in normal form");
		printf("\n   5. Exit");
		
		int p;
		printf("\nEnter your choice: ");
		scanf("%d",&p);
		
		if(p==1)
		{
			totuple(T1,m1,n2,A);
			printf("\nFirst matrix in tuple form: ");
			display(T1[0][2]+1,3,T1);
			totuple(T2,m2,n2,B);
			printf("\nSecond matrix in tuple form: ");
			display(T2[0][2]+1,3,T2);
		}
		else if(p==2)
		{
			int s[100][3];
			matrixadd(T1,T2,s);
			printf("\nSum of 2 matricews in tuple form: ");
			display(s[0][2]+1,3,s);
		}
		else if(p==3)
		{
			transpose(T1,tr1);
			printf("\nTranspose of first matrix in tuple form: ");
			display(tr1[0][2]+1,3,tr1);
			transpose(T2,tr2);
			printf("\nTranspose of second matrix in tuple form: ");
			display(tr2[0][2]+1,3,tr2);
		}
		else if(p==4)
		{
			tomatrix(tr1,Atr);
			printf("\nTranpose of first matrix in normal form: ");
			for(int i=0;i<n1;i++)
			{
				printf("\n");
				for(int j=0;j<m1;j++)
					printf("   %d   ",Atr[i][j]);
			}
			tomatrix(tr2,Btr);
			printf("\nTranpose of second matrix in normal form: ");
			for(int i=0;i<n2;i++)
			{
				printf("\n");
				for(int j=0;j<m2;j++)
					printf("   %d   ",Btr[i][j]);
			}
		}	
		else if(p==5)
			exit(0);
		else
			printf("\nInvalid Input");
	}
}
OUTPUT

Enter the order of first matrix: 4 5
Enter the order of second matrix: 4 5
Enter the elements of first matrix in order:
0 5 0 0 9 0 0 0 0 2 0 0 8 0 0 7 0 0 21 0
Enter the elements of second matrix in order:
0 0 4 0 -9 10 0 0 0 0 0 0 3 0 0 -2 0 0 0 6

First Matrix:
   0      5      0      0      9   
   0      0      0      0      2   
   0      0      8      0      0   
   7      0      0      21      0   
Second Matrix:
   0      0      4      0      -9   
   10      0      0      0      0   
   0      0      3      0      0   
   -2      0      0      0      6   

*********************************************
Menu-
   1. Display 2 matrices in tuple form
   2. Add 2 matrices and display in tuple form
   3. Display transpose of 2 matrices in tuple form
   4. Display transpose of 2 matrices in normal form
   5. Exit
Enter your choice: 1

First matrix in tuple form:
   4      5      6   
   0      1      5   
   0      4      9   
   1      4      2   
   2      2      8   
   3      0      7   
   3      3      21   
Second matrix in tuple form:
   4      5      6   
   0      2      4   
   0      4      -9   
   1      0      10   
   2      2      3   
   3      0      -2   
   3      4      6   

*********************************************
Menu-
   1. Display 2 matrices in tuple form
   2. Add 2 matrices and display in tuple form
   3. Display transpose of 2 matrices in tuple form
   4. Display transpose of 2 matrices in normal form
   5. Exit
Enter your choice: 2

Sum of 2 matricews in tuple form:
   4      5      8   
   0      1      5   
   0      2      4   
   1      0      10   
   1      4      2   
   2      2      11   
   3      0      5   
   3      3      21   
   3      4      6   

*********************************************
Menu-
   1. Display 2 matrices in tuple form
   2. Add 2 matrices and display in tuple form
   3. Display transpose of 2 matrices in tuple form
   4. Display transpose of 2 matrices in normal form
   5. Exit
Enter your choice: 3

Transpose of first matrix in tuple form:
   5      4      6   
   0      3      7   
   1      0      5   
   2      2      8   
   3      3      21   
   4      0      9   
   4      1      2   
Transpose of second matrix in tuple form:
   5      4      6   
   0      1      10   
   0      3      -2   
   2      0      4   
   2      2      3   
   4      0      -9   
   4      3      6   

*********************************************
Menu-
   1. Display 2 matrices in tuple form
   2. Add 2 matrices and display in tuple form
   3. Display transpose of 2 matrices in tuple form
   4. Display transpose of 2 matrices in normal form
   5. Exit
Enter your choice: 5
