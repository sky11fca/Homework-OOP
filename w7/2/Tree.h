template<typename T>
class TreeNode;

template<typename T>
class Tree {
private:
    TreeNode<T>* root;

public:
    Tree();
    ~Tree();

    TreeNode<T>* add_node(const T& value, TreeNode<T>* parent = nullptr);
    TreeNode<T>* get_node(TreeNode<T>* parent = nullptr);
    void delete_node(TreeNode<T>* node);
    TreeNode<T>* find(bool (*comparator)(const T&), TreeNode<T>* start = nullptr);
    void insert(const T& value, TreeNode<T>* parent, size_t index);
    void sort(TreeNode<T>* node, bool (*comparator)(const T&, const T&) = nullptr);
    size_t count(TreeNode<T>* node = nullptr);
};

#include "Tree.cpp"