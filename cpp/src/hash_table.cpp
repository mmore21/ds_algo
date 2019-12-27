#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <functional>
#include <vector>
#include <iostream>

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
    hashTable = std::vector<std::vector<T>>(size);
}

template <class T>
void HashTable<T>::insert(const T& key)
{
    std::size_t hashVal = getHash(key) % hashTable.size();

    hashTable.at(hashVal).push_back(key);
}

template <class T>
T HashTable<T>::search(const T& key)
{
    std::size_t hashVal = getHash(key) % hashTable.size();

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
    std::cout << "HASH:" << std::hash<T>{}(key) << "\n";
    return std::hash<T>{}(key);
}

int main()
{
    HashTable<std::string> h(5);

    h.insert("203");
    std::cout << h.search("203") << "\n";
    return 0;
}

#endif /* HASH_TABLE_HPP */