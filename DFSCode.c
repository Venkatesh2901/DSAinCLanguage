#include<stdio.h>
#include<stdlib.h>
int visited[7] = {0,0,0,0,0,0,0};
int A[7][7];
/* int A [7][7] = {
{0,1,1,1,0,0,0},
{1,0,1,0,0,0,0},
{1,1,0,1,1,0,0},
{1,0,1,0,1,0,0},
{0,0,1,1,0,1,1},
{0,0,0,0,1,0,0}, 
{0,0,0,0,1,0,0} 
}; */

void DFS( int i)
{
 printf("DFS order : %d ", i);
 visited[i] = 1;
 
  for (int j = 0; j < 7; j++)
   {

    if(A[i][j]==1 && !visited[j])
    {
      DFS(j);
    }
  }
}


int main(){ 
 
 int u;
  
 printf("\n Enter the elements in 2-D Array : ");
 for(int i=0;i<7;i++){
    for(int j=0;j<7;j++){
      scanf("%d",&A[i][j]);
  }
 }
 printf("\n Enter the value of starting index : ");
 scanf("%d",&u);

DFS(u); 
 return 0;
}