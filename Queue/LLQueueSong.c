#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* QUESTION 1: QUEUE (Linked List Implementation)
   ---------------------------------------------------------
   GOAL: 
   1. Rewrite 'enqueue' to only add songs from 1950 to 1980.
   2. Write 'dequeue' to remove and return the front song.
   --------------------------------------------------------- 
*/

typedef struct {
    char songName[50];
    int songYear;
    float duration;
} Song;

typedef struct Node {
    Song data;
    struct Node* next;
} Node, *NodePtr;

typedef struct {
    NodePtr front;
    NodePtr rear;
} Queue;

// Predefined: Initializes the queue pointers to NULL
void initQueue(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

// Predefined: Displays the current contents of the queue
void displayQueue(Queue Q) {
    NodePtr curr = Q.front;
    printf("\n--- Current Songlist (1950s-1980s) ---\n");
    if (curr == NULL) {
        printf("The queue is empty.\n");
    }
    while (curr != NULL) {
        printf("[%d] %-20s | %.2f min\n", 
               curr->data.songYear, curr->data.songName, curr->data.duration);
        curr = curr->next;
    }
    printf("--------------------------------------\n");
}

/* ---------------------------------------------------------
   TODO: YOUR CORE FUNCTIONS TO IMPLEMENT
   --------------------------------------------------------- */

/**
 * Requirement: 
 * - Only create a node and add to queue if S.songYear is [1950, 1980].
 * - Handle both "Empty Queue" and "Populated Queue" cases.
 */
void enqueue(Queue *Q, Song S) {
    // 1. Check the year constraint first.
    if(S.songYear > 1950 && S.songYear < 1980){
        Node* newNode = malloc(sizeof(Node));
        newNode->data = S;
        newNode->next = NULL;
        if(Q->front == NULL){// isEmpty(Q)
            Q->front = newNode;
        }
        else{
            Q->rear->next = newNode;
        }
        Q->rear = newNode;
    }
    // 2. If valid, malloc a new Node.
    // 3. Assign S to newNode->data.
    // 4. Update Q->front and Q->rear pointers.
    
    // YOUR CODE HERE
}

/**
 * Requirement:
 * - Remove the node at the front.
 * - Return the data (Song) that was in that node.
 * - Free the memory of the removed node.
 */
Song dequeue(Queue *Q) {
    Song dummy = {"EMPTY", 0, 0.0};
    
    // 1. Check if the queue is empty.
    if(Q->front != NULL){
        Node *temp = Q->front;
        dummy = temp->data;
        Q->front = temp->next;
        if (Q->front == NULL) {
            Q->rear = NULL;        
        }

        free(temp);
        return dummy;
    }
    // 2. If not, capture the data and the node pointer.
    // 3. Move Q->front to the next node.
    // 4. If the queue becomes empty, set Q->rear to NULL.
    // 5. free() the old node and return the data.

    // YOUR CODE HERE
    return dummy; 
}

/* ---------------------------------------------------------
   MAIN TEST SUITE
   --------------------------------------------------------- */

int main() {
    Queue mySongList;
    initQueue(&mySongList);

    // Test Data
    Song s1 = {"Bohemian Rhapsody", 1975, 5.55}; // Valid (1970s)
    Song s2 = {"Billie Jean", 1982, 4.54};       // Invalid (Post-1980)
    Song s3 = {"Johnny B. Goode", 1958, 2.41};   // Valid (1950s)
    Song s4 = {"Shake It Off", 2014, 3.39};      // Invalid (Modern)

    printf("Attempting to enqueue 4 songs...\n");
    enqueue(&mySongList, s1);
    enqueue(&mySongList, s2);
    enqueue(&mySongList, s3);
    enqueue(&mySongList, s4);

    // Only s1 and s3 should appear here
    displayQueue(mySongList);

    printf("\nTesting Dequeue...\n");
    Song removed = dequeue(&mySongList);
    printf("Removed: %s (%d)\n", removed.songName, removed.songYear);

    displayQueue(mySongList);

    return 0;
}