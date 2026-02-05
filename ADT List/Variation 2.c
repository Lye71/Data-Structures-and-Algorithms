#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr *L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main(){
    return 0;
}

void initialize(EPtr L){
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

void deletePos(EPtr L, int position){
    if(position > L->count || position < 0){
        printf("Invalid position");
        return;
    }
    int i;
    for(i = position; i < L->count; ++){
        L->elem[i] = L->elem[i+1];
    }
    L->count--;
}

int locate(EPtr L, int data){
    int i;
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data){
            return i;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position){
    if(position > L->count || position < 0){
        printf("Invalid position");
        return;
    }
    return L->elem[position];
}

void insertSorted(EPtr L, int data){
    if(L->count >= MAX){
        printf("List is full!");
        return;
    }
    int i;
    for(i = 0; i < L->count && data > L->elem[i]; i++){}
    insertPos(L, data, i);
}

void display(EPtr L){
    int i;
    printf("It contains: ");
    for(i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }
}

void makeNULL(EPtr L){
    free(L);
}