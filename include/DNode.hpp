#ifndef _DNODE_HPP_
#define _DNODE_HPP_

namespace Data {
    template<class Datatype>
    class DNode
    {
        public:
        Datatype _data;
        DNode<Datatype>* _next;
        DNode<Datatype>* _prev;

        DNode();
        DNode(Datatype data);
        ~DNode();

        void insertAfter(Datatype data);
        void insertBefore(Datatype data);
        
    };
}


#endif // _DNODE_HPP_