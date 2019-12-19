#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

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
        std::cout << "DATA:" << ptr->data << "\n";
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

    if (head == nullptr)
    {
        head = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
    
}

template <class T>
void SinglyLinkedList<T>::push_back(const T& val)
{
    Node<T> *node = new Node<T>();
    node->data = val;

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

        if (ptr->next == nullptr)
        {
            delete ptr;
            ptr = nullptr;
        }
        else
        {
            while (ptr->next != nullptr)
            {
                std::cout << ptr->data << "\n";
                ptr = ptr->next;
            }
            delete ptr;
            ptr = nullptr;
        }
    }
}

#endif /* SINGLY_LINKED_LIST_H */