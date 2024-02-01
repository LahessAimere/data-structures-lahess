#ifndef _NODE_FACTORY_HPP_
#define _NODE_FACTORY_HPP_

#include "Node.hpp"

namespace Data
{
    template <class T>
    class NodeFactory {
    public:
    static Node<T>* createNode(T data) {
        return new Node<T>(data);
    }
    };
}

#endif // _NODE_FACTORY_HPP_