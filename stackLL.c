#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *top=NULL;
struct stack *push(struct stack *, int);
struct stack *pop(struct stack *);
int peek(struct stack *);
struct stack *disp(struct stack *);

int main(){
    int val,opt;
    do{
        printf("\n________MAIN MENU_________");
        printf("\n 1.PUSH");
        printf("\n 2.POP");
        printf("\n 3.PEEK");
        printf("\n 4.DISPLAY");
        printf("\n 5.EXIT");
        printf("\n Enter your option: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
            printf("\n Enter number to be pushed: ");
            scanf("%d",&val);
            top= push(top,val);
            break;

            case 2:
            top=pop(top);
            if(val!=-1)
            printf("\n The value deleted is: %d",val);
            break;

            case 3:
            val=peek(top);
            if(val!=-1)
            printf("\n The value stored at top is %d",val);
            break;

            case 4:
            top=disp(top);
            break;

        }
    }while(opt!=5);
    return 0;
}

struct stack *push(struct stack *top,int val){
    struct stack *temp;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=val;
    if(top==NULL){
        temp->next=NULL;
        top=temp;
    }
    else{
        temp->next=top;
        top=temp;
    }
    return top;
}

struct stack *pop(struct stack *top){
    struct stack *temp;
    temp=top;
    if(top==NULL){
        printf("\n Stack underflow");
    }
    else{
        top=top->next;
        printf("\n The value being deleted is %d",temp->data);
        free(temp);
    }
    return top;
}

struct stack *disp(struct stack *top){
    struct stack *temp;
    temp=top;
    if(top==NULL)
    printf("\n Stack is empty");
    else{
        while(temp!=NULL){
            printf("\n %d \n",temp->data);
            temp=temp->next;
        }
    }
    return top;
}

int peek(struct stack *top){
    if(top==NULL)
    return -1;
    else 
    return top->data;
}