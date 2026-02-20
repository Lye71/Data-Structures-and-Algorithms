#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main(){
    List L;
    L = initialize(L);
    L = insertPos(L, 1, 0);
    L = insertPos(L, 2, 1);
    L = insertPos(L, 4, 2);
    L = insertPos(L, 5, 3);

    //test case for insertPos
    printf("Original List: ");
    display(L);
    printf("\nCount: %d", L.count); 
    L = insertPos(L, 4, 3);
    printf("\nList after insertion: ");
    display(L);
    printf("\nCount: %d\n", L.count);

    //test case for deletePos
    printf("\nOriginal List: ");
    display(L);
    printf("\nCount: %d", L.count);
    L = deletePos(L, 3);
    printf("\nList after deletion: ");
    display(L);
    printf("\nCount: %d\n", L.count);

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
    
    //test case for insertSotred
    printf("\nOriginal List: ");
    display(L);
    printf("\nCount: %d", L.count);
    L = insertSorted(L, 3);
    printf("\nList after inserting sorted: ");
    display(L);
    printf("\nCount: %d\n", L.count);

    return 0;
}

List initialize(List L){
    L.elemPtr = malloc(sizeof(int)*LENGTH);
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position <= L.count && position >= 0){
        if(L.count == L.max){
            L = resize(L);
        }
        int i;
        for(i = L.count; i > position; i--){
            L.elemPtr[i] = L.elemPtr[i-1];
        }
        L.elemPtr[position] = data;
        L.count++;
    }
    else{
        printf("Position Invalid!");
    }
    return L;
}

List deletePos(List L, int position){
    if(position < L.count && position >= 0){
        int i;
        L.count--;
        for(i = position; i < L.count; i++){
            L.elemPtr[i] = L.elemPtr[i+1];
        } 
    }
    else{
        printf("Position Invalid!");
    }
    return L;
}

int locate(List L, int data){
    int i;
    int j = -1;
    for(i = 0; i < L.count; i++){
        if(L.elemPtr[i] == data){
            j = i;
        }
    }
    return j;
}

List insertSorted(List L, int data){
    if(L.count == L.max){
        L = resize(L);
    }
    int i;
    for(i = 0; i < L.count && data > L.elemPtr[i]; i++){}
    
    return insertPos(L, data, i);;
}

void display(List L){
    int i;
    for(i = 0; i < L.count; i++){
        printf("%d, ", L.elemPtr[i]);
    }
}

List resize(List L){
    L.max *= 2;
    L.elemPtr =  realloc(L.elemPtr, sizeof(int)* L.max);
    return L;
}