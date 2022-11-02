#include <stdio.h>
#include <stdlib.h>
#include "SiraliLinkList.h"
// elemanları sıralı olan iki bağlantılı listeyi birleştiren birlestir(liste1,liste2) fonksiyonunu yazınız.
// bağlantılı listeler tek yönlüdür,birleştirme sonucu liste1 de toplanacaktır düğümlerin hepsi
void birlestir(node *liste1,node *liste2){
    node *endOfListe1=liste1;
    while (endOfListe1->next!=NULL)
    {
        endOfListe1=endOfListe1->next;
    }
    endOfListe1->next=liste2;
    free(liste2);
}

void birlestir2(node *liste1,node *liste2){
    node*iter=liste2;
    while (iter->next!=NULL)
    {
        liste1=addToList(iter->data,liste1);
        iter=iter->next;
    }
    
    
}

int main(){


    node *liste1=NULL;
    node *liste2=NULL;
    for (size_t i = 0; i < 10; i++)
    {
        liste1=addToList(i*7,liste1);
        liste2=addToList(i*11,liste2);
    }
    printf("Liste1:");
    printList(liste1);
    printf("\n");
    printf("Liste2:");
    printList(liste2);

    // birlestir(liste1,liste2);
    // printf("\n");
    // printf("Liste1:");
    // printList(liste1);

    birlestir2(liste1,liste2);
    printf("\n");
    printf("Liste1:");
    printList(liste1);

}