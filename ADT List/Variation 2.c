#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *Eprt;

void initialize(Eptr *L);
void insertPos(Eptr L, int data, int position);
void deletePos(Eptr L, int position);
int locate(Eptr L, int data);
void insertSorted(Eptr L, int data);
void display(Eptr L);
void makeNULL(Eptr L);

void initialize(Eptr L){
    L->count = 0;
}

void insertPos(Eptr L, int data, int position){
    if(position > L->count || position < 0){
        printf("Invalid position");
        return;
    }
    else if(L->count > MAX){
        printf("List is already full!");
        return;
    }
    int i;
    for(i = L->count; i > position; i--){
        L->elem[i] = L->elem[i-1];
    }
    L->elem[position] = data;
    L->count++;  
}

void deletePos(Eptr L, int position){
    if(position > L->count || position < 0){
        printf("Invalid position");
        return;
    }
    
}