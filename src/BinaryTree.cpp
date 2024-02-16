#include "BinaryTree.hpp"

namespace Data
{
    template <class Datatype>
    inline BinaryTree<Datatype>::BinaryTree()
    {
        this->_data = Datatype(0);
        this->_parent = nullptr;
        this->_left = nullptr;
        this->_right = nullptr;
    }

    template <class Datatype>
    inline BinaryTree<Datatype>::BinaryTree(const Datatype& data, BinaryTree<Datatype>* parent, BinaryTree<Datatype>* left, BinaryTree<Datatype>* right)
    {
        this->_data = data;
        this->_parent = parent;
        this->_left = left;
        this->_right = right;
    }

    template <class Datatype>
    inline BinaryTree<Datatype>::~BinaryTree()
    {   
        if (this->_left /*!= nullptr* c'est la même chose*/)
        {
            delete this->_left;
        }
        if (this->_right)
        {
            delete this->_right;
        }
    }

    template <class Datatype>
    Datatype& BinaryTree<Datatype>::getData()
    {
        return this->_data;
    }

    template <class Datatype>
    void BinaryTree<Datatype>::setData(const Datatype& data)
    {
        this->_data = data;
    }

    template <class Datatype>
    BinaryTree<Datatype>* BinaryTree<Datatype>::getParent()
    {
        return this->_parent;
    }
    
    template <class Datatype>
    void BinaryTree<Datatype>::setParent(BinaryTree<Datatype>* parent)
    {
        this->_parent = parent;
    }

    template <class Datatype>
    BinaryTree<Datatype>* BinaryTree<Datatype>::getLeft()
    {
        return this->_left;
    }

    template <class Datatype>
    void BinaryTree<Datatype>::setLeft(BinaryTree<Datatype>* left)
    {
        this->_left = left;
    }

    template <class Datatype>
    BinaryTree<Datatype>* BinaryTree<Datatype>::getRight()
    {
        return this->_right;
    }

    template <class Datatype>
    void BinaryTree<Datatype>::setRight(BinaryTree<Datatype>* right)
    {
        this->_right = right;
    }

    template class BinaryTree<int>;
}