#include "Tree.h"
#include "TreeNode.h"

template<typename T>
Tree<T>::Tree() : root(nullptr) {}

template<typename T>
Tree<T>::~Tree() {
    delete root;
}

template<typename T>
TreeNode<T>* Tree<T>::add_node(const T& value, TreeNode<T>* parent) {
    TreeNode<T>* newNode = new TreeNode<T>(value, parent);
    if (!root) {
        root = newNode;
    } else if (!parent) {
        newNode->sibling = root;
        root = newNode;
    } else if (!parent->child) {
        parent->child = newNode;
    } else {
        TreeNode<T>* sibling = parent->child;
        while (sibling->sibling) {
            sibling = sibling->sibling;
        }
        sibling->sibling = newNode;
    }
    return newNode;
}

template<typename T>
TreeNode<T>* Tree<T>::get_node(TreeNode<T>* parent) {
    if (!parent) {
        return root;
    }
    return parent->child;
}

template<typename T>
void Tree<T>::delete_node(TreeNode<T>* node) {
    if (!node) return;

    if (node->parent) {
        if (node->parent->child == node) {
            node->parent->child = node->sibling;
        } else {
            TreeNode<T>* prev = node->parent->child;
            while (prev->sibling != node) {
                prev = prev->sibling;
            }
            prev->sibling = node->sibling;
        }
    } else {
        root = node->sibling;
    }

    delete node;
}

template<typename T>
TreeNode<T>* Tree<T>::find(bool (*comparator)(const T&), TreeNode<T>* start) {
    if (!start) start = root;
    if (!start) return nullptr;

    if (comparator(start->value)) return start;

    TreeNode<T>* found = nullptr;

    if (start->child) {
        found = find(comparator, start->child);
    }
    if (!found && start->sibling) {
        found = find(comparator, start->sibling);
    }

    return found;
}

template<typename T>
void Tree<T>::insert(const T& value, TreeNode<T>* parent, size_t index) {
    TreeNode<T>* newNode = new TreeNode<T>(value, parent);

    if (!parent) {
        if (!root) {
            root = newNode;
            return;
        }
        newNode->sibling = root;
        root = newNode;
        return;
    }

    TreeNode<T>* current = parent->child;
    TreeNode<T>* prev = nullptr;
    size_t i = 0;
    while (current && i < index) {
        prev = current;
        current = current->sibling;
        ++i;
    }

    if (prev) {
        prev->sibling = newNode;
    } else {
        parent->child = newNode;
    }
    newNode->sibling = current;
}

template<typename T>
void Tree<T>::sort(TreeNode<T>* node, bool (*comparator)(const T&, const T&)) {
    if (!node) return;

    TreeNode<T>* current = node->child;
    while (current) {
        TreeNode<T>* minNode = current;
        TreeNode<T>* next = current->sibling;
        while (next) {
            if (!comparator && next->value < minNode->value) {
                minNode = next;
            } else if (comparator && comparator(next->value, minNode->value)) {
                minNode = next;
            }
            next = next->sibling;
        }
        if (minNode != current) {
            T temp = current->value;
            current->value = minNode->value;
            minNode->value = temp;
        }
        current = current->sibling;
    }

    current = node->child;
    while (current) {
        sort(current, comparator);
        current = current->sibling;
    }
}

template<typename T>
size_t Tree<T>::count(TreeNode<T>* node) {
    if (!node) node = root;
    if (!node) return 0;

    size_t count = 0;
    TreeNode<T>* current = node->child;
    while (current) {
        count++;
        count += count(current);
        current = current->sibling;
    }
    return count;
}