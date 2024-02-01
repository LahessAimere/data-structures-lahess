#include <iostream>
#include "Array.hpp"
#include "Node.hpp"
#include "NodeFactory.hpp"
#include "LinkedList.hpp"
#include "ListIterator.hpp"

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