#ifndef RBT_9_4_H
#define RBT_9_4_H
//20202995 장진영
#include <cassert>

template<class queueElementType>
class Queue{
public:
    Queue();
    ~Queue();
    void enqueue(queueElementType e);
    queueElementType dequeue();
    queueElementType front();
    bool isEmpty();
private:
    struct Node;
    typedef Node* nodePtr;
    struct Node{
        queueElementType data;
        nodePtr next;
    };
    nodePtr f;
    nodePtr r;
};

template <class queueElementType>
Queue <queueElementType > ::Queue()
{
    f=0;
    r=0;
}

template <class queueElementType>
Queue <queueElementType> :: ~Queue()
{
    while (f != 0) {
        nodePtr delNode(f);
        f = f->next;
        delete delNode;
    }
}

template <class queueElementType>
void Queue <queueElementType > ::enqueue(queueElementType e)
{
    nodePtr n(new Node);
    assert(n);
    n->next =0;
    n->data = e;
    if(f!=0){
        r->next =n;
        r=n;
    }
    else{
        f=n;
        r=n;
    }
}
template <class queueElementType>
queueElementType Queue <queueElementType > ::dequeue()
{
    assert(f);
    nodePtr n(f);
    queueElementType frontElement(f->data);
    f=f->next;
    delete n;
    if(f==0)
        r=0;
    return frontElement;
}

template <class queueElementType>
queueElementType Queue <queueElementType > ::front()
{
    assert(f);
    return f->data;
}

template <class queueElementType>
bool Queue <queueElementType > ::isEmpty()
{
    return bool(f==0);
}

#endif //RBT_9_4_H
