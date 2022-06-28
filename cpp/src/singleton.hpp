/*
Topic: Singleton
Category: Design Pattern
*/

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

class Singleton
{
    public:
        static Singleton &getInstance()
        {
            static Singleton instance;
            return instance;
        }

    private:
        Singleton() {}
        Singleton(Singleton const&) {}
        void operator=(Singleton const&) {}
};

#endif /* SINGLETON_HPP */