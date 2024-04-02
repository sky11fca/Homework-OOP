#include "../headers/NumberList.h"
#include <stdio.h>

void NumberList::Init()
{
    count=0;
}

bool NumberList::Add(int x)
{
    if(count>=10) return false;
    else
    {
        numbers[count]=x;
        count++;
        return true;
    }
}

void NumberList::Sort()
{
    int i, j;
    int aux;
    for(i=0; i<count-1; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(numbers[i]>numbers[j])
            {
                aux=numbers[i];
                numbers[i]=numbers[j];
                numbers[j]=aux;
            }
        }
    }
}

void NumberList::Print()
{
    int i;
    for(i=0; i<count; i++) printf("%d ", numbers[i]);
}