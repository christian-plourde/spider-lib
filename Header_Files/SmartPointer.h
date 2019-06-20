#include <iostream>
namespace SpiderLib::Utilities
{
    #ifndef SPIDERLIB_SMARTPOINTER_H
    #define SPIDERLIB_SMARTPOINTER_H

    template <class T>
    class SmartPointer
    {
        private:
            T* ptr;
        public:
            explicit SmartPointer(T* p = NULL){ptr = p;};
            ~SmartPointer(){delete ptr;};
            T &operator *(){return *ptr;};
            T *operator ->(){return ptr;};
    };

    #endif //SPIDERLIB_SMARTPOINTER_H
}

