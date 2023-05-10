#include<stdio.h>
 void Knapsack(int num , float weight[] , float profit[] ,int  cpu){
   float x[20];
   float tp=0;
   int i ,j , u;
   u=cpu;

   for(i=0; i<num;i++){
    x[i]=0.0;
   }

   for(i=0;i<num;i++){
    if(weight[i]>u)              //beyond limit 
    break;

    else{
        x[i]=1.0;
       
        tp = tp + profit[i];
        u = u-weight[i];    
     } 
   }

   if(i<num)
     x[i]=u/weight[i];
     tp=tp+(x[i]*profit[i]);

  
   printf("\n Total Profit  : %f " ,tp);

}




 int main(){
    float weight[20] , profit[20] , ratio [20]  ,temp;      
    int num , i , j ,k,a,b, cp ;

    printf(" \n enter the value total number  of object ");
    scanf("%d" , &num);

    printf(" \n enter the value of capacity ");
    scanf("%d" , &cp);
    
    
    printf("\n Enter the weight   of each objects : ");
    for(i = 0 ; i<num ; i++){
        scanf( " %f " , &weight[i]);
    }

     printf("\n Enter the profit  of each objects : ");
    for(j = 0 ; j<num ; j++){
        scanf( " %f  " , &profit[j] );
    }
    

   for(k = 0 ; k<num ; k++){
        ratio[k] = ( profit[k]/weight[k] );
    }


    printf(" \n profit  of element : ");
    for(i = 0 ; i< num ; i++){
         printf(" %f \n ", profit[i]);
     }
    printf(" \n weight  of element : ");
    for(j = 0 ; j< num ; j++){
         printf(" %f \n ", weight[j]);
     }
    printf(" \n ratio of element : ");
    for(k = 0 ; k<num ; k++){
         printf(" %f \n ", ratio[k]);
     }

    
     for(a=0;a<num ;a++){
        for(b=i+1 ;b<num ;b++){
          if(ratio[i]<ratio[j]){
           temp = ratio[a];
           ratio[a]=ratio[b];
           ratio[b]=temp;

           temp = profit[a];
           profit[a]=profit[b];
           profit[b]=temp;

           temp = weight[a];
           weight[a]= weight[b];
           weight[b]=temp;
          
          }
        }
      }
     Knapsack( num ,  weight , profit,  cp);
     return 0;

        
      
    
 }