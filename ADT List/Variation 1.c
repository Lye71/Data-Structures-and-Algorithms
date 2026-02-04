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
void display(List L);

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

List deletePos(List L, int data, int position){
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
    int returnVar = -1;
    int i;
    for(i = 0; i < L.count || L.elem[i] != data; i++){
        if(L.elem[i] != data){
            i = returnVar;      
        }
    }
    return returnVar;
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