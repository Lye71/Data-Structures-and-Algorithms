#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;

void init(Stack **s);
void push(Stack* s, int value);
void pop(Stack* s);

void init(Stack **s){
    (*s)->top = -1;
}

void push(Stack* s, int value){
    if(isFull(s)){
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

void pop(Stack* s){
    if(isEmpty(s)){
        return;
    }
    s->top--;
}