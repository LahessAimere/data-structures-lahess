#include <iostream>
#include <algorithm>
#include <queue>
#include "Array.hpp"
#include "Node.hpp"
#include "NodeFactory.hpp"
#include "LinkedList.hpp"
#include "ListIterator.hpp"
#include "Tree.hpp"
#include "BinaryTree.hpp"

using namespace Data;

template <class Datatype>
void displayArray(Array<Datatype>& array);

template <class Datatype>
void displayLinkedList(LinkedList<Datatype>& list);

int main()
{
    std::cout << "Création d'un Array de type int" << std::endl;

    Array<int> intArr(5);

    std::cout << "Get intArr size: " << intArr.size() << std::endl;

    intArr[0] = 12;
    intArr[1] = 24;

    displayArray(intArr);

    intArr.insert(24, 1);

    displayArray(intArr);

    intArr.remove(0);

    displayArray(intArr);

    intArr.resize(3);

    displayArray(intArr);

    // Node

    Node<int>* n = NodeFactory<int>::createNode(10);


    LinkedList<int> list;
    list.prepend(10);
    list.prepend(5);
    list.prepend(55);
    ListIterator<int> itr(list);
    displayLinkedList(list);

    itr.start();
    std::cout << "Itr position: " << itr.item() << std::endl;

    itr.forth();
    std::cout << "Itr position: " << itr.item() << std::endl;

    std::cout << "Insert 4 after " << itr.item() << std::endl;
    list.insert(itr, 4);
    displayLinkedList(list);

    std::cout << "Removing item: " << itr.item() << std::endl;
    list.remove(itr);

    displayLinkedList(list);


    BinaryTree<int>* bRoot = new BinaryTree<int>();
    BinaryTree<int>* bItr;

    bRoot->setData(0);
    bRoot->setLeft(new BinaryTree<int>(1, bRoot));
    bRoot->setRight(new BinaryTree<int>(2, bRoot));

    bItr = bRoot;
    bItr = bItr->getLeft();
    bItr->setLeft(new BinaryTree<int>(3, bItr));
    bItr->setRight(new BinaryTree<int>(4, bItr));
    
    bItr = bItr->getParent();
    bItr = bItr->getRight();
    bItr->setLeft(new BinaryTree<int>(5, bItr));
    bItr->setRight(new BinaryTree<int>(6, bItr));

    // Now let's print the values of the tree nodes
    std::cout << "Values of the nodes in the binary tree:" << std::endl;

    std::cout << "Root node: " << bRoot->getData() << std::endl;
    std::cout << "Left child of the root: " << bRoot->getLeft()->getData() << std::endl;
    std::cout << "Right child of the root: " << bRoot->getRight()->getData() << std::endl;

    std::cout << "Left child of the left child of the root: " << bRoot->getLeft()->getLeft()->getData() << std::endl;
    std::cout << "Right child of the left child of the root: " << bRoot->getLeft()->getRight()->getData() << std::endl;

    std::cout << "Left child of the right child of the root: " << bRoot->getRight()->getLeft()->getData() << std::endl;
    std::cout << "Right child of the right child of the root: " << bRoot->getRight()->getRight()->getData() << std::endl;


    std::cout << "Post-order traversal of the tree: ";
    postOrderTraversal(bRoot);
    std::cout << std::endl;

    std::cout << "Inorder traversal of the tree:";
    inorderTraversal(bRoot);
    std::cout << std::endl;

    std::cout << "Pre-order traversal of the tree: ";
    preOrderTraversal(bRoot);
    std::cout << std::endl;

    int treeHeight = height(bRoot);
    std::cout << "Height of the tree: " << treeHeight << std::endl;

    int numberOfNodes = countNodes(bRoot);
    std::cout << "Number of nodes in the tree: " << numberOfNodes << std::endl;

    std::cout << "Level-order traversal of the tree: ";
    levelOrderTraversal(bRoot);
    std::cout << std::endl;

    
    delete bRoot->getRight()->getLeft();
    delete bRoot->getRight()->getRight();
    delete bRoot->getRight();
    delete bRoot->getLeft()->getLeft();
    delete bRoot->getLeft()->getRight();
    delete bRoot->getLeft();
    delete bRoot;

    return 0;
}

template <class Datatype>
void displayArray(Array<Datatype>& array)
{
    std::cout << "[ ";
    for(int i = 0; i < array.size(); ++i)
    {
        std::cout << array._array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

template <class Datatype>
void displayLinkedList(LinkedList<Datatype>& list)
{
    auto itr = list.getIterator();
    std::cout << "[ ";
    while(itr.isValid())
    {
        std::cout << itr.item() << " ";
        itr.forth();
    }
    std::cout << "]" << std::endl;
}

template<class Datatype>
void postOrderTraversal(BinaryTree<Datatype>* data) 
{
    if(data != nullptr) 
    {
        postOrderTraversal(data->getLeft());
        postOrderTraversal(data->getRight());
        std::cout << data->getData() << std::endl;
    }
}

template<class Datatype>
void inorderTraversal(BinaryTree<Datatype>* data) 
{
    if (data != nullptr) 
    {
        inorderTraversal(data->getLeft());
        std::cout << data->getData() << std::endl;
        inorderTraversal(data->getRight());
    }
}

template<class Datatype>
void preOrderTraversal(BinaryTree<Datatype>* data) 
{
    if (data != nullptr) 
    {
        std::cout << data->getData() << " ";
        preOrderTraversal(data->getLeft());
        preOrderTraversal(data->getRight());
    }
}

template<class Datatype>
int height(BinaryTree<Datatype>* data) 
{
    if (data == nullptr) 
    {
        return 0;
    }

    int leftHeight = height(data->getLeft());
    int rightHeight = height(data->getRight());

    return 1 + max(leftHeight, rightHeight);
}

template<class Datatype>
int countNodes(BinaryTree<Datatype>* data) 
{
    if (data == nullptr) 
    {
        return 0;
    }

    int leftNodes = countNodes(data->getLeft());
    int rightNodes = countNodes(data->getRight());

    return 1 + leftNodes + rightNodes;
}

template<class Datatype>
void levelOrderTraversal(BinaryTree<Datatype>* data) 
{
    if (data == nullptr)
        return;
    
    std::queue<BinaryTree<Datatype>*> queue;
    queue.push(data);

    while (!queue.empty()) 
    {
        BinaryTree<Datatype>* current = queue.front();
        queue.pop();
        std::cout << current->getData() << " ";

        if (current->getLeft() != nullptr)
            queue.push(current->getLeft());
        
        if (current->getRight() != nullptr)
            queue.push(current->getRight());
    }
}