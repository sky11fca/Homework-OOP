#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cstdarg>
#include <cstdlib>

Sort::Sort(int nr, int min, int max): size(nr)
{
    int i;
    srand(time(NULL));
    for(i=0; i<size; i++)
    {
        this->arr[i]=rand()%(max-min+1)+min;
    }
}

Sort::Sort(int *init, int nr): size(nr)
{
    int i;
    for(i=0; i<size; i++)
    {
        this->arr[i]=init[i];
    }
}

Sort::Sort(int *init)
{
    size=0;
    int i=0;
    while(init[i])
    {
        this->arr[i]=init[i];
        size++;
        i++;
    }
}

Sort::Sort(int nr, ...): size(nr)
{
    va_list args;
    va_start(args, nr);
    for (int i=0; i<size; i++)
    {
        arr[i]=va_arg(args, int);
    }
    va_end(args);
}

Sort::Sort(char *s)
{
    char *p;
    int nr;
    size=0;
    p=strtok(s, ",");
    while(p!=NULL)
    {
        int i;
        nr=0;
        for(i=0; i<strlen(p); i++)
        {
            nr=nr*10+(p[i]-'0');
        }
        this->arr[size]=nr;
        size++;
        p=strtok(NULL, ",");
    }
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        if (ascendent)
        {
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        else
        {
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

int Sort::Partition(int low, int high, bool ascendent)
{
    int pivot = arr[high];
    int i = (low - 1);
    int aux;
    for (int j = low; j <= high - 1; j++)
    {
        if (ascendent ? arr[j] <= pivot : arr[j] >= pivot)
        {
            i++;
            aux=arr[i];
            arr[i]=arr[j];
            arr[j]=aux;
        }
    }
    aux=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=aux;
    return (i + 1);
}

void Sort::QuickSortHelper(int low, int high, bool ascendent)
{
    if (low < high)
    {
        int pivotIndex = Partition(low, high, ascendent);
        QuickSortHelper(low, pivotIndex - 1, ascendent);
        QuickSortHelper(pivotIndex + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent)
{
    QuickSortHelper(0, size - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    int aux;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ascendent ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1])
            {
                aux=arr[i];
                arr[i]=arr[j];
                arr[j]=aux;
            }
        }
    }
}

void Sort::Print()
{
    int i;
    for(i=0; i<size; i++) printf("%d ", arr[i]);
}

int Sort::GetElementsCount()
{
    return size;
}

int Sort::GetElementFromIndex(int index)
{
    return arr[index];
}