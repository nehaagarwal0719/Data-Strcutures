#include <stdio.h>  
#include <stdbool.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
int source,V,E,time,visited[20],q[20],visited1[20],final[20],G[20][20],i,c=0 ,v1, v2,j,f=0,r=-1;

void dfs(int i)
{
     final[c++]=i;
    int j;
    visited[i]=1;
    printf(" %d->",i);
    for(j=0;j<V;j++)
    {
        if(G[i][j]==1 && visited[j]==0)
            {dfs(j);
        
    }}
}

void bfs(int v) {

printf(" %d->",v);

 for(i = 0; i < V; i++){
     if(G[v][i] && !visited1[i])
     q[++r] = i;
}
 if(f < r) {
     visited1[q[f]] = 1;
     bfs(q[f++]);
 }
}

void cycle(int i)
{
    int j;
    visited1[i]=1;
    for(j=0;j<V;j++)
    {
        //printf("hi\n");
        if(G[i][j]==1 && visited1[j]==1){
         //    printf("hello\n");
            //printf("\ncycle present between %d and %d\n",i,j );
            printf("\ncycle present");
            break;
        }
        if(G[i][j]==1 && visited1[j]==0){
                cycle(j);//printf("going\n");
    }
    }
}

void graph_insert(){

    printf("Enter the no of edges:");
    scanf("%d",&E);
    printf("Enter the no of vertices:");
    scanf("%d",&V);

     for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            G[i][j]=0;
    }

    for(i=0;i<E;i++)
    {
        printf("Enter the edges (format: V1 V2) : ");
        scanf("%d%d",&v1,&v2);
        G[v1][v2]=1;

    }

    printf("The adjacency matrix formed is : \n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            printf(" %d ",G[i][j]);
        printf("\n");
    }

    printf("Enter the source: ");
    scanf("%d",&source);
}
void graph(char str[]){

  //va_list valist;

  char ins[] = "INS";
  char bfst[] = "BFS";
  char dfst[] ="DFS";
  char cy[]="CYCLE";
  //Insertion

  if(strcmp(str,ins) == 0)
     graph_insert();

   if(strcmp(str,bfst) == 0){
     printf("BFS Order :");
     bfs(source);
   }

   if(strcmp(str,dfst) == 0){
     printf("\nDFS Order :");
     dfs(source);
   }


   if(strcmp(str,cy) == 0)
     cycle(source);
 }  

/*int main()
{

    //graph();
   // DFS(source);
    //cycle(source);
    //bfs(source);
    //for(i=0;i<c;i++){
      //  printf("%d\n", final[i]);
    //}
     graph("INS");
     graph("BFS");
     graph("CYCLE");
     graph("DFS");
     graph("CYCLE");
    return 0;
}*/