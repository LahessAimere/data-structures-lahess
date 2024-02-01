#ifndef _DLINKED_LIST_HPP_
#define _DLINKED_LIST_HPP_

#include "DNode.hpp"

namespace Data {
    template <class>
    class DListIterator;

    template<class Datatype>
    class DLinkedList
    {
        public:
        DNode<Datatype>* _head;
        DNode<Datatype>* _tail;
        int _count;

        DLinkedList();
        ~DLinkedList();

        void append(Datatype data);
        void prepend(Datatype data);
        void insertAfter(DListIterator<Datatype>& itr, Datatype data);
        void insertBefore(DListIterator<Datatype>& itr, Datatype data);

        void removeHead();
        void removeTail();
        void removeAfter(DListIterator<Datatype>& itr);
        void removeBefore(DListIterator<Datatype>& itr);

        DListIterator<Datatype> getIterator();
    };
}


#endif //_DLINKED_LIST_HPP_