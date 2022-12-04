#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef struct node
{
    char data;
    struct node *next;

}Node;


typedef struct stack
{
    Node *top;
    int counter;
    
}STACK;

    bool isEmpty(STACK* stack){
            return stack->counter == 0;
        }

    char Top(STACK* stack){
            if(isEmpty(stack)){
                printf("Stack is empty");
                return -1;
            }else
            {
                return stack->top->data;
            }
            
        }

    void Push(STACK* stack,char data){
        if (isEmpty(stack))
        {
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->data = data;
            newNode->next = NULL;
            stack->top = newNode;
            stack->counter++;

        }else
        {
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->data = data;
            newNode->next = stack->top;
            stack->top = newNode;
             stack->counter++;
        }
        
        
    }

    char Pop(STACK* stack){
        if (isEmpty(stack))
        {
            printf("Stack is empty");
            return -1;
        }else
        {
            Node *temp = stack->top;
            char data = temp->data;
            stack->top = temp->next;
            free(temp);
            stack->counter--;
            return data;
        }
        
    }

    bool isParanthesis(char c){
        if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')
        {
            return true;
        }else
        {
            return false;
        }
        
    }

    bool isMatchingPair(char character1, char character2){
        if (character1 == '(' && character2 == ')')
        {
            return true;
        }else if (character1 == '{' && character2 == '}')
        {
            return true;
        }else if (character1 == '[' && character2 == ']')
        {
            return true;
        }else
        {
            return false;
        }
        
    }

    void initialize(STACK *stack){
        stack->counter=0;
        stack->top=NULL;
    }




    bool isBalanced(char* array){
        STACK* stack=(STACK*)malloc(sizeof(stack));
        initialize(stack);

        for (size_t i = 0; i < strlen(array); i++)
        {
            if (isParanthesis(array[i]))
            {
                if (isEmpty(stack))
                {
                    Push(stack,array[i]);
                }else
                {
                    if (isMatchingPair(stack->top->data,array[i]))
                    {
                        Pop(stack);
                    }else
                    {
                        Push(stack,array[i]);
                    }
                    
                    
                }
                
                
            }
            
        }

        if (isEmpty(stack))
        {
            printf("parantezler dengelidir \n");
        }else
        {
            printf("parantezler dengeli degildir \n");
        }
        
        
        
    }














int main(){

  
    char array[] = "if (isEmpty(stack)){printf(parantezler dengelidir \n);}else {printf(parantezler dengeli degildir \n);}";

    
    isBalanced(array);


    
    



    return 0 ;
}