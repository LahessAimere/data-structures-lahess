#include "DListIterator.hpp"
#include "DLinkedList.hpp"

namespace Data
{
    template <class Datatype>
    inline DListIterator<Datatype>::DListIterator(DLinkedList<Datatype>* list)
    {
        this->_list = list;
        this->_node = list->_head;
    }

    template <class Datatype>
    inline DListIterator<Datatype>::DListIterator(DLinkedList<Datatype>& list)
    {
        this->_list = &list;
        this->_node = list._head;
    }

    template <class Datatype>
    void DListIterator<Datatype>::start()
    {
        if(this->_list != nullptr)
        {
            this->_node = this->_list->_head;
        }
    }

    template <class Datatype>
    void DListIterator<Datatype>::forth()
    {
        if(this->_node != nullptr)
        {
            this->_node = this->_node->_next;
        }
    }

    template <class Datatype>
    void DListIterator<Datatype>::backward()
    {
        if (this->_node != nullptr)
        {
            this->_node = this->_node->_prev;
        }
    }

    template <class Datatype>
    void DListIterator<Datatype>::end()
    {
        if (this->_list != nullptr)
        {
            this->_node = this->_list->_tail;
        }
    }

    template <class Datatype>
    Datatype& DListIterator<Datatype>::item()
    {
        return this->_node->_data;
    }

    template <class Datatype>
    bool DListIterator<Datatype>::isValid()
    {
        return this->_node != nullptr;
    }

    template <class Datatype>
    bool DListIterator<Datatype>::hasNext()
    {
        return this->_node != nullptr && this->_node->_next != nullptr;
    }

    template class DListIterator<int>;
}