#include<stdio.h>

int max(int a, int b) {
   if(a>b){
      return a;
   } else {
      return b;
   }
}



int knapsack(int CP, int wt[], int OBJ[], int n) {
   int i, w;
   int knap[n+1][CP+1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= CP; w++) {
         if (i==0 || w==0)
            knap[i][w] = 0;
         else if (wt[i-1] <= w)
            knap[i][w] = max(OBJ[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
         else
            knap[i][w] = knap[i-1][w];
      }
   }
   return knap[n][CP];



}
int main() {
 
   int size;

   int wt[size];
   int OBJ[size];
   int CP ;                                //capacity 

   printf("\n enter the no of object : ");
   scanf("%d",&size);

   printf("\n Enter the  values in OBJECT array :");
   for(int i=0;i<size;i++){
      scanf("%d",&OBJ[i]);
   }

   printf("\n Enter the values in Weight array :");
   for(int i=0;i<size;i++){
     scanf("%d",&wt[i]);
   }

    printf("\n Enter the value of capacity :");
   scanf("%d",&CP);
   


   printf(" \n The solution is : %d ", knapsack(CP, wt, OBJ, size));
   return 0;
}