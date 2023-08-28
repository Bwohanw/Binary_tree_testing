#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>

template <typename T>
struct Node{
    T data;
    Node<T>* right;
    Node<T>* left;
};

template <typename T>
class BinaryTree {
    public:
    BinaryTree();
    BinaryTree(std::vector<T> vec);
    ~BinaryTree();
    std::string printTreeLevelOrder();
    private:
    Node<T>* root;
    void clear(Node<T>* node);
    void BuildTreeLevelOrder(std::vector<T> vec, size_t dim, size_t level, Node<T>*& root);
    size_t getIndex(size_t dim, size_t level);
    size_t twoPower(size_t level);
};

#include "binarytree.hpp"