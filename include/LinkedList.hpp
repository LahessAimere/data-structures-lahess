#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include "Node.hpp"

namespace Data
{
    template<class Datatype>
    class LinkedList
    {
    public:
        Node<Datatype>* _head;
        Node<Datatype>* _tail;
        int _count;

        LinkedList();
        ~LinkedList();

        void append(Datatype data);
        void prepend(Datatype data);

        void removeHead();
        void removeTail();
    };
}
#endif // LINKED_LIST_HPP
