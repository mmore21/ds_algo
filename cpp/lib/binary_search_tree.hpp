#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <cstddef>
#include <iostream>
#include <exception>

template <class T>
class Node
{
    public:
        Node(const int key, const T &value);
        int key;
        T value;
        Node<T> *left;
        Node<T> *right;
    private:
};

template <class T>
Node<T>::Node(const int key, const T &value)
{
    this->key = key;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
class BinarySearchTree
{
    public:
        BinarySearchTree();
        bool empty() const;
        size_t size() const;

        Node<T> *search(const int &key);
        void insert(const int &key, const T &value);
        void remove(const int &key);

    private:
        Node<T> *root;

        size_t sizeHelper(Node<T> *node) const;
        Node<T> *removeHelper(const int &key, Node<T> *node);
        Node<T> *findMin(Node<T> *node);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    this->root = nullptr;
}

template <class T>
bool BinarySearchTree<T>::empty() const
{
    return !root;
}

template <class T>
size_t BinarySearchTree<T>::size() const
{
    return sizeHelper(root);
}

template <class T>
size_t BinarySearchTree<T>::sizeHelper(Node<T> *node) const
{
    return node ? 1 + sizeHelper(node->left) + sizeHelper(node->right) : 0;
}

template <class T>
Node<T> *BinarySearchTree<T>::search(const int &key)
{
    Node<T> *ptr = root;

    while (ptr)
    {
        if (key == ptr->key)
        {
            return ptr;
        }
        else if (key < ptr->key)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }

    return nullptr;
}

template <class T>
void BinarySearchTree<T>::insert(const int &key, const T &value)
{
    Node<T> *ptr = root;
    Node<T> *prev;
    Node<T> *node = new Node<T>(key, value);

    if (!root || key == root->key)
    {
        root = node;
    }
    else
    {
        while (ptr)
        {
            if (key == ptr->key)
            {
                ptr->value = value;
                return;
            }
            else if (key < ptr->key)
            {
                prev = ptr;
                ptr = ptr->left;
            }
            else
            {
                prev = ptr;
                ptr = ptr->right;
            }
        }
        if (key < prev->key)
        {
            prev->left = node;
        }
        else
        {
            prev->right = node;
        }
    }
}

template <class T>
void BinarySearchTree<T>::remove(const int &key)
{
    if (empty())
    {
        throw std::exception();
    }
    else
    {
        root = removeHelper(key, root);
    }
    
}

template <class T>
Node<T> *BinarySearchTree<T>::removeHelper(const int &key, Node<T> *node)
{
    if (key < node->key)
    {
        node->left = removeHelper(key, node->left);
    }
    else if (key > node->key)
    {
        node->right = removeHelper(key, node->right);
    }
    else
    {
        if (node->left && node->right)
        {
            Node<T> *tmp = findMin(node->right);
            node->value = tmp->value;
            node->right=removeHelper(tmp->key, root->right);
        }
        else if (node->left)
        {
            Node<T> *tmp = node;
            node = node->left;
            delete tmp;
        }
        else if (node->right)
        {
            Node<T> *tmp = node;
            node = node->right;
            delete tmp;
        }
        else
        {
            delete node;
            node = nullptr;
        }
    }
    return node;
}

template <class T>
Node<T> *BinarySearchTree<T>::findMin(Node<T> *node)
{
    while (node->left)
    {
        node = node->left;
    }

    return node;
}

#endif /* BINARY_SEARCH_TREE_HPP */