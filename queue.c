 #include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

struct queue{
    struct node *front;
    struct node *rear;
};
struct node *q;
void create_queue(struct queue *);
struct queue *insert(struct queue *,int);
struct queue *delete(struct queue *);
struct queue *disp(struct queue *);
int peek(struct queue *);

void create_queue(struct queue *q){
    q->front=NULL;
    q->rear=NULL;
    q->front->next=q->rear->next=NULL;
}

struct queue *insert(struct queue *q,int val){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    if(q->front==NULL){
        q->front=NULL;
        q->rear=NULL;
        q->front->next=q->rear->next=NULL;
    }
    else{
        q->rear->next=temp;
        q->rear=temp;
        q->rear->next=NULL;
    }
    return q;
}

struct queue * delete(struct queue *q){
    struct node *temp;
    temp=q->front;
    if(q->front==NULL)
    printf("\n Underflow");
    else{
        q->front=q->front->next;
        printf("\n %d",temp->data);
        free(temp);
    }
    return q;
}

int peek(struct queue *q){
    if(q->front=NULL){
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else
    return q->front->data;
}

struct queue *disp(struct queue *q){
    struct node *temp;
    temp=q->front;
    if(temp=NULL){
        printf("\n queue is empty");
    }
    else{
        printf("\n");
        while(temp!=q->rear){
            printf("\n %d",temp->data);
            temp=temp->next;

        }
         printf("\n %d",temp->data);  
    }
    return q;
}