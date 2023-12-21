#include <iostream>
#include "Array.hpp"

using namespace Data;

template<class Datatype>
void displayArray(Array<Datatype>& array)
{
    std::cout << "[";
    for (int i = 0; i < array._size; i++)
    {
        std::cout << array._array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    Array<int> intArray(5);
    displayArray(intArray);

    intArray[0] = 75;
    intArray[1] = 91;
    intArray[2] = 5;
    intArray[3] = 0;
    intArray[4] = 46;

    displayArray(intArray);

    intArray.resize(10);

    displayArray(intArray);

    intArray.insert(67, 3);

    displayArray(intArray);

    intArray.remove(0);

    displayArray(intArray);

    return 0;
}