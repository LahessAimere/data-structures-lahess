#include "ListIterator.hpp"
#include "LinkedList.hpp"

namespace Data
{
    template <class Datatype>
    inline ListIterator<Datatype>::ListIterator(LinkedList<Datatype>* list)
    {
        this->_list = list;
        this->_node = list->_head;
    }

    template <class Datatype>
    inline ListIterator<Datatype>::ListIterator(LinkedList<Datatype>& list)
    {
        this->_list = &list;
        this->_node = list._head;
    }

    template <class Datatype>
    void ListIterator<Datatype>::start()
    {
        if(this->_list != nullptr)
        {
            this->_node = this->_list->_head;
        }
    }

    template <class Datatype>
    void ListIterator<Datatype>::forth()
    {
        if(this->_node != nullptr)
        {
            this->_node = this->_node->_next;
        }
    }

    template <class Datatype>
    Datatype& ListIterator<Datatype>::item()
    {
        return this->_node->_data;
    }

    template <class Datatype>
    bool ListIterator<Datatype>::isValid()
    {
        return this->_node != nullptr;
    }

    template <class Datatype>
    bool ListIterator<Datatype>::hasNext()
    {
        return this->_node != nullptr && this->_node->_next != nullptr;
    }

    template class ListIterator<int>;
}