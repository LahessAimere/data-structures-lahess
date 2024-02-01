#ifndef _DLIST_ITERATOR_HPP_
#define _DLIST_ITERATOR_HPP_

#include "DLinkedList.hpp"

namespace Data 
{
    template<class>
    class DLinkedList;
    
    template<class Datatype>
    class DListIterator
    {
        public:
        DNode<Datatype>* _node;
        DLinkedList<Datatype>* _list;

        DListIterator(DLinkedList<Datatype>* list = nullptr);
        DListIterator(DLinkedList<Datatype>& list = nullptr);

        void start();
        void forth();
        void backward();
        void end();

        Datatype& item();
        bool isValid();
        bool hasNext();
    };
}

#endif // _DLIST_ITERATOR_HPP_