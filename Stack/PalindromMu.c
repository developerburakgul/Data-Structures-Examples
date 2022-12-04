#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} Node;

typedef struct stack
{
    int counter;
    Node *top;
} STACK;

void initializeStack(STACK *stack)
{
    stack->counter = 0;
    stack->top = NULL;
}

bool isEmptyStack(STACK *stack)
{
    return stack->counter == 0;
}

char Top(STACK *stack)
{
    if (isEmptyStack(stack))
    {
        printf("Stack is empty");
        return '\0';
    }
    else
    {
        return stack->top->data;
    }
}

void Push(STACK *stack, char data)
{
    if (isEmptyStack(stack))
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        stack->top = newNode;
        stack->counter++;
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = stack->top;
        stack->top = newNode;
        stack->counter++;
    }
}

char Pop(STACK *stack)
{
    if (isEmptyStack(stack))
    {
        printf("Stack is empty");
        return '\0';
    }
    else
    {
        Node *temp = stack->top;
        char data = temp->data;
        stack->top = stack->top->next;
        free(temp);
        stack->counter--;
        return data;
    }
}

typedef struct que
{
    int counter;
    Node *front;
    Node *rear;

} QUE;

void initializeQue(QUE *que)
{
    que->counter = 0;
    que->front = NULL;
    que->rear = NULL;
}

bool isEmptyQue(QUE *que)
{
    return que->counter == 0;
}

void Enque(QUE *que, char data)
{

    if (isEmptyQue(que))
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        que->front = newNode;
        que->rear = newNode;
        que->counter++;
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        que->rear->next = newNode;
        que->rear = newNode;
        que->counter++;
    }
}

char Deque(QUE *que)
{
    if (isEmptyQue(que))
    {
        printf("Queue is empty");

        return '\0';
    }
    else
    {
        Node *temp = que->front;
        char data = temp->data;
        que->front = que->front->next;
        free(temp);
        que->counter--;
        return data;
    }
}

bool isPalindrom(char *str)
{
    int lentgh = strlen(str);
    STACK *stack;
    stack = (STACK *)malloc(sizeof(STACK));
    initializeStack(stack);
    QUE *que;
    que = (QUE *)malloc(sizeof(QUE));
    initializeQue(que);

    for (size_t i = 0; i < lentgh; i++)
    {
        Push(stack, str[i]);
    }

    for (size_t i = 0; i < lentgh; i++)
    {
        Enque(que, Pop(stack));
    }

    char *temp;
    for (size_t i = 0; i < lentgh; i++)
    {
        temp[i] = Deque(que);
    }

    if (strcmp(str, temp) == 0)
    {
        printf(" bu dizi Palindromdur \n");
        return true;
    }
    else
    {
        printf(" bu dizi Palindrom degildir \n");
        return false;
    }
}

int main()
{

    // kullaıcıdan string al
    char *str;
    str = "kayak";

    printf("%s\n", str);
    printf("%d\n", isPalindrom(str));

    return 0;
}