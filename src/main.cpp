#include "foo.h"
# define LARGE_ARRAY_SIZE 5000

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


    Test_Natvis test_natvis;
    test_natvis.large_container_size = LARGE_ARRAY_SIZE;
    uint32_t big_array[LARGE_ARRAY_SIZE];
    for(int i = 0; i < LARGE_ARRAY_SIZE; i++)
    {
        big_array[i] = i*3;
    }
    test_natvis.large_container = big_array;


    /// Try to display limited range using Natvis
    uint32_t limit_array[10];
    for(int i = 0; i < 10; i++)
    {
        limit_array[i] = i*5;
    }
    uint32_t *limit_ptr = limit_array;

    return 0;
}
