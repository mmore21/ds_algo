#include "singly_linked_list.h"

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    this->head = nullptr;
}

template <class T>
bool SinglyLinkedList<T>::empty() const
{
    return head ? true : false;
}

template <class T>
size_t SinglyLinkedList<T>::size() const
{
    size_t count = 0;
    Node<T> *tmp = head;
    while (tmp != nullptr)
    {
        tmp = tmp->next;
        count++;
    }

    return count;
}

template <class T>
void SinglyLinkedList<T>::push_front(const T& val)
{
}

template <class T>
void SinglyLinkedList<T>::pop_front()
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

template <class T>
void SinglyLinkedList<T>::push_back(const T& val)
{
    
}

template <class T>
void SinglyLinkedList<T>::pop_back()
{
    
}