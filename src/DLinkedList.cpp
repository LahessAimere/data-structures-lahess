#include "DLinkedList.hpp"
#include "DListIterator.hpp"

namespace Data
{
    template<class Datatype>
    inline DLinkedList<Datatype>::DLinkedList()
    {
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_count = 0;
    }

    template<class Datatype>
    inline DLinkedList<Datatype>::~DLinkedList ()
    {
        DNode<Datatype>* iterator = this->_head;
        DNode<Datatype>* next;
        while(iterator != nullptr)
        {
            next = iterator->_next;
            delete iterator;
            iterator = next;
        }
    
    }

    template<class Datatype>
    void DLinkedList<Datatype>::append(Datatype data)
    {
        if(this->_head == nullptr)
        {
            this->_head = this->_tail = new DNode<Datatype>(data);
        } else {
            this->_tail->insertAfter(data);
            this->_tail = this->_tail->_next;
        }

        this->_count++;
    }

    template<class Datatype>
    //Ajoute Avant
    void DLinkedList<Datatype>::prepend(Datatype data)
    {
        DNode<Datatype>* node = new DNode<Datatype>(data);
        node->_next = this->_head;
        this->_head = node;

        if(this->_tail == nullptr)
        {
            this->_tail = this->_head;
        }
        this->_count++;
    }

    template<class Datatype>
    void DLinkedList<Datatype>::insertAfter(DListIterator<Datatype>& itr, Datatype data)
    {
        if(itr._list != this) { return; }
        if(itr._node != nullptr)
        {
            itr._node->insertAfter(data);
            if(itr._node == this->_tail)
            {
                this->_tail = itr._node->_next;
            }
            this->_count++;
        }else{
            this->append(data);
        }
    }

    template<class Datatype>
    void DLinkedList<Datatype>::insertBefore(DListIterator<Datatype>& itr, Datatype data)
    {
        if(itr._list != this) { return; }
        if(itr._node != nullptr)
        {
            itr._node->insertBefore(data);
            if(itr._node == this->_tail)
            {
                this->_head = itr._node->_prev;
            }
            this->_count++;
        }else{
            this->prepend(data);
        }
    }

    template<class Datatype>
    void DLinkedList<Datatype>::removeHead()
    {
        DNode<Datatype>* node = nullptr;
        if(this->_head != nullptr)
        {
            node = this->_head->_next;
            delete this->_head;
            this->_head = node;
            
            // If head is null, last node was deleted
            // so also set tail at null
            if(this->_head == nullptr)
            {
                this->_tail = nullptr;
            }
            this->_count--;
        }
    }

    template<class Datatype>
    void DLinkedList<Datatype>::removeTail()
    {
        DNode<Datatype>* node = this->_head;
        if(this->_head != nullptr)
        {
            if(this->_head == this->_tail)
            {
                delete this->_head;
                this->_head = this->_tail = nullptr;
            }
        } else {
            // skip until find the tail
            while(node->_next != this->_tail)
            {
                node = node ->_next;
            }

            this->_tail = node;
            delete node->_next;
            node->_next = nullptr;
        }
        this->_count--;
    }

    template<class Datatype>
    void DLinkedList<Datatype>::removeAfter(DListIterator<Datatype>& itr)
    {
        DNode<Datatype>* node = this->_head;
        // Itr doesn't belong to this list
        if(itr._list != this) { return; }

        // Itr node isn't valid
        if(itr._node == nullptr) { return; }

        if(itr._node == this->_head)
        {
            itr.forth();
            this->removeHead();
        } else {
            // Find prior node of itr node
            while(node->_next != itr._node)
            {
                node = node->_next;
            }
            itr.forth();

            if(node->_next == this->_tail)
            {
                this->_tail = node;
            }

            delete node->_next;
            node->_next = itr._node;
        }
    }

    template<class Datatype>
    void DLinkedList<Datatype>::removeBefore(DListIterator<Datatype>& itr)
    {
        DNode<Datatype>* node = this->_head;
        // Itr doesn't belong to this list
        if(itr._list != this) { return; }

        // Itr node isn't valid
        if(itr._node == nullptr) { return; }

        if(itr._node == this->_head)
        {
            itr.forth();
            this->removeHead();
        } else {
            // Find prior node of itr node
            while(node->_prev != itr._node)
            {
                node = node->_prev;
            }
            itr.forth();

            delete node->_prev;
            node->_prev = itr._node;
        }
    }

    template <class Datatype>
    DListIterator<Datatype> DLinkedList<Datatype>::getIterator()
    {
        return DListIterator<Datatype>(this);
    }


    template class DLinkedList<int>;
}