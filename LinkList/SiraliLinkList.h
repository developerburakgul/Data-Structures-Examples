#ifndef SiraliLinkList
#define SiraliLinkList
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int data;
    struct n *next;
}node;

node* addToList(int data,node*dugum){
    node *root = dugum;
    node *iter = dugum;
    if (dugum==NULL)
    {
        
        node* liste=(node*)malloc(sizeof(node));
        liste->data=data;
        liste->next=NULL;
        dugum=liste;
        return dugum;
        

    }else
    {
        if (data>root->data)
        {
            node *temp=(node*)malloc(sizeof(node));
            temp->data=data;
            temp->next=root;
            root=temp;
            iter=temp;
            return root;

        }else
        {
            while (iter->next!=NULL && data<iter->next->data)
            {
                iter=iter->next;
            }
            node *temp=(node*)malloc(sizeof(node));
            temp->data=data;
            temp->next=iter->next;
            iter->next=temp;
            return root;

            
            
        }
        
        
        
        
    }
    

    
    




}

void printList(node *dugum){
    node *iter=dugum;
    if (iter==NULL)
    {
        printf("Liste Bos");
    }else
    {
        while (iter->next!=NULL)
        {
            printf("%d->",iter->data);
            iter=iter->next;
        }
        printf("%d",iter->data);
        
        
    }
}    

#endif