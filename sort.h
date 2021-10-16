#ifndef SORT_H
#define SORT_H

typedef struct iorb{
  int basePri; //int representing the base priority
  struct iorb *next;  //pointer to next block
  char filler[100]; //description of block
} IORB; 

IORB *swap(IORB *a, IORB *b);

void bubbleSort(IORB **head, int (*prio)(int), int size);
#endif
