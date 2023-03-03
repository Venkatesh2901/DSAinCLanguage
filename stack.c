#include<stdio.h>
#include<stdlib.h>

int stack[50],i,x,n,top,choice;

void push(){
    if(top>=n-1){
        printf("\n  stack is overflow");
    } else{
        printf(" \n  enter the value to be pushed ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void pop(){
    if(top<=-1){
        printf("\n stack is underflow");
    }else{
        printf("\n  element deleted from stack is %d",stack[top]);
        top--;
    }
}

void display(){
    if(top>=0){
        printf("\n  the element in stack is ");
        for(i=0;i<=top;i++){
            printf("%d",stack[i]);

        }
    }else{
        printf("\n stack is  empty");
     }
}

int main(){
  top=-1;
  printf("\n enter the size ofstack :")   ;
  scanf("%d",&n);

  printf(" \n  enter 1.push /n 2.pop /n 3.display /n 4.exit");
  do{
     printf(" \n  enter the choice :");
     scanf("%d",&choice);

     switch(choice){
        
        case 1: {
            push();
            break;
        }

        case 2: {
            pop();
            break;
        }

        case 3: {
            display();
            break;
        }

        case 4: {
            printf(" \n  exit");
            break;
        }
        default:{
            printf(" \n  please enter a validchoice");

        }
     }
 }while( choice!=4);
 return 0;
}