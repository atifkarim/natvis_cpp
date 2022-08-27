#include <iostream>

class FOO
{
    public:
        FOO(uint32_t a_, uint32_t b_) : a{a_}, b{b_}
                                        {}

        void Print_Value();
        uint32_t *pointer_array; // natvis checking will be done for this with ArrayItems

    protected:
        uint32_t a, b;

};