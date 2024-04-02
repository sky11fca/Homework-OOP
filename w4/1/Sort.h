#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cstdarg>

class Sort
{
    int size;
    int *arr;    
    public:

    Sort(int nr, int min, int max);    
    Sort(int *init, int nr);
    Sort(int *init);
    Sort(int nr, ...);
    Sort(char *s);

    void InsertSort(bool ascendent = false);
    int Partition(int low, int high, bool ascendent);
    void QuickSortHelper(int low, int high, bool ascendent);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};
