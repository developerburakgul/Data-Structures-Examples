#include <stdio.h>
#include <stdlib.h>
#include "BankaOrnegi.h"

int main(){


    insan* dizi=NULL;

    dizi=kisiEkle("Meryem","Gül",1,dizi);
    dizi=kisiEkle("Burak","Gül",1,dizi);
    listeyiYazdir(dizi);

    printf("\n\n\n");
    dizi=kisiEkle("Batuhan","Gül",0,dizi);
    listeyiYazdir(dizi);
    dizi=kisiCagir(dizi);
    printf("\n liste \n");
    listeyiYazdir(dizi);
    return 0 ;
}
