#include "../headers/NumberList.h"
#include "../source/NumberList.cpp"

int main()
{
    NumberList list;

    list.Init();

    list.Add(5);
    list.Add(10);
    list.Add(4);
    list.Add(6);
    list.Add(9);
    list.Add(12);
    list.Add(3);
    list.Add(43);
    list.Add(2);
    list.Add(1);
    list.Add(7);

    printf("before sorting:\n");
    list.Print();
    printf("\n");

    list.Sort();

    printf("after sorting:\n");
    list.Print();
    printf("\n");
}