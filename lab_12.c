Experiment no.11
Binary Tree Traversal
16-12-2022

PROGRAM

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
	struct tree *left;
	char data;
	struct tree *right;
	struct tree *next;
};
typedef struct tree node;
node *head=NULL;

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

void topostfix(char A[])
{
	printf("Enter the infix Expression: ");
	scanf("%s",A);
	
	for(int i=0;i<strlen(A);i++)
	{
		if((A[i]>='A'&&A[i]<='Z')||(A[i]>='a'&&A[i]<='z'))
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
	
	//printf("Postfix Expression: %s\n\n",B);
	
}

node *createnode(char data)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->next=NULL;
	return temp;
}

void push1(node *ptr)
{
	if(head==NULL)
		head=ptr;
	else
	{
		ptr->next=head;
		head=ptr;
	}
}

node *pop1()
{
	node *ptr=head;
	if(head!=NULL)
	{
		head=head->next;
		return ptr;
	}
}	

void inorder(node *a)
{
	if(a!=NULL)
	{
		inorder(a->left);
		printf("%c",a->data);
		inorder(a->right);
	}
}

void postorder(node *a)
{
	if(a!=NULL)
	{
		postorder(a->left);
		postorder(a->right);
		printf("%c",a->data);
	}
}

void preorder(node *a)
{
	if(a!=NULL)
	{
		printf("%c",a->data);
		preorder(a->left);
		preorder(a->right);
	}
}

int main()
{
	node *a, *b, *exp;
	char s[100];
	
	char A[100];
	topostfix(A);
	
	for(int i=0;i<strlen(B);i++)
		s[i]=B[i];
	
	
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			exp=createnode(s[i]);
			a=pop1();
			b=pop1();
			exp->left=b;
			exp->right=a;
			push1(exp);
		}
		else
		{
			exp=createnode(s[i]);
			push1(exp);
		}
	}
	
	exp=pop1();
	printf("\nInorder expression: ");
	inorder(exp);
	printf("\nPostorder expression: ");
	postorder(exp);
	printf("\nPreorder expression: ");
	preorder(exp);
	printf("\n");
	
	printf("\n");
}

OUTPUT

Enter the infix Expression: a/b*c+(d-e)

Inorder expression: a/b*c+d-e
Postorder expression: ab/c*de-+
Preorder expression: +*/abc-de


Experiment no.12
Graph
16-12-2022


PROGRAM

#include <stdio.h>

int graph[20][20],visited[20],n;

void dfs(int i)
{   
    int j;
    printf("\n%d",i);
    visited[i]=1;
    for(j=1;j<=n;j++)
    {
       if(!visited[j] && graph[i][j]==1)
         dfs(j);
    }
}

void dfs_main()
{
    for(int i=1;i<=n;i++)
    {
       
      visited[i]=0;
    }
    dfs(1);
}

int queue[20],front=0,rear=-1;

void bfs(int v)
{
    visited[v]=1;
    printf("\n%d",v);
    for(int i=1;i<=n;i++)
    {
      if(graph[v][i] && !visited[i])
      {
        queue[++rear]=i;
        visited[i]=1;
      }
    }
  if(front <=rear)
  {
    bfs(queue[front++]);
  }  

}

void bfs_main()
{
    for(int i=1;i<=n;i++)
    {
     visited[i]=0;
    }

    bfs(1);    
}

void main(){
    int op=0;
    do {
        printf("\n1.Enter graph details:\n2.DFS\n3.BFS\n4.Exit\n \nEnter your choice:");
        scanf("%d",&op);

        switch(op){
            case 1 :
            printf("\n \nEnter the number of vertices:");
            scanf("%d",&n);
            printf("\nEnter the adjacency matrix of the graph:");
            for(int i=1;i<=n;i++)
                for(int j =1;j<=n;j++)
                    scanf("%d",&graph[i][j]);

            break;

            case 2 :
            dfs_main();
            break;

            case 3 :
            bfs_main();
            break;

            case 4 :
            printf("Exited");
            break;

            default:
            printf("Invalid Choice");     
                }
            } while(op!=4);
        }



OUTPUT

1.Enter graph details:
2.DFS
3.BFS
4.Exit
 
Enter your choice:1

 
Enter the number of vertices:0

Enter the adjacency matrix of the graph:
1.Enter graph details:
2.DFS
3.BFS
4.Exit
 
Enter your choice:1

 
Enter the number of vertices:6

Enter the adjacency matrix of the graph:0
1
0
0
0
0
1
0
0
1
1
0
0
0
0
0
0
0
0
1
0
0
0
1
0
1
0
0
0
1
0
0
0
1
1
0

1.Enter graph details:
2.DFS
3.BFS
4.Exit
 
Enter your choice:2

1
2
4
6
5
1.Enter graph details:
2.DFS
3.BFS
4.Exit
 
Enter your choice:3

1
2
4
5
6
1.Enter graph details:
2.DFS
3.BFS
4.Exit
 
Enter your choice:4
