#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *next;
} node;

node *ekle(int data, node *dizi)
{
    node *root = dizi;
    node *iter = dizi;

    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->next = NULL;
        return root;
    }

    while (iter->next != NULL)
    {

        if (iter->data == data)
        {
            return root;
        }

        iter = iter->next;
    }
    if (iter->data == data)
    {
        return root;
    }

    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    iter->next = temp;
    return root;
}

void yazdir(node *dizi)
{
    node *iter = dizi;
    if (dizi == NULL)
    {
        printf("Liste bos");
    }
    else
    {
        while (iter->next != NULL)
        {
            printf("%d ", iter->data);
            iter = iter->next;
        }
        printf("%d ", iter->data);
    }
}

int main()
{
    node *dizi = NULL;
    for (size_t i = 0; i < 15; i++)
    {
        dizi=ekle(i*3,dizi);
    }
    

    yazdir(dizi);
    printf("\n");
    dizi=ekle(3,dizi);
    yazdir(dizi);
}