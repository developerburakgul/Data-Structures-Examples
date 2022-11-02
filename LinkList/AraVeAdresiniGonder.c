#include <stdio.h>
#include <stdlib.h>
#include "SiraliLinkList.h"

// tek yönlü bağlantılı liste üzerinde arama yap eğer varsa önceki node un adresini döndür yoksa NULL döndür

node* find(node *dugum,int data){
    node *iter=dugum;
    while (iter->next!=NULL)
    {
        if (iter->next->data==data)
        {
            return iter;
        }
        iter=iter->next;
    }
    return NULL;
    
}

int main(){
    node*liste=NULL;
    for (int i = 0; i < 10; i++)
    {
        liste=addToList(i*7,liste);
    }
    printList(liste);
    printf("\n");
    node *bulunanınoncesi=find(liste,28);
    printf(" bulunanın öncesindeki data : %d",bulunanınoncesi->data);
}


