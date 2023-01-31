#include "..\\header\Stack_LinkedList_Based.h"

template <class type>
Stack_LinkedList_Based<type>::Stack_LinkedList_Based()
{
}

template <class type>
Stack_LinkedList_Based<type>::~Stack_LinkedList_Based()
{
    while (is_empty())
        pop();
}
