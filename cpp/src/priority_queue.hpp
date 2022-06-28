#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <cstdlib>
#include <exception>
#include <vector>

template <class T>
class PriorityQueue
{
    public:
        PriorityQueue();

        bool empty() const;
        size_t size() const;

        const T &top() const;
        void push(const T &val);
        void pop();

    private:
        std::vector<T> pq;
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    pq = std::vector<T>();
}

template <class T>
bool PriorityQueue<T>::empty() const
{
    return pq.empty();
}

template <class T>
size_t PriorityQueue<T>::size() const
{
    return pq.size();
}

template <class T>
const T &PriorityQueue<T>::top() const
{
    if (pq.empty())
    {
        throw std::exception();
    }
    else
    {
        return pq.front();
    }
}

template <class T>
void PriorityQueue<T>::push(const T &val)
{
    for (typename std::vector<T>::iterator it = pq.begin(); it != pq.end(); ++it)
    {
        if (val > *it)
        {
            pq.insert(it, val);
            return;
        }
    }
    pq.push_back(val);
}

template <class T>
void PriorityQueue<T>::pop()
{
    if (pq.empty())
    {
        throw std::exception();
    }
    else
    {
        pq.erase(pq.begin());
    }
}

#endif /* PRIORITY_QUEUE_HPP */