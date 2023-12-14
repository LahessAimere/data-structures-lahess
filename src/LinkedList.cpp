#include "LinkedList.hpp"

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
    inline LinkedList<Datatype>::~LinkedList()
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
        //si ma liste est vide
        if (this->_head == nullptr)
        {
           this->_head = this->_tail = new Node<Datatype>;
           this->_head->_data = data;
        }
        else
        {
            this->_tail->insertAfter(data);
            this->_tail = this->_tail->_next;
        }
        this->_count++;
    }

    template<class Datatype>
    void LinkedList<Datatype>::prepend(Datatype data)
    {
        Node<Datatype>* newNode = new Node<Datatype>;
        newNode-> _data = data;
        newNode->_next = this->_head;
        this->_head = newNode;

        // Si la liste était initialement vide
        if (this->_tail == nullptr)
        {
            this->_tail = this->_head;
        }
        this->_count++;
    }

    template<class Datatype>
    void LinkedList<Datatype>::removeHead()
    {
        Node<Datatype>* node = nullptr;

        if (this->_head != nullptr)
        {
           node = this->_head->_next;
           delete this->_head;
           this->_head = node;
        }
        
        // Si la tête est nulle, le dernier noeud a été supprimé
        // Donc on set la queue à nul aussi
        if (this->_head == nullptr)
        {
            this->_tail = nullptr;
        }
        this->_count--;
    }

    template<class Datatype>
    void LinkedList<Datatype>::removeTail()
    {
        Node<Datatype>* node = this->_head;

        // Si il n'y a qu'un seul noeud
        if (this->_head == this->_tail)
        {
            delete this->_head;
            this->_head = this->_tail = nullptr;
        }
        else
        {
        //On parcours jusqu'à ce que le noeud ait pour successeur la tail
            while (node->_next != this->_tail)
            {
                node = node->_next;
            }

            this->_tail = node;
            delete node->_next;
            node->_next  = nullptr;
        }
        
        this->_count--;
    }
    template class LinkedList<int>;
    template class LinkedList<float>;
}