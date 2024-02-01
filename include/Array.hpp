#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

namespace Data {
    template<class Datatype>
    class Array
    {
        public:
        Datatype* _array;
        int _size;

        explicit Array (int size);

        virtual ~Array ();

        void resize (int size);

        void insert(Datatype item, int index);

        void remove(int index);

        // Getter

        int size ();

        Datatype& operator[] (int index);

        operator Datatype* ();
    };
    
}

#endif // _ARRAY_HPP_