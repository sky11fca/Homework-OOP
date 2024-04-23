template<typename T>
class TreeNode {
public:
    T value;
    TreeNode* parent;
    TreeNode* child;
    TreeNode* sibling;

    TreeNode(T val, TreeNode* p = nullptr)
        : value(val), parent(p), child(nullptr), sibling(nullptr) {}

    ~TreeNode();
};

#include "TreeNode.cpp"