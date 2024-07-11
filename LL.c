#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create(struct node *);
struct node *disp(struct node *);
struct node *insert_end(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_bef(struct node *);
struct node *insert_af(struct node *);
struct node *del_last(struct node *);
struct node *del_mid(struct node *);
struct node *del_beg(struct node *);
int main()
{
}

struct node *create(struct node *start)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n\t Enter -1 to end.");
    printf("\n\t Enter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        if (start == NULL)
        {
            newNode->next = NULL;
            start = newNode;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
                ptr->next = newNode;
            }
        }
        printf("\n\tEnter data: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *disp(struct node *start)
{
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("\n\t%d", temp->data);
        temp = temp->next;
    }
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *temp, *newNode;
    int num;
    printf("\n\t Enter data: ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("Unable to create memory");
    else
    {
        newNode->data = num;
        newNode->next = NULL;
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *temp, *newNode;
    int num;
    printf("\n\t Enter data: ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("Unable to create memory");
    else
    {
        newNode->data = num;
        newNode->next = start;
        start = newNode;
    }
    return start;
}

struct node *insert_bef(struct node *start)
{
    struct node *temp1, *temp2, *newNode;
    int num, val;
    printf("\n\tEnter value to be entered: ");
    scanf("%d", &num);
    printf("\n\tEnter the element before which the value is to inserted: ");
    scanf("%d", &val);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    temp1 = start;
    temp2 = temp1->next;
    while (temp2->data != val)
    {
        temp1 = temp2;
        temp2 = temp1->next;
    }
    newNode->next = temp2;
    temp1->next = newNode;
    return start;
}

struct node *insert_af(struct node *start)
{
    struct node *temp, *newNode;
    int val, num;
    printf("\n\tEnter value to be entered: ");
    scanf("%d", &num);
    printf("\n\tEnter the element after which the value is to be inserted: ");
    scanf("%d", &val);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    temp = start;
    while (temp->data != val)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    return start;
}

struct node *del_last(struct node *start)
{
    struct node *temp1, *temp2;
    temp1 = start;
    temp2 = temp1->next;
    while (temp2->next != NULL)
    {
        temp1 = temp2;
        temp2 = temp1->next;
    }
    temp1->next = NULL;
    return start;
}

struct node *del_mid(struct node *start)
{
    struct node *temp1, *temp2;
    int val;
    printf("\n\tEnter element to be deleted: ");
    scanf("%d", &val);
    temp1 = start;
    temp2 = temp1->next;
    while (temp2->data != val)
    {
        temp1 = temp2;
        temp2 = temp1->next;
    }
    temp1->next = temp2->next;
    return start;
}

struct node *del_beg(struct node *start)
{
    struct node *temp;
    temp = start;
    start = start->next;
    free(temp);
    return start;
}
