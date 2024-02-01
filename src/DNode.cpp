#include "DNode.hpp"

namespace Data
{
    template<class Datatype>
    inline DNode<Datatype>::DNode()
    {
        this->_data = Datatype(0);
        this->_next = nullptr;
        this->_prev = nullptr;
    }

    template<class Datatype>
    inline DNode<Datatype>::DNode(Datatype data)
    {
        this->_data = data;
        this->_next = nullptr;
        this->_prev = nullptr;
    }

    template<class Datatype>
    inline DNode<Datatype>::~DNode()
    {
        this->_next = nullptr;
        this->_prev = nullptr;
    }

    template<class Datatype>
    void DNode<Datatype>::insertAfter(Datatype data)
    {
        DNode<Datatype>* newNode = new DNode<Datatype>(data);
        newNode->_next = this->_next;
        newNode->_prev = this;
        this->_next = newNode;

        if (newNode->_next != nullptr)
        {
            newNode->_next->_prev = newNode;
        }
    }

    template<class Datatype>
    void DNode<Datatype>::insertBefore(Datatype data)
    {
        DNode<Datatype>* newNode = new DNode<Datatype>(data);
        newNode->_prev = this->_prev;
        newNode->_next = this;
        this->_prev = newNode;

        if (newNode->_prev != nullptr)
        {
            newNode->_prev->_next = newNode;
        }
    }



    template class DNode<int>;
}