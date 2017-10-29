//
// Created by Rounak on 29/10/17.
//

#ifndef STACK_CHAINNODE_H
#define STACK_CHAINNODE_H
template<class T>
class LinkedListChain;

template<class T>
class ChainNode {
public:
    friend class LinkedListChain<T>;

private:
    T data;
    ChainNode<T> *link;
};
#endif //STACK_CHAINNODE_H
