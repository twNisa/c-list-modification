#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include "sort.h"

IORB *swap(IORB *a, IORB *b){   //parse in a pointer and b pointer
  IORB *temp;                   //create new block pointer
  temp= b->next;                
  b->next = a;                  
  a->next = temp;
  return b;                     //return the smaller block
};


void bubbleSort(IORB **start, int (*prio)(int), int size)   //parse in pointer of header pointer, pointer to prio function, and size
{ 
    IORB **h;                   //create pointer of pointer of a new block
    int i, j, flag;
    for(i=0; i<= size;i++){     

        h = start;              
        flag = 0;                   
        
        for(j=0; j< size-i-1; j++){     //size-i-1 because each loop will end up with a block that is sorted at the end
             
            IORB *a = *h;               //pointer to current block
            IORB *b = a->next;          //pointer to next block
                        
            if(prio(a->basePri) > prio(b->basePri)){    //check priority value, if left is bigger than right, then swap
                *h = swap(a,b);         //pointer will be the new left block
                flag = 1;
            
            }
            
            h = &(*h)->next;            //head block will be the next block.
        }
        if(flag == 0)                   //after a loop through the list, if no swapping happened, then the list is in order, then stop.
            break;
        
    }
};
