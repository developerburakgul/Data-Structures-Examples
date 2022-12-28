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
    int min;
    int max;

} BST;

BST *CreateBST()
{
    BST *bst = (BST *)malloc(sizeof(BST));
    bst->count = 0;
    bst->root = NULL;
    return bst;
}

NODE *CreateNode(int data)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

NODE *_insert(NODE *root, NODE *newNode)
{
    if (root == NULL)
    {

        return newNode;
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
        printf("ayni sayi eklenemez \n");
        return root;
    }
}

void Insert(BST *bst, int data)
{
    NODE *node = CreateNode(data);
    if (bst->root == NULL)
    {
        bst->root = node;
        bst->count++;
        bst->min = data;
        bst->max = data;
        printf("%d agaca eklendi ,agacin eleman sayisi %d ,min %d max %d \n", data, bst->count, bst->min, bst->max);
        return;
    }
    else
    {
        bst->root = _insert(bst->root, node);
        bst->count++;
        if (data < bst->min)
        {
            bst->min = data;
        }
        if (data > bst->max)
        {
            bst->max = data;
        }
        printf("%d agaca eklendi ,agacin eleman sayisi %d ,min %d max %d \n", data, bst->count, bst->min, bst->max);
        return;
    }
}

void _printInorder(NODE *root)
{
    if (root == NULL)
    {
        return;
    }
    _printInorder(root->left);
    printf("%d ", root->data);
    _printInorder(root->right);
}

void _printInorder2(NODE *root)
{
    if (root == NULL)
    {
        return;
    }
    _printInorder2(root->right);
    printf("%d ", root->data);
    _printInorder2(root->left);
}

void _printPreorder(NODE *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    _printPreorder(root->left);
    _printPreorder(root->right);
}

void _printPostorder(NODE *root)
{
    if (root == NULL)
    {
        return;
    }
    _printPostorder(root->left);
    _printPostorder(root->right);
    printf("%d ", root->data);
}

void TraverseBST(BST *bst)
{
    if (bst == NULL)
    {
        printf("agac bos \n");
        return;
    }
    printf("inorder : ");
    _printInorder(bst->root);
    printf("\n");

    printf("inorder2 : ");
    _printInorder2(bst->root);
    printf("\n");

    printf("preorder : ");
    _printPreorder(bst->root);
    printf("\n");

    printf("postorder : ");
    _printPostorder(bst->root);
    printf("\n");
}

NODE *_search(NODE *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        return root;
    }
    else if (root->data > data)
    {
        return _search(root->left, data);
    }
    else
    {
        return _search(root->right, data);
    }
}

NODE *Search(BST *bst, int data)
{
    if (bst->root == NULL)
    {
        printf("agac bos \n");
        return NULL;
    }
    return _search(bst->root, data);
}

int _max(NODE *root)
{
    NODE *iter = root;
    while (iter->right != NULL)
    {
        iter = iter->right;
    }
    return iter->data;
}

int _min(NODE *root)
{
    NODE *iter = root;
    while (iter->left != NULL)
    {
        iter = iter->left;
    }
    return iter->data;
}

NODE *_delete(NODE *root, int data)
{

    if (root != NULL)
    {
        if (root->data == data) // aranan değer bulunduysa
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                root->data = _max(root->left);
                root->left = _delete(root->left, _max(root->left));
                return root;
            }
            else if (root->right != NULL && root->left == NULL)
            {
                root->data = _min(root->right);
                root->right = _delete(root->right, _min(root->right));
                return root;
            }
            else
            {
                root->data = _max(root->left);
                root->left = _delete(root->left, _max(root->left));
                return root;
            }
        }
        else if (root->data < data) // aranan değer sağ taraftaysa
        {
            root->right = _delete(root->right, data);
            return root;
        }
        else if (root->data > data) // aranan değer sol taraftaysa
        {
            root->left = _delete(root->left, data);
            return root;
        }
        else // aranan değer yoksa
        {
            printf("aranan deger bulunamadi \n");
            return NULL;
        }
    }
    else
    {
        printf(" dugum bos  \n");
        return NULL;
    }
}

bool Delete(BST *bst, int data)
{
    if (bst->root != NULL)
    {
        bst->root = _delete(bst->root, data);
        return true;
    }
    else
    {
        printf("agac bos \n");
        return false;
    }
}

void _destroy(BST *bst, NODE *root)
{
    if (root != NULL)
    {
        _destroy(bst, root->left);
        _destroy(bst, root->right);
        free(root);
        bst->count--;
    }
    else
    {
        return;
    }
}

BST *DestroyBST(BST *bst)
{

    if (bst != NULL)
    {
        _destroy(bst, bst->root);
        free(bst);
        return NULL;
    }
    else
    {
        printf(" agac bos \n");
        return bst;
    }
}

/*
İTERATİVE ŞEKİLDE EKLEME
void Insert(BST* bst,int data)
{
    NODE* node=CreateNode(data);
    if(bst->root==NULL)
    {
        bst->root=node;
        bst->count++;
        return;
    }
    NODE* temp=bst->root;
    while(true)
    {
        if(data<temp->data)
        {
            if(temp->left==NULL)
            {
                temp->left=node;
                bst->count++;
                return;
            }
            temp=temp->left;
        }
        else
        {
            if(temp->right==NULL)
            {
                temp->right=node;
                bst->count++;
                return;
            }
            temp=temp->right;
        }
    }
}

*/

int main()
{
    BST *bst = CreateBST();
    srand(1);
    for (size_t i = 0; i < 10; i++)
    {
        int rastgele = rand() % 100;
        Insert(bst, rastgele);
    }
    TraverseBST(bst);
    printf(" \n %d ", Delete(bst, 78));
    TraverseBST(bst);
    bst = DestroyBST(bst);
    DestroyBST(bst);

    return 0;
}