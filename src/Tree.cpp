#include "Tree.hpp"

namespace Data
{
    template<class Datatype>
    inline Tree<Datatype>::Tree()
    {
        this->_data = Datatype(0);
        this->_parent = nullptr;
    }

    template<class Datatype>
    inline Tree<Datatype>::Tree(Datatype data)
    {
        this->_data = data;
        this->_parent = nullptr;
    }

    template<class Datatype>
    inline Tree<Datatype>::~Tree()
    {
        this->destroy();
    }

    template<class Datatype>
    int Tree<Datatype>::count()
    {
        if (this == nullptr)
        return 0;

        int countNode = 1;

        DListIterator<Node*> itr = this->_children;
        for (itr.start(); itr.isValid(); itr.forth())
        {
            countNode += itr.item()->count();
        }
    return countNode;
    }

    template<class Datatype>
    void Tree<Datatype>::destroy()
    {
        DListIterator<Node*> itr(this->_children);
        Node* node = nullptr;
        itr.start();
        while (itr.isValid())
        {
            node = itr.item();
            this->_children.removeAfter(itr);
        }
    }

    template class Tree<int>;
}