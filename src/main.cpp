#include "foo.h"

int main()
{
    FOO obj_1(58,9);
    obj_1.Print_Value();

    uint32_t foo_array[5] = {5,15,96,8,77};
    obj_1.pointer_array = foo_array;
    uint32_t * pointer_array_1 = foo_array;

    std::cout << "printing pointer" << std::endl;
    for(int i = 0; i < 5 ; i++)
    {
        std::cout << *(obj_1.pointer_array + i) << " ** ";
    }
    std::cout << std::endl;

    for(int i = 0; i < 5 ; i++)
    {
        std::cout << *(pointer_array_1 + i) << " *//* ";
    }


    return 0;
}
