#include <iostream>
#include "Array.hpp"
#include "Node.hpp"
#include "NodeFactory.hpp"
#include "LinkedList.hpp"
#include "ListIterator.hpp"
#include "Tree.hpp"

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

    //Tree
    
    // Création du nœud racine
    Data::Tree<int>* root = new Data::Tree<int>();
    root->_data = 1;

    // Création et ajout des enfants
    Data::Tree<int>* child1 = new Data::Tree<int>();
    child1->_data = 2;
    root->_children.append(child1);
    child1->_parent = root;

    Data::Tree<int>* child2 = new Data::Tree<int>();
    child2->_data = 3;
    root->_children.append(child2);
    child2->_parent = root;

    // Création et ajout des enfants de child2
    Data::Tree<int>* subChild1 = new Data::Tree<int>();
    subChild1->_data = 4;
    child2->_children.append(subChild1);
    subChild1->_parent = child2;

    Data::Tree<int>* subChild2 = new Data::Tree<int>();
    subChild2->_data = 5;
    child2->_children.append(subChild2);
    subChild2->_parent = child2;

    // Création et ajout des enfants de child1
    Data::Tree<int>* subChild3 = new Data::Tree<int>();
    subChild3->_data = 6;
    child1->_children.append(subChild3);
    subChild3->_parent = child1;

    // Affichage du nombre de nœuds dans l'arbre
    std::cout << "Nombre de noeuds dans l'arbre : " << root->count() << std::endl;

    // Destruction de l'arbre
    root->destroy();
    delete root;

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