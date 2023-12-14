#include <iostream>
#include "Array.hpp"

namespace Data {
    template<class Datatype>
    inline Array<Datatype>::Array (int size)
    {
    std::cout << "Construction de mon Array " << std::endl;
        this->_array = new Datatype[size];
        this->_size = size;
        for (int i = 0; i < size; i++)
        {
           this->_array[i]= Datatype(0);
        }
    }
    template<class Datatype>
    inline Array<Datatype>::~Array ()
    {
    std::cout << "Destruction de mon Array " << std::endl;
        if (this-> _array != nullptr)
        {
            delete this-> _array;
        }
        this->_array =nullptr;
    }

    template<class Datatype>
    void Array<Datatype>::resize (int newSize)
    {
        if (newSize == this->_size) return;
        
        Datatype* newArray = new Datatype[newSize];
        if (newArray == nullptr) return;

        int min = (newSize < this-> _size) ? newSize : this->_size;
        for (int i = 0; i < min ; i++)
        {
            newArray[i] = this->_array[i];
        }
        this->_size = newSize;

        if (this->_array != nullptr)
        {
            delete[] this->_array;
        }
        
        this->_array = newArray;
        
    }

    template<class Datatype>
    void Array<Datatype>::insert(Datatype item, int index)
    {
           for (int i = this->_size - 1; i < index; i--)
           {
                this->_array[i] = this->_array[i - 1];
           }
           this->_array[index] = item;
    }

    template<class Datatype>
    void Array<Datatype>::remove(int index)
    {
        for (int i =index + 1; i < this->_size; i++)
        {
            this->_array[i - 1] = this-> _array[i];
        }
        
    }

    template<class Datatype>
    int Array<Datatype>::size()
    {
        return this->_size;
    }

    template<class Datatype>
    Datatype& Array<Datatype>::operator[](int index)
    {
         return this->_array[index];
    }

    template<class Datatype>
    Array<Datatype>::operator Datatype* ()
    {
         return this->_array;
    }

    //template<class Datatype>
    //std::iostream&  Array::operator<<(std<<ostrea)

    template class Array<int>;
    template class Array<float>;
    template class Array<double>;
    template class Array<char>;
}