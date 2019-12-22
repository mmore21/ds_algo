/*
Topic: Singleton
Category: Design Pattern
*/

class Singleton
{
    public:
        static Singleton &getInstance()
        {
            static Singleton instance;
            return instance;
        }
        
        Singleton(Singleton const&) = delete;
        void operator=(Singleton const&) = delete;

    private:
        Singleton() {}
        Singleton(Singleton const&);
        void operator=(Singleton const&);      
};