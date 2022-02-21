#ifndef _LINKNODE_
#define _LINKNODE_


template<class T>
class LinkNode
{
    template<class T>
    friend class LinkList;
public:
    LinkNode(){next = NULL;}
private:
    T data;
    LinkNode<T>* next;
};

#endif