#include <iostream>
#include "Array.hpp"
#include "Node.hpp"
#include "LinkedList.hpp"

using namespace Data;

template<class Datatype>
void displayArray(Array<Datatype>& array);

template<class Datatype>
void displayList(LinkedList<Datatype>& list);

int main()
{
    std::cout << "Création des tableau et iniitalisations" << std::endl;

    Array<int> arrayInt(5);
    //Array<float> arrayFloat(10);
    displayArray(arrayInt);
    
    std::cout << "#Implémentation du tableau" << std::endl;
    arrayInt[0] = 12;
    arrayInt[1] = 24;
    arrayInt[2] = 2;
    arrayInt[3] = 8;
    arrayInt[4] = 6;

    displayArray(arrayInt);
    std::cout << "#Redimmension de tableau" << std::endl;
    arrayInt.resize(8);
    
    displayArray(arrayInt);
    std::cout << "#Insertion d'une valeur'" << std::endl;
    arrayInt.insert(87, 2);

    displayArray(arrayInt);
    std::cout << "#Retirer une valeur'" << std::endl;
    arrayInt.remove(3);

    displayArray(arrayInt);

    LinkedList<int> list;
    list.append(0);
    list.append(1);
    list.append(2);
    displayList(list);

    list.prepend(3);
    displayList(list);

    list.removeHead();
    displayList(list);

    list.removeTail();
    displayList(list);


    LinkedList<float> list;
    list.append(0.5);
    list.append(1.5);
    list.append(2.8);
    displayList(list);

    list.prepend(3.2);
    displayList(list);

    list.removeHead();
    displayList(list);

    list.removeTail();
    displayList(list);

    return 0;
}

template<class Datatype>
void displayArray(Array<Datatype>& array)
{
    std::cout << "[";
    for (int i = 0; i < array._size; i++)
    {
        std::cout << array._array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

template<class Datatype>
void displayList(LinkedList<Datatype>& list)
{
    Node<Datatype>* node = list._head;

    if (node != nullptr)
    {
        while (node != nullptr)
        {
            std::cout << node->_data;
            std::cout << "->";
            node = node->_next;
        }
        std::cout <<std::endl;
    }
}