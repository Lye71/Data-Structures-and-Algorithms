
typedef struct node{
	int data;
	struct node* next;
}Node;

typedef struct{
	Node* front;
	Node* rear;
};

void initialize(Queue *q);
bool isFull(Queue *q);
bool isEmpty(Queue *q);
void enqueue(Queue *q, int value);
void dequeue(Queue *q);

void initialize(Queue *q){
	q->front = NULL;
	q->rear = NULL;
}

bool isFull(Queue *q){
	return false;
}

bool isEmpty(Queue *q){
	if(q->front == NULL){
		return true;
	}
	else{
		return false;
	}
}

void enqueue(Queue *q, int value){
	Node *newNode = malloc(sizeof(newNode));
	newNode->data = value;
	newNode->next = NULL;
	if(isEmpty){
		q->front = newNode;
	}
	else{
		q->rear->next = newNode;
	}
	q->rear = newNode;
}

void dequeue(Queue *q){
	if(isEmpty){
		printf("Queue is empty");
	}
	Node *temp = malloc(sizeof(newNode));
	//int value = temp->data;
	q->front = temp->next;
	if(isEmpty){
		q->front = NULL;
		q->rear = NULL;
	}	
	free(temp)
}

