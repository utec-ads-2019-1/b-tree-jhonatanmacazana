#ifndef BTREE_H
#define BTREE_H

#include "node.h"

template <typename T>
class BTree {
    private:
        Node<T>* root;
        unsigned int degree;
        int size;


    public:
        BTree(unsigned int degree) : degree(degree), root(nullptr){};

        bool search(int k) {
            if(root == nullptr) return false;
            return root->search(k);
        }

        bool insert(int k, T data = 0) {
            if(search(k)) return false;
            if(root == nullptr)
            {
                root = new Node<T>(degree, true);
                root->keys[0] = k;
                root->size = 1;
                return true;
            }
            if(root->size == 2*degree - 1)
            {
                Node<T> *newNode = new Node<T>(degree, true);
                newNode->childs[0] = root;
                newNode->splitNode(0, root);
                uint8_t i = 0;
                if(newNode->keys[0]<k) i = 1;
                newNode->childs[i]->insert(k);
                root = newNode;
                return true;
            }
            else return root->insert(k);
        }

        bool remove(int k) {
            // TODO
        }

        bool print() {
             if(!this->root) return false;
             return this->root->print();
        }

        ~BTree(){
            // TODO
        }
};

#endif