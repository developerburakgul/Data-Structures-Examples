#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *next;
} node;

node* addToQue(int data, node *que)
{
    node *root = que;

    

    if (root == NULL)
    {
        printf("Que is empty\n");
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->next = NULL;
        return root;
    }else
    {
        node*temp=(node*)malloc(sizeof(node));
        temp->data=data;
        temp->next=root;
        root=temp;
        return root;
    }
    

}

int getFromQue(node*que){


    if (que==NULL)
    {
        printf("Que is emptyyyy\n");
        return -1;

    }else
    {
        node*temp=que;
        que=que->next;
        return temp->data;
        free(temp);

        
    }
    
    



}


void printQue(node *que)
{
    node* iter=que;
    while(iter->next!=NULL)
    {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }
    printf("%d -> ",iter->data);

}



int main(){

    node* dizi=NULL;
    getFromQue(dizi);
    for (size_t i = 0; i < 18; i++)
    {
        dizi=addToQue(i*10,dizi);
    }
    
    printQue(dizi);
    printf("\n");
    for (size_t i = 0; i < 18; i++)
    {
        printf("%d -> ",getFromQue(dizi));
    }
    return 0;








}
