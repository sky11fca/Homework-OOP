#include <iostream>
using namespace std;

template <typename K, typename V, int MaxSize>
class Map
{
    private:

    K *Keys;
    V *Value;
    int size;

    public:

    Map();

    void Set(const K& key, const V& value);
    bool Get(const K& key, const V& value);
    int Count();
    void Clear();
    bool Delete(const K& key);
    bool Includes(const Map<K, V, MaxSize>& M);

    V& operator[](const K& key);

    class Iterator
    {
        private:
        Map& map;
        int index;

        public:
        Iterator(Map& m, int i): map(m), index(i){}

        bool operator!=(const Iterator& other)
        {
            return index!=other.index;
        }

        void operator++()
        {
            index++;
        }

        auto operator*()
        {
            return tuple<K, V, int>(map.Keys[index], map.Value[index], index);
        }
    };

    Iterator begin()
    {
        return Iterator(*this, 0);
    }

    Iterator end()
    {
        return Iterator(*this, size);
    }
    ~Map();
};