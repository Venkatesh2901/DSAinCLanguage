#include<stdio.h>
#include<stdlib.h>

    int Partition(int arr[] ,int low ,int high) {     
                                                                 // Quick sort Start with last element 
           int pivot =arr[high];                                 
           int i = low-1;                                         //i =-1   

           for(int j = low ; j<high ; j++){
            if(arr[j] <pivot){
                i++;                                              //i =0 to n
             
                //swap
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

             }
           }

           //swap with pivot
           i++;        
           int temp=arr[i];
           arr[i]=arr[high];
           arr[high]=temp;
           return i;                                             //return index  
    }



     void Quicksort(int arr[] ,int low , int high){
       if(low< high){
          int pi=Partition(arr, low, high);                      //pi=pivot index

          Quicksort(arr, low, pi-1);
          Quicksort(arr, pi+1, high);
       }
    }



     void main( ) {
        
        
        
        int n ;
        int arr[n];

        printf("\n Enter the size of array ");
        scanf("%d",&n);
        
        printf(" Enter values in array : ");
        for(int i = 0 ; i <n ; i++){
            scanf(  "%d"  , &arr[i]);
        }

        Quicksort(arr, 0, n-1);

        //print the elements
        printf(" Sorting  in Ascending order : ");
        for(int i =0 ; i <n ;i++){
            printf( "  %d " , arr[i]);
        }
    }
