#include "Map.h"

int main()
{
    const int MaxSize=10;

    Map<int, const char *, MaxSize> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    for(auto[key, value, index] : m)
    {
        if(m.Get(key, value)) printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    Map<int, const char *, MaxSize> m2;
    m2[10]="C++";
    m2[30]="Poo";

    if(m.Includes(m2))
    {
        printf("m2 includes elements from m\n");
    }

    //m2.Clear();

    for(auto[key, value, index]:m)
    {
        if(m.Delete(key)) printf("Succesfully deleted the map from index=%d\n", index);
    }

    return 0;
}
