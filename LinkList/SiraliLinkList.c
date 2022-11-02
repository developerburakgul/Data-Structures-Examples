#include <stdio.h>
#include <stdlib.h>
#include "SiraliLinkList.h"
// elemanları büyükten küçüğe doğru sıralı olacak şekilde bağlı listeye eleman ekleme fonksiyonunu yazınız.
   
    

int main(){



    node*liste=NULL;
    liste=addToList(5,liste);
    liste=addToList(10,liste);
    liste=addToList(15,liste);
    liste=addToList(12,liste);
    printList(liste);

}
