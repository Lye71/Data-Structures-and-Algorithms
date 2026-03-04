#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main(){
    return 0;
}

List* initialize(){
    List *list = malloc(sizeof(List));
    if(list == NULL){
        return NULL;
    }
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list){
    Node *head = list->head;
    int i;
    for(i = 0; i < list->count; i++){
        free(head);
        head = head->next;
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error allocating memory.");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error allocating memory.");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL){
        list->head = newNode;
    }
    else{
        Node *curr = list->head;
        int i;
        for(i = 0; i < list->count && list != NULL; i++){
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void insertPos(List *list, int data, int index){
    if(index > list->count){
        printf("Index is invalid");
        return;
    }
    if(index == 0){
        insertFirst(list, data);
    }
    if(index == list->count){
        insertLast(list, data);
    }
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error allocating memory.");
        return;
    }
    newNode->data = data;
    Node* curr = list->head;
    int i;
    for(i = 0; i < (index - 1); i++){
        curr = curr->next;
    }
    curr->next = newNode;
    list->count++;
}

void deleteStart(List *list){
    Node* curr = list->head;
    list->head = curr->next;
    free(curr);
    list->count--;
}

void deleteLast(List *list){
    if(list->count == 1){
        list->head = NULL;
        list->count--;
        return;
    }
    Node* curr = list->head;
    int i;
    for(i = 0; i < (list->count -2); i++){
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    list->count--;
}

void deletePos(List *list, int index)
{
    if (index > list->count || index < 0)
    {
        return;
    }

    if (index == 0)
    {
        deleteStart(list);
        return;
    }

    if (index == list->count)
    {
        deleteLast(list);
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);

    list->count--;
}

int retrieve(List *list, int index)
{
    Node *head = list->head;
    if (head == NULL || index > list->count || index < 0)
    {
        return -1;
    }

    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->data;
}

int locate(List *list, int data)
{
    Node *head = list->head;
    if (head == NULL)
    {
        return -1;
    }

    Node *current = head;
    int index = 0;
    while (current != NULL)
    {
        if (current->data == data)
            return index;

        current = current->next;
        index++;
    }

    return -1;
}

void display(List *list)
{
    Node *current = list->head;
    printf("head: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\ncount: %d\n\n", list->count);
}