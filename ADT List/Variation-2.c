#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main(){

    EPtr L = (EPtr)malloc(sizeof(Etype));
    initialize(L);
    insertPos(L, 1, 0);
    insertPos(L, 2, 1);
    insertPos(L, 4, 2);
    insertPos(L, 5, 3);

    //test case for insertPos
    printf("Original List: ");
    display(L);
    printf("\nCount: %d", L->count); 
    insertPos(L, 4, 3);
    printf("\nList after insertion: ");
    display(L);
    printf("\nCount: %d\n", L->count);

    //test case for deletePos
    printf("\nOriginal List: ");
    display(L);
    printf("\nCount: %d", L->count);
    deletePos(L, 3);
    printf("\nList after deletion: ");
    display(L);
    printf("\nCount: %d\n", L->count);

    //test case for locate
    int locateData;
    printf("\nOriginal List: ");
    display(L);
    printf("\nLooking for number 5");
    locateData = locate(L, 5);
    if(locateData == -1){
        printf("\nCannot find Item");
    }
    else{
        printf("\nItem found at index: %d\n", locateData);
    }

    //test case for retrieve
    int retrieveData;
    printf("\nOriginal List: ");
    display(L);
    printf("\nLooking for index 3");
    retrieveData = retrieve(L, 3);
    if(retrieveData == -1){
        printf("\nCannot find Item");
    }
    else{
        printf("\nItem at index 3: %d\n", retrieveData);
    }
    
    //test case for insertSotred
    printf("\nOriginal List: ");
    display(L);
    printf("\nCount: %d", L->count);
    insertSorted(L, 3);
    printf("\nList after inserting sorted: ");
    display(L);
    printf("\nCount: %d\n", L->count);

    return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if(position > L->count || position < 0){
        printf("Invalid position");
        return;
    }
    else if(L->count >= MAX){
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
    for(i = position; i < L->count; i++){
        L->elem[i] = L->elem[i+1];
    }
    L->count--;
}

int locate(EPtr L, int data){
    int i;
    for(i = 0; i < L->count && L->elem[i] != data; i++);
    return(i < L->count)    ? i : -1;
}

int retrieve(EPtr L, int position){
    if(position > L->count || position < 0){
        printf("Invalid position");
        return -1;
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
    for(i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }
}

void makeNULL(EPtr L){
    free(L);
}