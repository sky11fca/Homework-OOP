#include <iostream>
#include "Tree.h"

bool compareInt(const int& a, const int& b) {
    return a < b;
}

bool isEqualTo15(const int& a) {
    return a == 15;
}

int main() {
    Tree<int> tree;

    auto root = tree.add_node(10);
    auto child1 = tree.add_node(20, root);
    auto child2 = tree.add_node(30, root);

    tree.add_node(40, child1);
    tree.add_node(50, child1);

    tree.insert(15, root, 1);

    tree.sort(root, compareInt);

    std::cout << "Count: " << tree.count() << std::endl;

    auto found = tree.find(isEqualTo15);
    if (found) {
        std::cout << "Found: " << found->value << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}