#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List L;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
List display(List L);

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
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){

    if(position > L.count || position < 0){
        printf("Invalid position");
        return L;
    }
    else if(L.count >= MAX){
        printf("List is full!");
        return L;
    }
    int i;
    for(i = L.count; i > position; i--){
        L.elem[i] = L.elem[i-1];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(position > L.count || position < 0){
        printf("Invalid position");
        return L;
    }
    else if(L.count >= MAX){
        printf("List is full!");
        return L;
    }
    int i;
    for(i = position; i < L.count; i++){
        L.elem[i] = L.elem[i+1];
    }
    L.count--;
    return L;
}

int locate(List L, int data){
    int i;
    for(i = 0; i < L.count && L.elem[i] != data; i++);
    return(i < L.count) ? i : 1;
}

List insertSorted(List L, int data){
    if(L.count >= MAX){
        printf("List is full!");
        return L;
    }
    int i;
    for(i = 0; i < L.count && data > L.elem[i]; i++){
    }
    return insertPos(L, data, i);
}

List display(List L){
    int i;
    for(i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
}