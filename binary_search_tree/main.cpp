#include <iostream>
#include <iomanip>

struct KeyValue {
    int key;
    std::string value;
};

class BST {
    struct Node;
    using NodePtr = Node*;
    struct Node {
        KeyValue data {-1};
        NodePtr left {nullptr};
        NodePtr right {nullptr};
    };

    NodePtr _root {nullptr};
public:
    void insert(const KeyValue& data) {
        insert(data, _root);
    }

    void remove(const int key) {

        auto node = _root;
        auto parent = static_cast<NodePtr>(nullptr);

        // find the node to delete
        while (node != nullptr) {
            if (key < node->data.key) {
                // traverse the left path
                parent = node;
                node = node->left;
            } else if (key > node->data.key) {
                // traverse the right path
                parent = node;
                node = node->right;
            } else {
                // found the node to delete
                break;
            }
        }

        // did I find the node to delete?
        if (node == nullptr) return; // nope, so just return

        // do I have a child?

        // start by assuming there is left child
        NodePtr subtree = node->left;

        // if no left child, assume a right child
        if (subtree == nullptr) {
            subtree = node->right;
        }

        // is this node on the right or left side of the parent?
        if (parent->left == node) {
            // we are on the parent's left side
            parent->left = subtree; // disconnect node from parent
        } else if (parent->right == node) {
            // we are on the parent's right side
            parent->right = subtree; // disconnect node from parent
        }

        delete node;
    }

private:
    void insert(const KeyValue& data, NodePtr& node) {
        if (node == nullptr) {
            node = new Node {data};
        } else if (data.key < node->data.key) {
            // traverse to the left
            insert(data, node->left);
        } else if (data.key > node->data.key) {
            // traverse to the right
            insert(data, node->right);
        } else {
            std::cout << "Node value " << data.key << " already exists." << std::endl;
        }
    }

    void print_tree(std::ostream& os, const NodePtr& node, const int level) {
        if (node != nullptr) {
            print_tree(os, node->right, level + 8);
            os << std::setw(level) << node->data.key << std::endl;
            print_tree(os, node->left, level + 8);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, BST& bst);
};

std::ostream& operator<<(std::ostream& os, BST& bst) {
    bst.print_tree(os, bst._root, 0);
    return os;
}

int main() {

    BST bst;

    // test 1 - add nodes to the tree
    std::cout << "Test 1 - add nodes to the tree" << std::endl;
    std::cout << "------------------------------" << std::endl;

    bst.insert({5, "five"});
    bst.insert({3, "three"});
    bst.insert({7, "seven"});
    bst.insert({2, "two"});
    bst.insert({4, "four"});
    bst.insert({6, "six"});
    bst.insert({8, "eight"});

    std::cout << bst << std::endl;

    // test 2 - delete a node with node children
    std::cout << "Test 2 - delete a node with no child" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    bst.remove(2);

    std::cout << bst << std::endl;

    // test 3 - delete a node with one child
    std::cout << "Test 3 - delete a node with one child" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    bst.remove(3);

    std::cout << bst << std::endl;

    return 0;
}