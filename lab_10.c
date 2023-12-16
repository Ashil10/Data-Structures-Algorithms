Experiment no.10
Polynomial Multiplication using linked list
07-11-2022


Write a C program to insert two polynomials using linked list. Find the product of two polynomials using linkedl ist and display the product.

PROGRAM

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct polytype
{
	int coef;
	int exp;
	struct polytype *next;
};
typedef struct polytype poly;

poly *maketerm(int co,int ex)
{
	poly *term;
	term=(poly*)malloc(sizeof(poly));
	term->coef=co;
	term->exp=ex;
	term->next=NULL;
	return term;
}

poly *insertterm(int co, int ex, poly *tail)
{
	poly *temp;
	temp=maketerm(co,ex);
	temp->next=tail->next;
	tail->next=temp;
	return temp;
}

poly *polyprod(poly *a, poly *b)
{
	poly *result, *tail, *ap, *bp;
	int texp, tcoef;
	result=tail=maketerm(0,INT_MAX);
	for(ap=a;ap!=NULL;ap=ap->next)
		for(bp=b;bp!=NULL;bp=bp->next)
		{
			tcoef=ap->coef*bp->coef;
			texp=ap->exp+bp->exp;
			
			tail=result;
			while(tail->next!=NULL&&tail->exp>texp)
			{
				if((tail->next)->exp>=texp)
					tail=tail->next;
				else
					break;
			}
			
			if(tail->exp==texp)
				tail->coef+=tcoef;
			else
				tail=insertterm(tcoef,texp,tail);
			
		}
	tail=result;
	result=result->next;
	free(tail);
	return result;
}

poly *readpoly(int m)
{
	poly *x, *a;
	x=a=maketerm(0,INT_MAX);
	
	for(int i=0;i<m;i++)
	{
		int co, ex;
		scanf("%d%d",&co,&ex);
		
		x=insertterm(co,ex,x);	
	}
	x=a;
	a=a->next;
	free(x);
	return a;
}
void display(poly *a)
{
	poly *x=a;
	printf("\n");
	while(x!=NULL)
	{
		if(x->coef!=0)
		{
		printf("(%dx^%d)",x->coef,x->exp);
		if(x->next!=NULL)
			printf(" + ");
		}
		x=x->next;
	}
}
void sort(poly *a,int m)
{
	for(int i=0;i<m;i++)
	{
		poly *x=a;
		while((x->next)!=NULL)
		{
			if(x->exp<(x->next)->exp)
			{
				int temp=x->exp;
				x->exp=(x->next)->exp;
				(x->next)->exp=temp;
				
				temp=x->coef;
				x->coef=(x->next)->coef;
				(x->next)->coef=temp;
			}
			x=x->next;
		}
	}
}			
int main()
{
	int m, n;
	
	printf("Enter numbers of term of first polynomial: ");
	scanf("%d",&m);
	printf("Enter coefficients and exponents in order:\n");
	poly *a=readpoly(m);
	
	printf("Enter numbers of term of second polynomial: ");
	scanf("%d",&n);
	printf("Enter coefficients and exponents in order:\n");
	poly *b=readpoly(n);
	
	sort(a,m);
	printf("\nFirst Polynomial: ");
	display(a);
	sort(b,n);
	printf("\nSecond Polynomial: ");
	display(b);
	
	poly *result=polyprod(a,b);
	printf("\n\nProduct of Polynomials: ");
	display(result);
	
	printf("\n\n");
}
OUTPUT

Enter numbers of term of first polynomial: 4
Enter coefficients and exponents in order:
35 4
7 2
4 1
12 0
Enter numbers of term of second polynomial: 5
Enter coefficients and exponents in order:
15 5
-3 3
6 2
9 1
25 0

First Polynomial:
(35x^4) + (7x^2) + (4x^1) + (12x^0)
Second Polynomial:
(15x^5) + (-3x^3) + (6x^2) + (9x^1) + (25x^0)

Product of Polynomials:
(525x^9)  + (270x^6) + (474x^5) + (905x^4) + (51x^3) + (283x^2) + (208x^1) + (300x^0)
