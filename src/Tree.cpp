#include "Tree.hpp"

namespace Data
{
    template<class Datatype>
    inline Tree<Datatype>::Tree()
    {
        
    }

    template<class Datatype>
    inline Tree<Datatype>::~Tree()
    {
        for (Node* child = _children)
                {
                    delete child;
                }
    }

    template<class Datatype>
    int Tree<Datatype>::count()
    {
        if (this == nullptr)
        return 0;

        int countNode = 1;

        for (Node* child = _children)
        {
            countNode += count(child);
        }

    return countNode;
    }

    template<class Datatype>
    void Tree<Datatype>::destroy()
    {
        for (Node* child = _children)
        {
            child->destroy();
            delete child;
        }
        _children.clear();

        if (_parent != nullptr)
        {
            _parent->_children.remove(this);
        }
    }

    template class Tree<int>;
}