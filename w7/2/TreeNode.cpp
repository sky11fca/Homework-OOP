#include "TreeNode.h"

template<typename T>
TreeNode<T>::~TreeNode() {
    delete child;
    delete sibling;
}