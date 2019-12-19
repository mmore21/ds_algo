#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <vector>
#include <exception>

template <class T>
class Queue
{
    public:
        Queue();

        bool empty() const;
        size_t size() const;

        T& front();
        T& back();

        void push(const T& val);
        void pop();

    private:
        std::vector<T> queue;
};

template <class T>
Queue<T>::Queue()
{
    this->queue = std::vector<T>();
}

template <class T>
bool Queue<T>::empty() const
{
    return queue.empty();
}

template <class T>
size_t Queue<T>::size() const
{
    return queue.size();
}

template <class T>
T& Queue<T>::front()
{
    if (queue.empty())
    {
        throw std::exception();
    }
    return queue.front();
}

template <class T>
T& Queue<T>::back()
{
    if (queue.empty())
    {
        throw std::exception();
    }
    return queue.back();
}

template <class T>
void Queue<T>::push(const T& val)
{
    queue.push_back(val);
}

template <class T>
void Queue<T>::pop()
{
    if (empty())
    {
        throw std::exception();
    }
    queue.erase(queue.begin());
}

#endif /* QUEUE_H */