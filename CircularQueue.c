#include<stdio.h>

#define MAX 5

int Queue[MAX];
int front=-1;
int rear=-1;

 void Enqueue(int item){
     if((front==0 && rear==MAX-1 )||( front==rear+1)){
        printf("\n Queue underflow");
        return ;
     }
     if(front==-1){
            front =0;
            rear =0;
     }

     else{
         if(rear==MAX-1){
          rear =0;
         }
          else{
            rear=rear+1;
          }
        Queue[rear]=item;
     }
     
 }

 void Dequeue(){ 
   if(front==-1){                  // underflow condition 
     printf("\n Queue Underflow");
     return ;
   }

   printf("\n element deleted from circular queue :%d",Queue[front]);

   if(front==rear){               //last element , set to intial
     front=-1;        
     rear=-1;
   }
   else{  
      if(front==MAX-1){          //conition of circular queue
         front=0;
      }
      else{
        front=front+1;           //increment of front
      }
   }
 }

 void Display(){
    int i;
    if(front<=rear){
        for(i=front ; i<=rear ; i++){
            printf("\n elements in queue are : %d", Queue[i]);
        }
    }
    else{
        for(i=front;i<=MAX-1;i++){
            printf("\n elemts : %d "),Queue[i];
        }
        for(i=0;i<=rear;i++){
            printf("\n %d "),Queue[i];
        }
    }
 }

 int main(){
    int choice ,item;

    do{
        printf("\n Select your choice 1.Insert , 2.Delete, 3.Display , 4.Exit \n ");
        printf("\n enter your choice :");
        scanf("%d",&choice);

        switch(choice){
          case 1:
          {
                printf("\n enter the element you want to be insert ");
                scanf("%d",&item);
                Enqueue(item);
                break;
          }
          case 2 :
          {
                 Dequeue();
                 break;    
          }

          case 3 :
          {
                 Display();
                 break;
          }

          case 4:
          {
                break;
          }
          default: printf("\n enter valid choice");
        }
    } while(choice!=4);
  return 0;
 }