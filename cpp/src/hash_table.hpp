#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <functional>
#include <vector>

template <class T>
class HashTable
{
public:
    HashTable();
    HashTable(const int& size);
    void insert(const T& key);
    T search(const T& key);

private:
    std::size_t getHash(const T& key);

    std::vector<std::vector<T>> hashTable;
};

template <class T>
HashTable<T>::HashTable()
{
    hashTable = std::vector<std::vector<T>>(20);
}

template <class T>
HashTable<T>::HashTable(const int& size)
{
    if (size > 0)
    {
        hashTable = std::vector<std::vector<T>>(size);
    }
    else
    {
        HashTable();
    }
    
}

template <class T>
void HashTable<T>::insert(const T& key)
{
    std::size_t hashVal = getHash(key);

    hashTable.at(hashVal).push_back(key);
}

template <class T>
T HashTable<T>::search(const T& key)
{
    std::size_t hashVal = getHash(key);

    for (auto value : hashTable.at(hashVal))
    {
        if (key == value)
        {
            return key;
        }
    }
    return T();
}

template <class T>
std::size_t HashTable<T>::getHash(const T& key)
{
    return std::hash<T>{}(key) % hashTable.size();
}

#endif /* HASH_TABLE_HPP */