#include "Sort.h"


int main()
{
    Sort s1(10, 1, 100);
    Sort s2{10, 50, 20, 30, 10, 5};
    int arr[] = {100, 50, 20, 10, 5};
    Sort s3(arr, 5);
    Sort s4("10,40,100,5,70");
    Sort s5(6, 10, 40, 60, 20, 5, 80);

    s1.InsertSort();
    s1.Print();

    s2.QuickSort(true);
    s2.Print();

    s3.BubbleSort();
    s3.Print();

    s4.InsertSort(true);
    s4.Print();

    s5.QuickSort();
    s5.Print();

    return 0;
}