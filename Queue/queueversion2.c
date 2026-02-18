#define MAX 10

typedef struct
{
    int items[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue *q);
bool isFull(Queue *q);
bool isEmpty(Queue *q);
void enqueue(Queue *q, int value);
void dequeue(Queue *q);

void initialize(Queue *q){
	q->front = 1;
	q->rear = 0;
}

bool isFull(Queue *q)
{
    return q->front == (q->rear + 2) % MAX;
}

bool isEmpty(Queue *q)
{
    return q->front == (q->rear + 1) % MAX;
}

void enqueue(Queue *q, int value){
	if(isFull(Queue *q)){
		printf("Queue is full");
	}
	else{
		q->rear = (q->rear+1) % MAX;
		q->items[q->rear] = value;
	}
	
}

void dequeue(Queue *q){
	if(isEmpty(Queue *q)){
		printf("Queue is empty");
	}
	else{
		q->front = (q->front+1) % MAX;
	}
}


