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

} TreeNode;

TreeNode *CreateTreeNode()
{
    TreeNode *tree = NULL;
    return tree;
}

bool insert(TreeNode **rootPtr, int data)
{
    TreeNode *root = *rootPtr;

    if (root == NULL)
    {
        TreeNode *tree = (TreeNode *)malloc(sizeof(TreeNode));
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
        (*rootPtr) = tree;
        return tree;
    }
    else if (data < root->data)
    {
        insert(&(root->left), data);
        return true;
    }
    else if (data > root->data)
    {
        insert(&(root->right), data);
        return true;
    }
    else
    {
        return false;
    }
}

void preorder(TreeNode *tree)
{

    if (tree != NULL)
    {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder1(TreeNode *tree)
{
    if (tree != NULL)
    {
        inorder1(tree->left);
        printf("%d ", tree->data);
        inorder1(tree->right);
    }
}

void inorder2(TreeNode *tree)
{
    if (tree != NULL)
    {
        inorder2(tree->right);
        printf("%d ", tree->data);
        inorder2(tree->left);
    }
}

void postorder(TreeNode *tree)
{
    if (tree != NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->data);
    }
}

int main()
{
    srand(time(0));

    TreeNode *tree = CreateTreeNode();
    for (size_t i = 0; i < 10; i++)
    {
        int data = rand() % 100;
        bool sonuc = insert(&tree, data);
        printf("%d \n", data);
    }

    postorder(tree);

    return 0;
}