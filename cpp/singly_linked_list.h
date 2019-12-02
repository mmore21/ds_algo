#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

template <class T>
struct Node
{
    T data;
    Node *next;
};

template <class T>
class SinglyLinkedList
{
    SinglyLinkedList();

    bool empty() const;
    size_t size() const;

    void push_front(const T& val);
    void pop_front();
    void push_back(const T& val);
    void pop_back();
};

#endif /* SINGLY_LINKED_LIST_H_ */