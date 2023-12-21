#include "Array.hpp"
#include <iostream>

namespace Data {
    template<class Datatype>
    
    inline Array<Datatype>::Array (int size)
    {
        _array = new Datatype[size];
        _size = size;

        for (int i = 0; i < size; ++i) 
        {
            _array[i] = Datatype();
        }
    }

    template<class Datatype>
    inline Array<Datatype>::~Array ()
    {
        delete[] _array;
    }

    template<class Datatype>
    void Array<Datatype>::resize (int size)
    {
        Datatype* newArray = new Datatype[size];
        
        int min;
        if (size < _size) 
        {
            min = size;
        } 
        else 
        {
            min = _size;
        }

        for (int i = 0; i < min; ++i) 
        {
            newArray[i] = _array[i];
        }
        delete[] _array;
        _array = newArray;
    }

    template<class Datatype>
    void Array<Datatype>::insert(Datatype item, int index)
    {
        for (int i = _size - 1; i > index; --i) {
        _array[i] = _array[i - 1];
    }
        _array[index] = item;
    }

    template<class Datatype>
    void Array<Datatype>::remove(int index)
    {
        for (int i = index + 1; i < _size; ++i) 
        {
            _array[i - 1] = _array[i];
        }
        _size--;
    }

    template<class Datatype>
    int Array<Datatype>::size()
    {
        return _size;
    }

    template<class Datatype>
    Datatype& Array<Datatype>::operator[](int index)
    {
        return _array[index];
    }

    template<class Datatype>
    Array<Datatype>::operator Datatype* ()
    {
        return _array;
    }

    template class Array<int>; 
}