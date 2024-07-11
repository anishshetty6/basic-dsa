#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
}

void pre(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        pre(root->left);
        pre(root->right);
    }
}

void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void post(struct node *root){
    if(root!=NULL){
        post(root->left);
        post(root->right);
        printf("%d ",root->data);
    }
}

struct node * search(struct node *root,int key){
    while(root!=NULL){
        if(key==root->data)
        return root;
    
        else if(key<root->data)
        root=root->left;
    
        else
        root=root->right;
    
    }  
    return NULL;
}

void insert(struct node* root,int key){
    struct node *prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("cannot insert");
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node *new=create(key);
    if(key<prev->data)
    prev->left=new;
    else
    prev->right=new;
}

struct node *inPre(struct node *root){
    root=root->left;
    while(root->right!=NULL)
    root=root->right;
    return root;
}

struct node *del(struct node *root,int val){
    struct node *iPre;
    if(root==NULL)
    return NULL;
    
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }

    if(val>root->data){
        root->right=del(root->right,val);
    }

    else if(val<root->left){
        root->left=del(root->left,val);
    }

    else{
        iPre=inPre(root);
        root->data=iPre->data;
        root->left=del(root->left,iPre->data);
    }
    return root;
}

int main(){

    struct node *p=create(5);
    struct node *p1=create(3);
    struct node *p2=create(6);
    struct node *p3=create(1);
    struct node *p4=create(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inOrder(p);
    printf("\n");
    pre(p);
    printf("\n");
    post(p);
    printf("\n");
    
}