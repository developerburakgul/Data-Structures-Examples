#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// arada yorum satıları vardır debug için yazdım onları
typedef struct node
{
    int data;
    int balance;
    int height;
    struct node *left;
    struct node *right;

} NODE;

typedef struct
{
    int count;
    NODE *root;

} AVL;

NODE *CreateNode(int data)
{
    NODE *tmp = (NODE *)malloc(sizeof(NODE));
    tmp->data = data;
    tmp->balance = 0;
    tmp->height = -1;
    tmp->right = NULL;
    tmp->left = NULL;
    return tmp;
}

AVL *CreteAVL()
{
    AVL *tmp = (AVL *)malloc(sizeof(AVL));
    tmp->count = 0;
    tmp->root = NULL;
    return tmp;
}

int _max(NODE *root)
{
    NODE *iter = root;
    while (iter != NULL)
    {
        iter = iter->right;
    }
    return iter->data;
}

int _min(NODE *root)
{
    NODE *iter = root;
    while (iter != NULL)
    {
        iter = iter->left;
    }
    return iter->data;
}

int MaxValue(number1, number2)
{
    if (number1 < number2)
    {
        return number2;
    }
    else if (number1 > number2)
    {
        return number1;
    }
    else
    {
        // printf(" 2 sayi degeri de aynidir  number 1 : %d number 2 : %d \n",number1,number2);
        return number1;
    }
}

int _height(NODE *root)
{

    if (root != NULL)
    {
        int leftHeight = _height(root->left);
        int rightHeight = _height(root->right);

        return MaxValue(leftHeight, rightHeight) + 1;
    }
    else
    {
        return -1;
    }
}

int _getBalance(NODE *root)
{
    if (root != NULL)
    {
        return _height(root->left) - _height(root->right);
    }
    else
    {
        return 0;
    }
}

NODE *_rotateRight(NODE *root)
{
    NODE *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}

NODE *_rotateLeft(NODE *root)
{
    NODE *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}

NODE *_leftRightRotate(NODE *root)
{
    root->left = _rotateLeft(root->left);
    return _rotateRight(root);
}

NODE *_rightLeftRotate(NODE *root)
{
    root->right = _rotateRight(root->right);
    return _rotateLeft(root);
}

NODE *_insert(NODE *root, int data)
{

    if (root != NULL)
    {
        // aşağıdaki if else bloğunda veriyi ekliyor rekürsif fonk ile
        if (data < root->data)
        {
            root->left = _insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = _insert(root->right, data);
        }
        else
        {
            printf("ayni sayi girdiniz ekleme yapilamaz \n");
        }
        // ekledik fakat bu dengeyi bozdu mu bozmadı mı emin değiliz bu yüzden üstteki if else bloğunda return etmedik
        // şimdi aşağıda denge olaylarını kontrol ettikten sonra return edeceğiz
        // denge olaylarını kontrol edebilmek için ağaca ekledik ve bu ağacın verilerini yeniden düzenlemek gerek
        // çünkü her eleman eklediğimizde yükseklik ve balance degeri değişmektedir

        root->height = _height(root);
        root->balance = _getBalance(root);

        if (root->balance > 1) // yani agacın sol tarafı daha yüksekse
        {
            if (data < root->left->data)
            {
                root = _rotateRight(root);
                root->height = _height(root);
                root->balance = _getBalance(root);
            }
            else if (data > root->left->data)
            {
                root = _leftRightRotate(root);
                root->height = _height(root);
                root->balance = _getBalance(root);
            }
            else
            {
                printf("ayni sayilar girilemezz \n");
            }

            // printf("agacin sol tarafi yuksekdi dengelendi \n");
        }
        else if (root->balance < -1) // yani ağacın sağ tarafı daha yüksekse
        {
            if (data > root->right->data)
            {
                root = _rotateLeft(root);
                root->height = _height(root);
                root->balance = _getBalance(root);
            }
            else if (data < root->right->data)
            {
                root = _rightLeftRotate(root);
                root->height = _height(root);
                root->balance = _getBalance(root);
            }
            else
            {
                printf("ayni sayilar girilemezzz \n");
            }

            // printf("agacin sag tarafi yuksekdi dengelendi \n");
        }
        else // agacın dengede (balance) da olduğu durumdur
        {
            // printf("agac dengelidir rotate islemlerine gerek yok \n");
        }
    }
    else
    {
        root = CreateNode(data);
    }
    return root;
}

bool insert(AVL *avl, int data)
{
    if (avl != NULL)
    {
        if (avl->root != NULL)
        {
            avl->root = _insert(avl->root, data);
            avl->count++;
            return true;
        }
        else
        {
            // printf("agac var ama eleman yok \n");
            avl->root = _insert(avl->root, data);
            avl->count++;
            // printf("agaca eleman eklendi \n");
            return true;
        }
    }
    else
    {
        printf("agac olusmamis \n");
        return false;
    }
}

void _preorderTraverse(NODE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        _preorderTraverse(root->left);
        _preorderTraverse(root->right);
    }
    else
    {
        return;
    }
}

void preorderTraverse(AVL *avl)
{
    if (avl->root != NULL)
    {
        _preorderTraverse(avl->root);
    }
    else
    {
        printf("agac yok \n");
    }
}

NODE *_delete(NODE *root, int data)
{
    // printf("1 \n");

    if (root != NULL)
    {
        // printf("2 \n");

        if (root->data == data) // aranan veri bulundu silme işlemi yaoılacak
        {
            // printf("3 \n");

            if (root->right == NULL && root->left == NULL) // silinecek data bir leafdir yapraktır
            {
                // printf("4 \n");
                free(root);
                root = NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                // printf("5 \n");
                NODE *temp = root->left;
                free(root);
                root = temp;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                // printf("6 \n");
                NODE *temp = root->right;
                free(root);
                root = temp;
            }
            else
            {
                // printf("7 \n");
                root->data = _max(root->left);
                root->left = _delete(root->left, root->data);
            }
            // printf("8 \n");

            return root;
        }
        else
        {
            // printf("9 \n");
            if (data < root->data) // aranan veri sol alt ağaçta ise
            {
                // printf("10 \n");
                root->left = _delete(root->left, data);
            }
            else // aranan veri sağ alt ağaçta ise
            {
                // printf("11 \n");
                root->right = _delete(root->right, data);
            }

            // printf("12 \n");
        }
        // root un verilerini güncelle
        root->height = _height(root);
        root->balance = _getBalance(root);

        if (root->balance > 1) // sol taraf daha uzun demektir
        {
            // printf("13 \n");
            if (root->left->balance >= 0)
            {
                // printf("14 \n");
                root = _rotateRight(root);
            }
            else
            {
                // printf("15 \n");
                root = _leftRightRotate(root);
            }
            // printf("16 \n");
        }
        else if (root->balance < -1) // sağ taraf daha uzun demektir
        {
            // printf("17 \n");
            if (root->right->balance <= 0)
            {
                // printf("18 \n");
                root = _rotateLeft(root);
            }
            else
            {
                // printf("19 \n");
                root = _rightLeftRotate(root);
            }
            // printf("20 \n");
        }
        else // balance dengelidir
        {
            // printf("21 \n");
            printf("agac dengelidir \n");
        }
        root->height = _height(root);
        root->balance = _getBalance(root);
        // printf("22 \n");
        return root;
    }
    else
    {
        // printf("23 \n");
        return root;
    }
}

bool Delete(AVL *avl, int data)
{
    if (avl->root != NULL)
    {
        avl->root = _delete(avl->root, data);
        avl->count--;
        return true;
    }
    else
    {
        printf("bos agac \n");
        return false;
    }
}
int main()
{

    AVL *avl = CreteAVL();

    for (size_t i = 0; i < 10; i++)
    {
        insert(avl, i);
    }

    preorderTraverse(avl);
    printf("\n\n");
    printf("dugum sayisi : %d  balance degeri : %d  yuksekligi %d \n\n", avl->count, avl->root->balance, avl->root->height);

    Delete(avl, 0);
    preorderTraverse(avl);
    printf("\n\n");
    printf("dugum sayisi : %d  balance degeri : %d  yuksekligi %d \n\n", avl->count, avl->root->balance, avl->root->height);

    Delete(avl, 2);
    preorderTraverse(avl);
    printf("\n");
    printf("dugum sayisi : %d  balance degeri : %d  yuksekligi %d \n\n", avl->count, avl->root->balance, avl->root->height);

    return 0;
}