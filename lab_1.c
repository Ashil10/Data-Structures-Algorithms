Experiment no.1
Polynomial Addition
26-09-2022


Write a C program to read two polynomials and store them in an array. Calculate the sum of the polynomials and display the first polynomial, second polynomial and the resultant polynomial

PROGRAM

#include<stdio.h>

struct poly
{
	int e;
	int c;
}A[100];

void sort(int f, int l)
{
	for(int i=f;i<=l-1;i++)
		for(int j=f;j<=l-1;j++)
			if(A[j].e<A[j+1].e)
			{
				int temp=A[j].e;
				A[j].e=A[j+1].e;
				A[j+1].e=temp;
				temp=A[j].c;
				A[j].c=A[j+1].c;
				A[j+1].c=temp;
			}
}

void insert(int f, int l)
{
	for(int i=f;i<=l;i++)
		scanf("%d%d",&A[i].e,&A[i].c);
}

void display(int f, int l)
{
	printf("\n");
	for(int i=f;i<=l;i++)
	{
		printf(" %d",A[i].c);
		if(A[i].e!=0)
			printf("x^%d ",A[i].e);
		if(i!=l)
			printf("+");
	}
}

int newterm(int x, int y, int free)
{
	A[free].e=x;
	A[free].c=y;
}
				
int polyadd(int af,int al, int bf, int bl)
{
	int p=af, q=bf, sum;
	int free=bl+1;
	while((p<=al)&&(q<=bl))
	{
		if(A[p].e==A[q].e)
		{
			sum=A[p].c+A[q].c;
			if(sum!=0)
			{
				newterm(A[p].e, sum, free);
				free++;
			}
			p++; q++;
		}
		else if(A[p].e<A[q].e)
		{
			newterm(A[q].e,A[q].c,free);
			q++; free++;
		}
		else if(A[p].e>A[q].e)
		{
			newterm(A[p].e,A[p].c,free);
			p++; free++;
		}
	}
	while(p<=al)
	{
		newterm(A[p].e,A[p].c,free);
		p++; free++;
	}
	while(q<=bl)
	{
		newterm(A[q].e,A[q].c,free);
		q++; free++;
	}
	return free;
}

	
int main()
{
	int m, n, i, af, al, bf, bl, cf, cl;
	printf("Enter the number of elements of first polynomial: ");
	scanf("%d",&m);
	af=0; al=m-1;
	printf("Enter the exponents and coefficients of first polynomial in order: \n");
	insert(af,al);
	
	printf("Enter the number of elements of second polynomial: ");
	scanf("%d",&n);
	bf=m; bl=al+n;
	printf("Enter the exponents and coefficients of second polynomial in order: \n");
	insert(bf,bl);
	
	sort(af,al);
	sort(bf,bl);	
	
	printf("The two polynomials are-");
	display(af,al);
	display(bf,bl);
	
	cl=polyadd(af, al, bf, bl);
	cf=bl+1;
	
	printf("\n\nSum of the two polynomials is:\n");
	display(cf,cl-1);	
	
	printf("\n\n");

}
	
	
	
	
OUTPUT

Enter the number of elements of first polynomial: 6
Enter the exponents and coefficients of first polynomial in order:
0 7
1 10
3 9
4 6
6 3
7 5
Enter the number of elements of second polynomial: 7
Enter the exponents and coefficients of second polynomial in order:
0 4
1 -10
3 8
4 4
5 12
7 -5
25 14
The two polynomials are-
 5x^7 + 3x^6 + 6x^4 + 9x^3 + 10x^1 + 7
 14x^25 + -5x^7 + 12x^5 + 4x^4 + 8x^3 + -10x^1 + 4

Sum of the two polynomials is:
14x^25 + 3x^6 + 12x^5 + 10x^4 + 17x^3 + 11
