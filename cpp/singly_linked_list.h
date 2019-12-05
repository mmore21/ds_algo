#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

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
        void pop_front();
        void push_back(const T& val);
        void pop_back();

    private:
        Node<T> *head;
};

#endif /* SINGLY_LINKED_LIST_H_ */