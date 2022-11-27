// https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
#include <iostream>

int main()
{
    int value{5};
    // notation: pointer is made with an *
    // notation: an & before an object gives us its address

    // create a new int pointer that points to loc of value.
    int *ptr{&value};
    std::cout << *ptr << '\n'; // Dereference pointer to int to get int value

    int **ptrptr{&ptr};            // works the same as with value, getting the pointer adress.
    std::cout << **ptrptr << '\n'; // dereference to get pointer to int, dereference again to get int value

    return 0;
}