#include "Array.hpp"

namespace Data {
    
    template<class Datatype>
    inline Array<Datatype>::Array (int size)
    {
        this->_size = size;
        this->_array = new Datatype[size];

        for(int i = 0; i < size; i++)
        {
            this->_array[i] = Datatype(0);
        }
    }

    template<class Datatype>
    inline Array<Datatype>::~Array ()
    {
        if(this->_array != nullptr)
        {
            delete this->_array;
        }
        this->_array = nullptr;
    
    }

    template<class Datatype>
    void Array<Datatype>::resize (int size)
    {
        if(size == this->_size) return;

        Datatype* newArray = new Datatype[size];
        if(newArray == nullptr)
        {
            return;
        }

        int min = size < this->_size? size : this->_size;
        for(int index = 0; index < min; ++index)
        {
            newArray[index] = this->_array[index];
        }

        this->_size = size;

        if(this->_array != 0) {
            delete[] this->_array;
        }

        this->_array = newArray;
    }

    template<class Datatype>
    void Array<Datatype>::insert(Datatype item, int index)
    {
        for(int i = this->_size - 1; i > index; i--)
        {
            this->_array[i] = this->_array[i - 1];
        }
        this->_array[index] = item;
    }

    template<class Datatype>
    void Array<Datatype>::remove(int index)
    {
        for(int i = index + 1; i < this->_size; ++i)
        {
            this->_array[i - 1] = this->_array[i];
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

    template class Array<int>;
    template class Array<double>;

}