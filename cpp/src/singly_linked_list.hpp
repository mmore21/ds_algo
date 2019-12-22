#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
#include <cstddef>

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class SinglyLinkedList
{
    public:
        SinglyLinkedList();

        bool empty() const;
        size_t size() const;

        void push_front(const T& val);
        void push_back(const T& val);
        void pop_front();
        void pop_back();

        void output();

    private:
        Node<T> *head;
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    this->head = nullptr;
}

template <class T>
bool SinglyLinkedList<T>::empty() const
{
    return head ? false : true;
}

template <class T>
size_t SinglyLinkedList<T>::size() const
{
    int count = 0;
    Node<T> *ptr = head;

    while (ptr != nullptr)
    {
        ptr = ptr->next;
        count++;
    }

    return count;
}

template <class T>
void SinglyLinkedList<T>::push_front(const T& val)
{
    Node<T> *node = new Node<T>();
    node->data = val;
    node->next = head;
    head = node;
}

template <class T>
void SinglyLinkedList<T>::push_back(const T& val)
{
    Node<T> *node = new Node<T>();
    node->data = val;
    node->next = nullptr;

    if (head == nullptr)
    {
        head = node;
    }
    else
    {
        Node<T> *ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }

        ptr->next = node;
    }
}

template <class T>
void SinglyLinkedList<T>::pop_front()
{
    if (head)
    {
        if (head->next)
        {
            head = head->next;
        }
        else
        {
            head = nullptr;
        }
    }
}

template <class T>
void SinglyLinkedList<T>::pop_back()
{
    if (head)
    {
        Node<T> *ptr = head;
        Node<T> *prev;
        if (head->next == nullptr)
        {
            head = nullptr;
            delete ptr;
        }
        else
        {
            while(ptr->next != nullptr)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = nullptr;
            delete ptr;
        }
    }
}

template <class T>
void SinglyLinkedList<T>::output()
{
    Node<T> *ptr = head;
    while (ptr)
    {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    std::cout << "\n";
}

#endif /* SINGLY_LINKED_LIST_HPP */