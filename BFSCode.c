#include<stdio.h>
#include<stdlib.h>

int A[4][4],Q[4],Visited[4], n, i, j ,f=0, r=-1;

void BFS(int v){
  for(i=0;i<n;i++)
  {
    if(A[v][i] && !Visited[i])     //condition of edges b\w nodes and not visited
    {
        Q[++r]=i;                 //Enqueue given nodes  by increment the value of r
    }
  }

  if(f<=r)
  {
    Visited[Q[f]]=1;    // mark as visited
    BFS(Q[f++]);       //Enqueue Adjcent nodes
  }

} 

int main(){
    int v;
    
    printf("\n Enter the number of vertices  ");
    scanf("%d",&n);

    printf("\n Enter the number of adjacency matrix : ");    // input 
    for(i=0;i<n;i++) 
    {
       for(j=0;j<n;j++)
       {
         scanf("%d",&A[i][j]);
       }
    }

    printf("\n enter the value of starting vertex :");
    scanf("%d",&v);
  

  //Intilization of queue
    for(i-0;i<n;i++)     
   {
     Q[i]=0;
     Visited[i]=0;
   }

   BFS(v);  // function call

   printf("\n Recahable nodes are  :");
   for(i=0;i<n;i++)        // printing the vistied nodes
   {
    if(Visited[i])
    {
        printf("\n %d",i);
    }
   }
}