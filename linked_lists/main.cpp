#include <iostream>

class LinkedList {
    struct Node {
        int data {-1};
        Node* next {nullptr};
    };

    Node* _start {nullptr};

public:
    void add(const int data) {
        auto node = new Node {data};

        // am I the first node in the chain?
        if (_start == nullptr) {
            // yep! I must be the first node!
            _start = node;
        } else {
            // no, I can't be since the _start is already pointing to something

            auto curr = _start;
            auto prev = static_cast<Node*>(nullptr);

            // let's find the end of the chain
            while (curr != nullptr) {
                prev = curr;
                curr = curr->next;
            }

            // we should have found the end of the chain
            // curr == nullptr
            // prev == the last node

            // attach node to the end of the chain
            prev->next = node;
        }
    }

    /// deletes a node in the linked list
    /// @param data the data of the node to delete
    void remove(const int data) {

        auto curr = _start;
        auto prev = static_cast<Node*>(nullptr);

        // find the node to delete
        while (curr != nullptr) {
            if (curr->data == data) break;
            prev = curr;
            curr = curr->next;
        }

        // did I find the node to delete?
        if (curr != nullptr) {
            // yep! I found it!

            // is this the first node?
            if (prev == nullptr) {
                // yes! it is the first node!
                _start = curr->next;
            } else {
                // nope.. just another node
                // detach node from the chain
                prev->next = curr->next;
            }

            // now that it is detached, I can delete it!
            delete curr;
        } else {
            std::cout << "The node doesn't exist." << std::endl;
        }
    }

    void list() {
        list(1, numlines);
    }
    void list(const int lineno) {
        list(lineno, lineno);
    }
    void list(const int start, const int end) {

    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
};

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    auto node = list._start;

    while (node != nullptr) {
        os << node->data << " ";
        node = node->next;
    }
    return os;
}

int main() {

    LinkedList list;

    // test 1 - add some nodes to the linked list

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    std::cout << "Test 1 - add nodes to list" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 2 - delete a node from the list

    // delete the node with the value 3
    list.remove(3);

    std::cout << "Test 2 - delete node from list" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 3 - delete the first node from the list

    // delete the node with the value 1
    list.remove(1);

    std::cout << "Test 3 - delete the first node from list" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << list << std::endl;

    return 0;
}