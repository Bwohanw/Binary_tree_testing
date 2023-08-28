#pragma once
#include "binarytree.h"

template <typename T>
BinaryTree<T>::BinaryTree() : root(NULL) {}

template <typename T>
BinaryTree<T>::BinaryTree(std::vector<T> vec) : root(NULL) {
      BuildTreeLevelOrder(vec, 0, 0, root);
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
      clear(root);
}

template <typename T>
void BinaryTree<T>::clear(Node<T>* tree) {
      if (tree == NULL) return;
      clear(tree->left);
      clear(tree->right);
      delete tree;
      tree = NULL;
}

template <typename T>
std::string BinaryTree<T>::printTreeLevelOrder() {
      std::string output;
      if (root == NULL) return output;
      std::queue<Node<T>*> q;
      std::queue<std::string> q2;
      q.push(root);
      q2.push("root");
      while (!q.empty()) {
            Node<T>* temp = q.front();
            q.pop();
            std::string loc = q2.front();
            q2.pop();
            if (temp->left != NULL) {
                  q.push(temp->left);
                  q2.push(loc + "->left");
            }
            if (temp->right != NULL) {
                  q.push(temp->right);
                  q2.push(loc + "->right");
            }
            output = output + loc + ": " + std::to_string(temp->data) + " ";
      }
      return output;
}


template <typename T>
size_t BinaryTree<T>::getIndex(size_t dim, size_t level) {
      size_t product = 1;
      for (size_t i = 0; i < level; i++) product *= 2;
      for (size_t i = 0; i < dim; i++) product += 1;
      return product-1;
}

template <typename T>
size_t BinaryTree<T>::twoPower(size_t level) {
      size_t product = 1;
      for (int i = 0; i < level; i++) product *= 2;
      return product;
}

/*Builds a binary tree using a vector such that the level order traversal of it matches the vector passed in
Does this by looking at the current level and the dim, which represents which node from left to right of the current level
it is, and uses that to construct it

Example:
                root level: 0
            /         \
      right1            left1 level: 1, dim from left to right: 0,1
      /        \       /     \
      right2 left2  right3  left3 level: 2, dim from right to left: 0, 1, 2, 3*/
template <typename T>
void BinaryTree<T>::BuildTreeLevelOrder(std::vector<T> vec, size_t dim, size_t level, Node<T>*& root) {
      size_t index = getIndex(dim, level);
      //std::cout << "level: " << level << "dim: " << dim << std::endl;
      if (index >= vec.size()) return;
      root = new Node<T>;
      root->data = vec[index];
      root->left = NULL;
      root->right = NULL;
      //checks if we're supposed to move down a level or not
      /*if (level == 0 || twoPower(level) <= dim-1) {
            BuildTreeInOrder(vec, 0, level+1, leftmost->left, leftmost->left);
            BuildTreeInOrder(vec, 1, level+1, leftmost->right, leftmost->right);
      } else {*/
            BuildTreeLevelOrder(vec, 2*dim, level+1, root->left);
            BuildTreeLevelOrder(vec, 2*dim+1, level+1, root->right);
      //}
      
}