#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
} List, *ListPtr;

void initialize(ListPtr *L);
void insertPos(ListPtr L, int data, int position);
void deletePos(ListPtr L, int position);
int locate(ListPtr L, int data);
int retrieve(ListPtr L, int position);
void insertSorted(ListPtr, int data);
void display(ListPtr L);
void makeNULL(ListPtr L);

int main(){

    ListPtr L;
    initialize(&L);
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

void initialize(ListPtr *L){
    *L = (ListPtr)malloc(sizeof(List)); //can also be = malloc(sizeof(List))
    if(*L != NULL){
        (*L)->elemPtr = malloc(sizeof(int) * LENGTH);
        (*L)->max = LENGTH;
        (*L)->count = 0;
        }
    }
    

void insertPos(ListPtr L, int data, int position){
    if(position < L->max && position >= 0){
        if(L->count == L->max){
            resize(L);
        }
        int i;
        for(i = L->count; i > position; i--){
            L->elemPtr[i] = L->elemPtr[i-1];
        }
        L->elemPtr[position] = data;
        L->count++;
    }
    else{
        printf("Invalid Position!");
    }
}

void deletePos(ListPtr L, int position){
    if(position < L->count && position >= 0){
        int i;
        L->count--;
        for(i = position; i < L->count; i++){
            L->elemPtr[i] = L->elemPtr[i+1];
        }
    }
    else{
        printf("Invalid Position");
    }
}

int locate(ListPtr L, int data){
    int i;
    int j = -1;
    for(i = 0; i < L->count; i++){
        if(data == L->elemPtr[i]){
            j = i;
        }
    }
    return j;
}

int retrieve(ListPtr L, int position){
    if(position < L->count && position >= 0){
        return L->elemPtr[position];
    }
    else{
        printf("Invalid P osition");
        return -1;
    }
}


void insertSorted(ListPtr L, int data){
        if(L->count == L->max){
            resize(L);
        }
        int i;
        for(i = 0; data > L->elemPtr[i]; i++){}
        insertPos(L, data, i);
}

void display(ListPtr L){
    int i;
    for(i = 0; i < L->count; i++){
        printf("%d, ", L->elemPtr[i]);
    }
}

void resize(ListPtr L){
    L->max *= 2;
    L->elemPtr = realloc(L->elemPtr, sizeof(int) * L->max);
}

void makeNULL(ListPtr L){
    free(L->elemPtr);
    free(L);
}