#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 10
char stack[10];
int top = -1;
int isOp(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 1;
    else
        return 0;
}
int priority(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 3;
    else
        return 0;
}
int isEmp()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
void push(char data)
{
    stack[++top] = data;
}
char pop()
{
    return stack[top--];
}
char peek()
{
    return stack[top];
}

int main()
{
    char infix[10];
    char postfix[10];
    char x, y;
    int n, j = 0, int1, int2, res;
    printf("Enter infix: ");
    gets(infix);
    n = strlen(infix);
    for (int i = 0; i < n; i++)
    {
        x = infix[i];
        if (isOp(x))
        {
            while (priority(x) < priority(peek()))
            {
                postfix[j] = pop();
                j++;
            }
            push(x);
        }
        else if (isalpha(x))
        {
            postfix[j] = x;
            j++;
        }
        else if (x == '(')
        {
            push(x);
        }
        else if (x == ')')
        {
            while (peek() != '(')
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        }
    }
    while (!isEmp())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    puts(postfix);

    int m = strlen(postfix);
    for (int i = 0; i < m; i++)
    {
        x = postfix[i];
        if (isalpha(x))
        {
            printf("]n Enter value of %c: ", x);
            scanf("%d", &int1);
            push(int1);
        }
        if (isOp(x))
        {
            int1 = (int)pop();
            int2 = (int)pop();
            switch (x)
            {
            case '+':
                res = int1 + int2;
                push(res);
                break;
            case '-':
                res = int2 - int1;
                push(res);
                break;
            case '*':
                res = int1 * int2;
                push(res);
                break;
            case '/':
                res = int2 / int1;
                push(res);
                break;
            default:
                break;
            }
        }
    }
    res = pop();
    printf("RESULT: %d", res);
}