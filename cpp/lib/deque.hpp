#ifndef DEQUE_H
#define DEQUE_H

#include <cstdlib>
#include <vector>
#include <exception>

template <class T>
class Deque
{
    public:
        Deque();

        bool empty() const;
        size_t size() const;

        T& front();
        T& back();
        T& at(size_t n);

        void push_back(const T& val);
        void push_front(const T& val);
        void pop_back();
        void pop_front();

    private:
        std::vector<T> deque;
};

template <class T>
Deque<T>::Deque()
{
    this->deque = std::vector<T>();
}

template <class T>
bool Deque<T>::empty() const
{
    return deque.empty();
}

template <class T>
size_t Deque<T>::size() const
{
    return deque.size();
}

template <class T>
T& Deque<T>::front()
{
    if (deque.empty())
    {
        throw std::exception();
    }
    return deque.front();
}

template <class T>
T& Deque<T>::back()
{
    if (deque.empty())
    {
        throw std::exception();
    }
    return deque.back();
}

template <class T>
T& Deque<T>::at(size_t n)
{
    if (n > deque.size() - 1)
    {
        throw std::exception();
    }
    return deque.at(n);
}

template <class T>
void Deque<T>::push_back(const T& val)
{
    deque.push_back(val);
}

template <class T>
void Deque<T>::push_front(const T& val)
{
    deque.insert(deque.begin(), val);
}

template <class T>
void Deque<T>::pop_back()
{
    if (empty())
    {
        throw std::exception();
    }
    deque.pop_back();
}

template <class T>
void Deque<T>::pop_front()
{
    if (empty())
    {
        throw std::exception();
    }
    deque.erase(deque.begin());
}

#endif /* DEQUE_H */