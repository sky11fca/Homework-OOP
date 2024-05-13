#include "Map.h"

template <typename K, typename V, int MaxSize>
Map<K, V, MaxSize>::Map(): size(0)
{
    Keys=new K[MaxSize];
    Value=new V[MaxSize];
}

template <typename K, typename V, int MaxSize>
void Map<K, V, MaxSize>::Set(const K&key, const V& value)
{
    Keys[size]=key;
    Value[size]=value;
    size++;
}

template <typename K, typename V, int MaxSize>
bool Map<K, V, MaxSize>::Get(const K& key, const V& value)
{
    for(int i=0; i<size; i++)
    {
        if(Keys[i]==key)
        {
            //value=Value[i];
            return true;
        }
    }
    return false;
}

template <typename K, typename V, int MaxSize>
int Map<K, V, MaxSize>::Count()
{
    return size;
}


template <typename K, typename V, int MaxSize>
void Map<K, V, MaxSize>::Clear()
{
    delete[] Keys;
    delete[] Value;
    size=0;
}

template <typename K, typename V, int MaxSize>
bool Map<K, V, MaxSize>::Delete(const K& key)
{
    for(int i=0; i<size; i++)
    {
        if(Keys[i]==key)
        {
            Keys[i]=Keys[size-1];
            Value[i]=Value[size-1];
            size--;
            return true;
        }
    }
    return false;
}

template <typename K, typename V, int MaxSize>
bool Map<K, V, MaxSize>::Includes(const Map<K, V, MaxSize>& M)
{
    for(int i=0; i<M.size; i++)
    {
        bool found=false;
        for(int j=0; j<size; j++)
        {
            if(Keys[j]==M.Keys[i])
            {
                found=true;
                break;
            }
        }
        if(!found) return false;
    }

    return true;
}

template <typename K, typename V, int MaxSize>
V& Map<K, V, MaxSize>::operator[](const K& key)
 {
    for(int i=0; i<size; i++)
    {
        if(Keys[i]==key)
        {
            return Value[i];
        }
    }

    Set(key, V());
    return Value[size-1];
}

template <typename K, typename V, int MaxSize>
Map<K, V, MaxSize>::~Map()
{
    Clear();
}