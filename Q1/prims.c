#include<stdio.h>
#include<stdlib.h>
 
int a,b,u,v,n,i,j,s=1;
int nodes_visited[10]={0},min,mincost=0,cost[10][10];
void main()
 
{
     printf("\nEnter the number of nodes:");
     scanf("%d",&n);
     printf("\nEnter the adjacency matrix:\n");
     for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     {
         scanf("%d",&cost[i][j]);
         if(cost[i][j]==0)
             cost[i][j]=999;
 
     }
 
     nodes_visited[1]=1;
     printf("\n");
     while(s < n)
     {
         for(i=1,min=999;i<=n;i++)
             for(j=1;j<=n;j++)
                 if(cost[i][j]< min)
                     if(nodes_visited[i]!=0)
                      {
                          min=cost[i][j];
                          a=u=i;
                          b=v=j;
                      }
         if(nodes_visited[u]==0 || nodes_visited[v]==0)
         {
             printf("\n %d edge:(%d %d) = %d",s++,a,b,min);
             mincost+=min;
             nodes_visited[b]=1;
         }
         cost[a][b]=cost[b][a]=999;
     }
     printf("\n Minimun cost=%d\n",mincost);
}
