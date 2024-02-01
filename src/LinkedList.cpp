#include "LinkedList.hpp"
#include "ListIterator.hpp"

namespace Data
{
    template<class Datatype>
    inline LinkedList<Datatype>::LinkedList()
    {
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_count = 0;
    }

    template<class Datatype>
    inline LinkedList<Datatype>::~LinkedList ()
    {
        Node<Datatype>* iterator = this->_head;
        Node<Datatype>* next;
        while(iterator != nullptr)
        {
            next = iterator->_next;
            delete iterator;
            iterator = next;
        }
    
    }

    template<class Datatype>
    void LinkedList<Datatype>::append(Datatype data)
    {
        if(this->_head == nullptr)
        {
            this->_head = this->_tail = new Node<Datatype>;
            this->_head->_data = data;
        } else {
            this->_tail->insertAfter(data);
            this->_tail = this->_tail->_next;
        }

        this->_count++;
    }

    template<class Datatype>
    void LinkedList<Datatype>::prepend(Datatype data)
    {
        Node<Datatype>* newNode = new Node<Datatype>;
        newNode->_data = data;
        newNode->_next = this->_head;
        this->_head = newNode;

        if(this->_tail == nullptr)
        {
            this->_tail = this->_head;
        }
        this->_count++;
    }

    template<class Datatype>
    void LinkedList<Datatype>::insert(ListIterator<Datatype>& itr, Datatype data)
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
    void LinkedList<Datatype>::removeHead()
    {
        Node<Datatype>* node = nullptr;
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
    void LinkedList<Datatype>::removeTail()
    {
        Node<Datatype>* node = this->_head;
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
    void LinkedList<Datatype>::remove(ListIterator<Datatype>& itr)
    {
        Node<Datatype>* node = this->_head;
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



    template <class Datatype>
    ListIterator<Datatype> LinkedList<Datatype>::getIterator()
    {
        return ListIterator<Datatype>(this);
    }


    template class LinkedList<int>;
}