#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct heap
{
    int size;
    int capacity;
    int tail;
    int *heapArray;

} HEAP;

HEAP *CreateHeap(int maxSize)
{
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    heap->capacity = maxSize;
    heap->size = 0;
    heap->tail = 1;

    heap->heapArray = (int *)malloc(sizeof(int) * (maxSize + 1));
    return heap;
}

void swap(int *number1, int *number2)
{
    int temp;
    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

void _reheapUp(HEAP *heap, int childLocation)
{
    int temp;
    int parentLocation = childLocation / 2;

    if (childLocation != 1)
    {
        if (heap->heapArray[childLocation] >= heap->heapArray[parentLocation])
        {
            // swap(&heap->heapArray[parentLocation],&heap->heapArray[childLocation]); aşağıdaki aynı işi yapar

            temp = heap->heapArray[parentLocation];
            heap->heapArray[parentLocation] = heap->heapArray[childLocation];
            heap->heapArray[childLocation] = temp;
        }

        _reheapUp(heap, parentLocation);
    }
}

bool insertToMaxHeap(HEAP *heap, int data)
{

    if (heap->size < heap->capacity)
    {
        heap->heapArray[heap->tail] = data;

        _reheapUp(heap, heap->tail);
        heap->size++;
        heap->tail++;
        return true;
    }
    else
    {
        printf("heap dolu \n");
        return false;
    }
}

void _reheapDown(HEAP *heap, int indis)
{
    if (2 * indis + 1 < heap->tail)
    {
        if (heap->heapArray[2 * indis + 1] > heap->heapArray[2 * indis])
        {
            swap(&heap->heapArray[2 * indis + 1], &heap->heapArray[indis]);
            _reheapDown(heap, 2 * indis + 1);
        }
        else
        {
            swap(&heap->heapArray[2 * indis], &heap->heapArray[indis]);
            _reheapDown(heap, 2 * indis);
        }
    }
}

bool Delete(HEAP *heap)
{

    if (heap->size != 0)
    {
        heap->heapArray[1] = heap->heapArray[heap->tail - 1];
        heap->heapArray[heap->tail - 1] = 0;

        _reheapDown(heap, 1);
        heap->size--;
        heap->tail = heap->tail - 1;

        return true;
    }
    else
    {
        return false;
    }
}

int peek(HEAP *heap)
{
    if (heap->size != 0)
    {

        int returnValue = heap->heapArray[1];
        return returnValue;
    }
}

void printHeap(HEAP *heap)
{
    printf("heap : ");
    for (size_t i = 1; i < heap->size + 1; i++)
    {
        printf("%d ", heap->heapArray[i]);
    }
    printf("\nheap boyut : %d dir \n", heap->size);
}

int main()
{

    HEAP *heap = CreateHeap(10);

    srand(13);

    int dizi[10];
    for (size_t i = 0; i < 10; i++)
    {
        dizi[i] = rand() % 100;
    }
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", dizi[i]);
    }
    printf("\n\n");

    for (size_t i = 0; i < 10; i++)
    {
        insertToMaxHeap(heap, dizi[i]);
    }

    printHeap(heap);

    Delete(heap);
    printf("\n\n");
    printHeap(heap);
    printf("\n %d ", peek(heap));

    return 0;
}
