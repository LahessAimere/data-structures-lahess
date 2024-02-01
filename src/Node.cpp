#include "Node.hpp"

namespace Data
{
    template<class Datatype>
    inline Node<Datatype>::Node()
    {
        this->_data = Datatype(0);
        this->_next = nullptr;
    }

    template<class Datatype>
    inline Node<Datatype>::Node(Datatype data)
    {
        this->_data = data;
        this->_next = nullptr;
    }

    template<class Datatype>
    inline Node<Datatype>::~Node()
    {
        this->_next = nullptr;
    }

    template<class Datatype>
    void Node<Datatype>::insertAfter(Datatype data)
    {
        Node<Datatype>* newNode = new Node<Datatype>;
        newNode->_data = data;
        newNode->_next = this->_next;
        this->_next = newNode;
    }


    template class Node<int>;
}