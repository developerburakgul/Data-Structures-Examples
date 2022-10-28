#ifndef BankaOrnegi
#define BankaOrnegi

typedef struct n
{
    char* isim;
    char* soyisim;
    int oncelikNumarasi;
    int giseNumarasi;
    struct n* next;

}insan;

insan* kisiEkle(char*ad,char*soyad,int oncelik,insan*dizi){
    insan*root=dizi;
    insan*iter=dizi;

    if (dizi==NULL)
    {   
        
        dizi=(insan*)malloc(sizeof(insan));
        dizi->isim=ad;
        dizi->soyisim=soyad;
        dizi->oncelikNumarasi=oncelik;
        dizi->giseNumarasi=1;


        dizi->next=NULL;
        
        return dizi;
    }else
    {
        if (oncelik<iter->oncelikNumarasi)
        {
            insan*temp=(insan*)malloc(sizeof(insan));
            temp->isim=ad;
            temp->soyisim=soyad;
            temp->oncelikNumarasi=oncelik;
            temp->giseNumarasi=1;
            temp->next=dizi;
            dizi->next=NULL;
            dizi=temp;
            root=dizi;
            iter->giseNumarasi=2;
            iter=root;
            return dizi;

        }else
        {
            while (oncelik>=iter->oncelikNumarasi && iter->next!=NULL)
            {
                iter=iter->next;
            }
            insan*temp=(insan*)malloc(sizeof(insan));
            temp->isim=ad;
            temp->soyisim=soyad;
            temp->oncelikNumarasi=oncelik;
            temp->giseNumarasi=iter->giseNumarasi+1;
            temp->next=NULL;
            iter->next=temp;
            return root;
        }
        
        
        

        
        
        
    }
    
    





}

insan* kisiCagir(insan*dizi){
    insan*temp=dizi;
    if (dizi==NULL)
    {
        printf("Tüm kişiler çağrılmıştır \n");
        return NULL;
    }
    printf("Çağırılan kişi: %s %s Gişe numarası : %d \n",dizi->isim,dizi->soyisim,dizi->giseNumarasi);
    dizi=dizi->next;
    free(temp);
    return dizi;
    
}

void kisiyiYazdir(insan*person){

    
    
    printf("İsim: %s \nSoyisim: %s \nÖncelik Numarası: %d \nGise Numarası: %d \n",person->isim,person->soyisim,person->oncelikNumarasi,person->giseNumarasi);
        
       


}

void listeyiYazdir(insan*dizi){
    
    insan*iter=dizi;
    while (iter!=NULL)
    {
        kisiyiYazdir(iter);
        printf("\n");
        iter=iter->next;
    }
    
    
    
    
}


#endif
