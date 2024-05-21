#include "Arr.h"

// template<class T>
// ArrayIterator<T>::ArrayIterator(int Current, Array<T>* arr): arr(arr), Current(Current)
// {

// }

template <class T>
ArrayIterator<T>::ArrayIterator(Array<T>* arr, int Current): Current(Current), arr(arr)
{

}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator++()
{
    if(Current<arr->getSize()-1)
    {
        Current++;
    }
    return *this;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator--()
{
    if(Curren>0)
    {
        Curren--;
    }
    return *this;
}

template<class T>
bool ArrayIterator<T>::operator==(ArrayIterator<T>& other)
{
    return Current==other.Current;
}

template<class T>
bool ArrayIterator<T>::operator!=(ArrayIterator<T>& other)
{
    return Current!=other.Current;
}

template<class T>
T* ArrayIterator<T>::GetElement()
{
    return &((*arr)[Current]);
}

template <class T>
Array<T>::Array(): List(nullptr) Capacity(0), Size(0)
{

}

template <class T>
Array<T>::Array(int capacity): Capacity(capacity), Size(0)
{
    if(Capacity<=0)
    {
        throw AllocationException();
    }
    List=new T*[Capacity];
}


template <class T>
Array<T>::Array(const Array<T>& otherArray): Capacity(otherArray.Capacity), Size(otherArray.Size)
{
    List=new T*[Capacity];
    for(int i=0; i<Size; i++)
    {
        List[i]=new T(*otherArray.List[i]);
    }
}

template <class T>
Array<T>::~Array()
{
    delete[] List;
}

template<class T>
T& Array<T>::operator[](int index)
{
   checkIndex(index);
   return *List[index];
}

template<class T>
const Array<T>& Array<T>::operator+=(const T &newElem)
{
    if(Size>=Capacity)
    {
        throw AllocationException();
    }

    List[Size++]=new T(newElem);
    return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T &newElem)
{
    if(index<0 || index>=Size)
    {
        throw OutOfBoundsException();
    }

    if(Size>=Capacity)
    {
        throw AllocationException();
    }

    for(int i=Size; i>index; i--)
    {
        List[i]=List[i-1];
    }

    List[index]=new T(newElem);
    Size++;
    return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
    if(index<0 || index>=Size)
    {
        throw OutOfBoundsException();
    }

    if(Size+otherArray.Size>=Capacity)
    {
        throw AllocationException();
    }

    for(nt i-Size-1; i>=index; i--)
    {
        List[i+otherArray.Size]=List[i];
    }

    for(int i=0; i<otherArray.Size; i++)
    {
        List[index+i]=new T*(otherArray.List[i]);
    }

    Size+=otherArray.Size;
    
    return *this;
}

template<class T>
const Array<T>& Array<T>::Delete(int index)
{
    checkIndex(index);
    delete List[index];
    for(int i=index; i<Size-1; i++)
    {
        List[i]=List[i+1];
    }
    Size--;
    return *this;
}

template<class T>
bool Array<T>::operator=(const Array<T>& otherArray)
{
    if(this==otherArray)
    {
        return true;
    }

    for(int i=0; i<Size; i++)
    {
        delete List[i];
    }

    delete[] List;

    Capacity=otherArray.Capacity;
    Size=otherArray.Size;
    List=new T*[Capacity];

    for(int i=0; i<Size; i++)
    {
        List[i]=new T(*otherArray.List[i]);
    }

    return true;
}

template<class T>
void Array<T>::Sort()
{
    if(Size>1)
    {
        quickSort(0; Start-1);
    }
}

template<class T>
void Array<T>::Sort(int(*compare)(const T&, const T&))
{
    if(Size<=1) return;
    auto comp=[compare](T*a, T*b){return compare(*a, *b)<0;};
    sort(List, List+Size, comp);
}

template<class T>
void Array<T>::Sort(Compare *comparator)
{
    if(Size<=1) return;
    auto cmp=[comparator](T*a, T*b){return comparator->CompareElements(a, b)<0;};
    sort(List, List+Size, cmp);
}

template<class T>
int Array<T>::BinarySearch(const T& elem)
{
    int l=0, r=Size-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2
        if(*List[mid]==elem) return mid;
        if(*List[mid]<elem) left=mid+1;
        else right=mid-1;
    }

    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
    int l=0, r=Size-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2
        int cmpRez=compare(*List[mid], elem);
        if(cmpRez==0) return mid;
        if(cmpRez<0) left=mid+1;
        else right=mid-1;
    }

    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, Compare *comparator)
{
    int l=0, r=Size-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2
        int cmpRez=comparator->CompareElements(List[mid], &elem);
        if(cmpRez==0) return mid;
        if(cmpRez<0) left=mid+1;
        else right=mid-1;
    }

    return -1;
}

template<class T>
int Array<T>::Find(const T& elem)
{
    for(int i=0; i<Size; i++)
    {
        if(*List[i]==elem) return  i;
    }
    return -1;
}

template<class T>
int Array<T>::Find(const T &elem, int(*compare)(const T&, const T&))
{
    for(int i=0; i<Size; i++)
    {
        if(compare(*List[i], elem)==0) return  i;
    }
    return -1;
}

template<class T>
int Array<T>::Find(const T &elem, Compare *comparator)
{
    for(int i=0; i<Size; i++)
    {
        if(comparator->CompareElements(List[i], &elem)==0) return  i;
    }
    return -1;
}

template <class T>
int Array<T>::GetSize()
{
    return Size;
}

template <class T>
int Array<T>::GetCapacity()
{
    return Size;
}

template <class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
    return ArrayIterator(this, 0);
}

template <class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
    return ArrayIterator(this, Size);
}
