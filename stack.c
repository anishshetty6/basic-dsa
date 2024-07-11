#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int st[MAX], top=-1;
void push(int st[], int val);
int pop();
int peek(int st[]);
void disp(int st[]);

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
            push(st,val);
            break;

            case 2:
            val=pop();
            if(val!=-1)
            printf("\n The value deleted is: %d",val);
            break;

            case 3:
            val=peek(st);
            if(val!=-1)
            printf("\n The value stored at top is %d",val);
            break;

            case 4:
            disp(st);
            break;

        }
    }while(opt!=5);
    return 0;
}

void push(int st[],int val){
    if(top==MAX-1)
    printf("\n STACK OVERFLOW");
    else{
        top++;
        st[top]=val;
    }
}

int pop(){
    int val;
    if(top==-1){
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else{
        val=st[top];
        top--;
        return val;
    }
}

void disp(int st[]){
    int i;
    if(top==-1)
    printf("\n Stack is empty!");
    else{
        for(i=top;i>=0;i--){
            printf("\n %d \n",st[i]);
        }
    }
}
int peek(int st[]){
    if(top==-1){
        printf("\n Stack is empty!");
        return -1;
    }
    else
    return (st[top]);
}
