#include <stdio.h>
#include <stdlib.h>
#include "BankaOrnegi.h"


int main(){


    insan* dizi=NULL;
    
    dizi=kisiEkle("Betül","Köse",1,dizi);
    dizi=kisiEkle("Burak","Gül",1,dizi);
    dizi=kisiEkle("Batuhan","Gül",1,dizi);
    dizi=kisiEkle("Batuhan","Köse",0,dizi);

    listeyiYazdir(dizi);
    dizi=kisiCagir(dizi);
    dizi=kisiCagir(dizi);
    dizi=kisiCagir(dizi);
    dizi=kisiCagir(dizi);


    



    
    






    return 0 ;
}