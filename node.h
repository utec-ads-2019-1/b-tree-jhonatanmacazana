#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

template <typename T>
class BTree;

template <typename T>
class Node {
    unsigned int size;
    vector<unsigned int> keys;
    vector<Node<T>*> childs;
    bool isLeaf;

    public:
        Node(unsigned int Size, bool IsLeaf = true) :
        size(Size),
        isLeaf(IsLeaf)
        {
            keys.resize(Size - 1);
            childs.resize(Size);
        }

        bool search(int k)
        {
            uint8_t i = 0;
            while (i<size && keys[i] < k) i++;
            if(keys[i] == k) return true;
            if(!isLeaf) childs[i]->search(k);
            return false;
        }

        bool insert(int k)
        {
            //TODO
            if(isLeaf)
            {

            }
            return true;

        }

        bool splitNode(int k, Node<T> *node)
        {
            //TODO
            return true;
        }

        bool print()
        {
            if(!isLeaf)
            {
                for (int i = 0; i < size; ++i)
                {
                    childs[i]->print();
                    printf("%d\t", keys[i]);
                }
            }
            else
            {
                for (int i = 0; i < size; ++i)
                    printf("%d\t", keys[i]);
            }
            return true;
        }


    friend class BTree<T>;
};

#endif