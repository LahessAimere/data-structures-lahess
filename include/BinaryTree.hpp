#ifndef _BINARY_TREE_HPP
#define _BINARY_TREE_HPP

namespace Data
{
    template<class Datatype>
    class BinaryTree
    {
        public:
        BinaryTree();
        BinaryTree(const Datatype& data, BinaryTree<Datatype>* parent = nullptr, BinaryTree<Datatype>* left = nullptr, BinaryTree<Datatype>* right = nullptr);
        ~BinaryTree();

        Datatype& getData();
        void setData(const Datatype& data);

        BinaryTree<Datatype>* getParent();
        void setParent(BinaryTree<Datatype>* parent);

        BinaryTree<Datatype>* getLeft();
        void setLeft(BinaryTree<Datatype>* left);

        BinaryTree<Datatype>* getRight();
        void setRight(BinaryTree<Datatype>* right);



        protected:
        Datatype _data;
        BinaryTree<Datatype>* _parent;
        BinaryTree<Datatype>* _left;
        BinaryTree<Datatype>* _right;
    };
}
#endif// _BINARY_TREE_HPP