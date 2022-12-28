#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

typedef struct Bst
{
    int count;
    NODE *root;

} BST;

BST *CreateBST()
{
    BST *bst = (BST *)malloc(sizeof(BST));
    bst->count = 0;
    bst->root = NULL;

    return bst;
}

NODE *_insert(NODE *root, NODE *newNode)
{
    if (root == NULL)
    {
        root = newNode;

        return root;
    }
    else if (root->data > newNode->data)
    {
        root->left = _insert(root->left, newNode);
        return root;
    }
    else if (root->data < newNode->data)
    {
        root->right = _insert(root->right, newNode);
        return root;
    }
    else
    {
        printf("ayni sayi eklenmeye calisiliyor \n");
        return root;
    }
}

void insert(BST *bst, int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (!newNode)
    {
        printf("bellek dolu");
    }
    else if (bst->root == NULL)
    {
        bst->root = newNode;
        (bst->count)++;
    }
    else
    {
        bst->root = _insert(bst->root, newNode);
        (bst->count)++;
    }
}

void *_retrieve(NODE *root, int data)
{

    if (root != NULL)
    {
        if (root->data == data)
        {
            return root;
        }
        else if (root->data < data)
        {
            return _retrieve(root->right, data);
        }
        else
        {
            return _retrieve(root->left, data);
        }
    }
    else
    {
        printf("%d agacta bulunamadi ", data);
        return NULL;
    }
}

void *Retrieve(BST *bst, int data)
{

    if (bst->root != NULL)
    {
        return _retrieve(bst->root, data);
    }
    else
    {
        return NULL;
    }
}

void _traverse(NODE *root)
{
    if (root != NULL)
    {
        _traverse(root->left);
        printf("%d ", root->data);
        _traverse(root->right);
    }

   
}

void Traverse(BST *bst)
{
    _traverse(bst->root);
}

void _destroy(NODE*root)
{
    if (root!=NULL)
    {
        _destroy(root->left);
        root->data=0;
        
        _destroy(root->right);
        
    
        free(root);

    }
    
}

void Destroy(BST*bst)
{
    _destroy(bst->root);
    
    printf("%p %d \n",bst->root->left,bst->count);
    _traverse(bst->root);
}

int main()
{
    BST *tree1 = CreateBST();
    insert(tree1, 100);
    insert(tree1, 75);
    insert(tree1, 150);
    insert(tree1, 50);
    insert(tree1, 80);
    insert(tree1, 125);
    insert(tree1, 175);
    insert(tree1, 25);
    insert(tree1, 55);
    insert(tree1, 77);
    insert(tree1, 85);
    insert(tree1, 120);
    insert(tree1, 130);
    insert(tree1, 170);
    insert(tree1, 180);

    printf(" tree 1 in dügüm sayisi = %d \n", tree1->count);
    Traverse(tree1);
    printf("\n");
    Destroy(tree1);

    



    return 0;
}