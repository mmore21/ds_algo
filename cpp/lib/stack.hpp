#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <vector>
#include <exception>

template <class T>
class Stack
{
    public:
        Stack();

        bool empty() const;
        size_t size() const;

        T& top();

        void push(const T& val);
        void pop();

    private:
        std::vector<T> stack;
};

template <class T>
Stack<T>::Stack()
{
    this->stack = std::vector<T>();
}

template <class T>
bool Stack<T>::empty() const
{
    return stack.empty();
}

template <class T>
size_t Stack<T>::size() const
{
    return stack.size();
}

template <class T>
T& Stack<T>::top()
{
    if (empty())
    {
        throw std::exception();
    }
    return stack.back();
}

template <class T>
void Stack<T>::push(const T& val)
{
    stack.push_back(val);
}

template <class T>
void Stack<T>::pop()
{
    if (empty())
    {
        throw std::exception();
    }
    stack.pop_back();
}

#endif /* STACK_H */