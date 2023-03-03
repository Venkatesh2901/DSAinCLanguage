#include<stdio.h>
#include<stdlib.h>
void prims(int n,int cost[10][10]){
    int i,j,u,v,min,mincost=0,vis[10],ne=1;
    for(i=1;i<=n;i++){
        vis[i]=0;
    }
    printf("The edges for mst are\n");
    vis[1]=1;
    while(ne<n){
        for(i=1,min=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    if(vis[i]==0)
                    {
                        continue;
                    }
                    else{
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(vis[u]==0||vis[v]==0){
            printf("%d edge (%d %d)=%d\n",ne++,u,v,min);
             mincost=mincost+min;
            vis[v]=1;
        }
        cost[u][v]=cost[v][u]=999;
    }
    printf("cost =%d\n",mincost);
}
int main(){
    int i,j,n,cost[10][10];
    printf("Enter the no of node\n");
    scanf("%d",&n);
    printf("Enter the cost\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);

            
            if(cost[i][j]==0){
                cost[i][j]==999;
            }
        }
    }
    prims(n,cost);
    return 0;
}