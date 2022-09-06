#include <iostream>

class FOO
{
    public:
        FOO(uint32_t a_, uint32_t b_) : a{a_}, b{b_}
                                        {}

        void Print_Value();
        uint32_t *pointer_array;

    protected:
        uint32_t a, b;

};

class Test_Natvis
{
    public:
        uint32_t * large_container;
        uint32_t large_container_size;

};