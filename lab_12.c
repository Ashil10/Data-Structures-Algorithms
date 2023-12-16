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
