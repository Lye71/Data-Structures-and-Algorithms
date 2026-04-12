#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct{
	char partName[20];
	int partID;
	int speed;
	int acceleration;
	int weight;
	int handling;
	int traction;
}Stats;

typedef struct{
	Stats body;
	Stats wheel;
	Stats glider;
}Vehicle;

typedef struct{
	char itemName[20];
	int itemID;
}Item;

typedef struct{
	char name[20];
	int id;
}IGN;

typedef struct{
	char chcterName[20];
	int chcterID;
	int chcterWeight;
}Character;

typedef struct {
    Item items[2];
    IGN ign;
    Character character;
    Vehicle vehicle;
    int coin;
    int score;
} User;

typedef struct {
    User data;
    int next;
} Node;

typedef struct {
    Node H[MAX];
    int avail;
} VHeap;


void initialize(VHeap *V);
int allocSpace(VHeap *V);
void deallocSpace(VHeap *V, int index);
void insertLast(int *L, VHeap *V, User u);
void insertFirst(int *L, VHeap *V, User u);
void insertByPlace(int *L, VHeap *V, User u);
void deleteUser(int *L, VHeap *V, char* name);
void display(int L, VHeap V);


int main() {
    VHeap myHeap;
    int leaderboard = -1;

    initialize(&myHeap);

    User u1 = {.score = 80};
    strcpy(u1.ign.name, "Bullock");
    
    User u2 = {.score = 65};
    strcpy(u2.ign.name, "Bradford");

    User u3 = {.score = 120};
    strcpy(u3.ign.name, "James");


    printf("Adding users to the leaderboard");
    insertByPlace(&leaderboard, &myHeap, u1);
    insertByPlace(&leaderboard, &myHeap, u2);
    insertByPlace(&leaderboard, &myHeap, u3);
    display(leaderboard, myHeap);

    printf("\nDeleting 'Bullock' from the leaderboard");
    deleteUser(&leaderboard, &myHeap, "Bullock");
    display(leaderboard, myHeap);

    printf("\nTesting reusing slots");
    User u4 = {.score = 90};
    strcpy(u4.ign.name, "Bob");
    insertByPlace(&leaderboard, &myHeap, u4);
    display(leaderboard, myHeap);

}


void initialize(VHeap *V) {
    for (int i = 0; i < MAX - 1; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
    V->avail = 0;
}

int allocSpace(VHeap *V) {
    int p = V->avail;
    if (p != -1) {
        V->avail = V->H[p].next;
    }
    return p;
}

void deallocSpace(VHeap *V, int index) {
    if (index != -1) {
        V->H[index].next = V->avail;
        V->avail = index;
    }
}

void insertLast(int *L, VHeap *V, User u) {
    int newNode = allocSpace(V);
    if (newNode == -1) {
        printf("Insertion failed: no space available.\n");
        return;
    }

    V->H[newNode].data = u;
    V->H[newNode].next = -1;

    int *trav = L;
    while (*trav != -1) {
        trav = &V->H[*trav].next;
    }
    *trav = newNode;
}

void insertFirst(int *L, VHeap *V, User u){
    int newNode = allocSpace(V);
    if (newNode == -1)
    {
        printf("Insertion failed: no space available.\n");
        return;
    }

    V->H[newNode].data = u;
    V->H[newNode].next = *L;

    *L = newNode;
    

}

void insertByPlace(int *L, VHeap *V, User u){
    int newNode = allocSpace(V);

    if (newNode == -1){
        printf("Insertion failed: no space available.\n");
        return;
    }


    V->H[newNode].data = u;

    int *trav = L;
    while (*trav != -1 && V->H[*trav].data.score >= u.score) {
        trav = &V->H[*trav].next;
    }

    V->H[newNode].next = *trav; 
    *trav = newNode;
}

void deleteUser(int *L, VHeap *V, char* name) {
    int *trav = L, temp;
    
    while (*trav != -1 && strcmp(V->H[*trav].data.ign.name, name) != 0) {
        trav = &V->H[*trav].next;
    }

    if (*trav != -1) {
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V, temp);
    } else {
        printf("User '%s' not found.\n", name);
    }
}

void display(int L, VHeap V) {
    if (L == -1) {
        printf("List is currently empty.\n");
        return;
    }
    printf("\n%-15s | %-10s | %-5s\n", "IGN", "SCORE", "INDEX");
    printf("--------------------------------------\n");
    for (int curr = L; curr != -1; curr = V.H[curr].next) {
        printf("%-15s | %-10d | %d\n", 
               V.H[curr].data.ign.name, 
               V.H[curr].data.score,
               curr);
    }
}

