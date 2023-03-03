#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *left;
 struct node *right;
};


struct node *CreateNode(int data){
  struct node*n;  //creating a node pointer 
  n=(struct node*)malloc(sizeof(struct node));  //Allocating memory in heap
  
   n->data=data;      
   n->left=NULL;
   n->right=NULL;
   return n;        //returing the creating node
}


void preorder(struct node *root){
    if(root!=NULL){
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root){
    if(root!=NULL){
       inorder(root->left);
        printf(" %d ",root->data);
       inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder (root->left) ;
        postorder(root->right);
        printf(" %d ",root->data);
    }
}

//searching in a BST
struct node *Search(struct node *root,int key){
    if(root==NULL){
        return NULL;
    }

    if(key==root->data){
        return root;
    }

    else if(key<root->data){
       return Search(root->left,key);
      }

     else{
        return Search(root->right,key);
      }
  }


//Insertion in a BST
void insert(struct node *root , int key){
  struct node *prev=NULL;

    while(root!=NULL){
    prev=root;

    if(key== root->data){
     printf(" \n cannot insert %d element, Alreading present in BST",key);
     return ;
    }
     else if(key <root->data){
       root =root->left;
     }
     else {
        root=root->right;
     }
   }
   struct node *new1=CreateNode(key);
   if(key < prev->data){
        prev->left =new1 ;
     }
     else{
        prev->right =new1 ;
     }
}
  

 int  main(){
 struct node *p=CreateNode(4);
 struct node *p1=CreateNode(2);
 struct node *p2=CreateNode(6);
 struct node *p3=CreateNode(1);
 struct node *p4=CreateNode(3);

 //linking the node with left and right childrem
 p->left=p1;
 p->right=p2;
 p1->left=p3;
 p1->right=p4;

 printf("\n BST by using preorder :");
 preorder(p);

 printf("\n BST by using inorder  :");
 inorder(p);

 printf("\n BST by using postorder:");
 postorder(p);
 
 printf("\n ");


//searching in BST
 printf("\n Searching in BST");
 struct node *n = Search(p,6);
  if(n!=NULL){
    printf(" \n Element found: %d",n->data);
}
  else{
    printf(" \n  This Element is  not found");
 }
printf("\n");


//insertion in BST
printf("\n insertion in a BST");
insert(p,16);
printf(" \n %d",p->right->right->data);
  
 return 0;
}