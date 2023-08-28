#include "binarytree.h"

int main() {
    std::vector<int> s;
    for (int i = 0; i <= 10; i++) s.push_back(i);
    BinaryTree<int> tree(s);
    std::cout << tree.printTreeLevelOrder() << std::endl;
    return 1;
}