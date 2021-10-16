#include<stdio.h> 
#include<stdlib.h> 
#include <stddef.h>
#include <string.h>
#include<time.h>
#include <unistd.h>
#include <sys/types.h>


#include "sort.h"
//initialise IORB for starting list block
IORB *listStart = NULL;

//function to build list, head is pointer to the pointer to linked list
void buildList(IORB **head,int size); 

//function to displaylist
void displayList(IORB *head);

//function to delete list
void deleteList(IORB **head);

//display menu
void menu();

//function to insert to list
void insertToList(IORB **head, char* filler, int prio);

//prio compute
int prioComp(int x);


int main(){
  srand(time(NULL));
  int listSize = 10;
  int user; //variable for user input

  //while loop for main menu
  while (1){   

    menu();
    printf("Enter a decision\n");
    scanf("%d", &user);
    printf("entered: %d", user);

    while(user < 0 || user > 4){
      printf("\nInvalid option, please enter a number between 0 and 4.\n");
      scanf("%d", &user);
    }

    switch(user){
      case 0:
      deleteList(&listStart);
      printf("\nExiting program...\n");
      exit(0);
      break;

      case 1:
      printf("\nBuilding the list...\n");
      buildList(&listStart, listSize);
      break;
      
      case 2:
      printf("\nDisplaying the list...\n");
      displayList(listStart);
      break;

      case 3:
      printf("\nSorting the list...\n");
      if(listStart == NULL){
        printf("\nList is empty\n");
      } else{
        bubbleSort(&listStart, prioComp, listSize);
      }
      break;

      case 4:
      printf("\nDeleting the list...\n");
      deleteList(&listStart);
      break;

      default:
      break;

    }
  }

  return 0;
}

void menu(){
  printf("\nOptions\n");
  printf("0 - Exit\n");
  printf("1 - Build List\n");
  printf("2 - Display List\n");
  printf("3 - Sort List\n");
  printf("4 - Delete List\n");
}

//insert to beginning of the list
void insertToList(IORB **head, char *data, int prio){     //parse in pointer to header pointer, pointer to text data and the prio int

  IORB *new = (struct iorb*) malloc(sizeof(struct iorb)); //create new block
  strcpy(new->filler, data);                              //copy filler text to new block
  new->next = *head;                                      //point next to head pointer of list
  new->basePri = prio;                                    
  *head = new;                                            //change header pointer to the new block

};


//build list function
void buildList(IORB **head,int size){   //parse in pointer to the header pointer and list size
  int x;
  char text[100];
  for (x = 0; x < size; x++){           //loop list size times from 0
    int base = rand()%100+1;            //get priority number, between 1 and 100;
    int newBase = prioComp(base);       
    sprintf(text, "Block Description: this is i/o request %d, base prio: %d, Priority: %d", x, base, newBase); 
    insertToList(&(*head), text, base); //insert to the list

  }
};

//display list function
void displayList(IORB *head){     //parse in the head pointer
  if(head == NULL){               //if head is null, the the list is empty
    printf("\nList is empty\n");
    return;
  }

  IORB *temp = head;              //create new temp pointer to head
  printf("\n");       

  while(temp!=NULL){              //while temp is not null, print out the filler text
   
    printf("%s\n", temp->filler);
    temp = temp->next;            //update temp to the next block

  } 
}

int prioComp(int x){
  x = 6 * x + 20 / 2;
  return x;
}

//delete the list
void deleteList(IORB **head){      //pointer of the pointer to the head of the list
  if(*head){                       //if the pointer to the head is not empty,
    while(*head){                  //while pointer to the head is not empty, create new pointer having the head pointer value
      IORB *temp = *head;
      if(head!=NULL){              //if the block is not empty, then change the head pointer to the next block, then free temp
        *head = temp->next;
        free(temp);
      }
    }
    printf("List is empty\n");
  }else{                           
      printf("List is already empty\n");
    }
}
