#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void linklisttransversal( struct node *ptr){
   while(ptr!=NULL){
     printf("\n element : %d",ptr->data);
     ptr=ptr->next;
   }
}

 //insert AT FIRST
struct node *insertAtFirst(struct node *head,int data){
   struct node *ptr=(struct node*)malloc(sizeof(struct node)); 

   ptr->data=data;
   ptr->next=head;
    
   head=ptr;
   return head;
}

//Insert at given INdex
struct node *insertAtIndex(struct node *head,int data,int index){
   struct node *ptr=(struct node*)malloc(sizeof(struct node)); 
   struct node *p=head;

   ptr->data=data;

   int i=0;
   while(i!=index-1){
    p=p->next;
    i++;
   }

   ptr->next=p->next;
   p->next=ptr;
   return head;
}


//Insert At Last Poistion 
struct node *insertAtEnd(struct node *head,int data){
   struct node *ptr=(struct node*)malloc(sizeof(struct node)); 

   ptr->data=data;

   struct node *p=head;
   while(p->next!=NULL){
    p=p->next;
   }

   p->next=ptr;
   ptr->next=NULL;
   return head;
}

//searching in a linked list 
void search(int num,struct node *head){
   struct node *ptr=NULL;
   ptr=head;

   while(ptr!=NULL){
      if(ptr->data==num){
         printf(" \n Element find successful");
         return ;
      } ptr=ptr->next;
   } printf("\n element not found ");
}
  

//  Deleting the first element from the linked list
struct node * deleteFirst(struct node * head){
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Deleting the element at a given index from the linked list
struct node * deleteAtIndex(struct node * head, int index){
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

// Deleting the last element
struct node * deleteAtLast(struct node *head){
    struct node *p = head;
    struct node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}




int main(){
    struct node*head;
    struct node*first;
    struct node*second;

    //allocates memory of node in heap
     head=(struct node*)malloc(sizeof(struct node));
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));

    struct node*third=(struct node*)malloc(sizeof(struct node));                    // intilation +allocated memory

    //link 1st and 2nd nodes
    head->data=7;
    head->next=first;

    //link  2nd  & 3rd nodes
    first->data=14;
    first->next=second;

    //link 2nd and 3rd nodes
    second->data=21;
    second->next=third;

    //terminated the list 
    third->data=42;
    third->next=NULL;


    printf("\n linklist before insertion :");
    linklisttransversal(head);
    printf("\n ");

   //insertion 
    printf("\n linklist AFTER  begging insertion :");
    head=insertAtFirst(head,1);
    linklisttransversal(head);

    printf("\n linklist AFTER  Middle  insertion");
     head=insertAtIndex(head,28,3);
     linklisttransversal(head);

    printf("\n linklist AFTER Ending insertion");
     head=insertAtEnd(head,48);
     linklisttransversal(head);

     printf(" \n");


   //searching 
    printf("\n Searching in a linked List ");
    search(21,head);

    printf(" \n ");


   //deletion in a linked list
    printf(" \n Linked list after first node deletion");
    head = deleteFirst(head); 
   linklisttransversal(head);

    printf(" \n Linked list after  Middle deletion");
    head = deleteAtIndex(head, 2);
   linklisttransversal(head);

    printf(" \n Linked list after End node deletion");
    head = deleteAtLast(head);
   linklisttransversal(head);
    
  return 0;

}