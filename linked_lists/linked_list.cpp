#include "linked_list.h"

void LinkedList::add(const int data) {
    const auto node = new Node{data};

    // am I the first node in the chain?
    if (_start == nullptr) {
        // yep! I must be the first node!
        _start = node;
    } else {
        // no, I can't be since the _start is already pointing to something

        auto curr = _start;
        auto prev = static_cast<Node *>(nullptr);

        // let's find the end of the chain
        while (curr != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        // we should have found the end of the chain
        // curr == nullptr
        // prev == the last node

        // attach node to the end of the chain
        if (prev != nullptr) {
            prev->next = node;
        }
    }
}

/// inserts nodes in the linked list
/// the linked list starts at index 1
/// @param data the data to insert
/// @param before_idx the index of the node to insert before
void LinkedList::insert(const int data, const int before_idx) {
    auto node = new Node{data};

    // find the node to insert before
    auto curr = _start;
    auto prev = static_cast<Node *>(nullptr);

    auto index = 1;
    while (curr != nullptr) {
        if (index++ == before_idx) break;
        prev = curr;
        curr = curr->next;
    }

    // are we inserting before the first node?
    if (prev == nullptr) {
        // yes! we are!
        node->next = _start;
        _start = node;
    } else {
        // either add or insert depending on whether the index was found
        node->next = prev->next;
        prev->next = node;
    }
}

/// deletes a node in the linked list
/// @param data the data of the node to delete
void LinkedList::remove(const int data) {
    auto curr = _start;
    auto prev = static_cast<Node *>(nullptr);

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

#if 0
void list() {
    list(1, numlines);
}
void list(const int lineno) {
    list(lineno, lineno);
}
void list(const int start, const int end) {
}
#endif


std::ostream &operator<<(std::ostream &os, const LinkedList &list) {
    auto node = list._start;

    while (node != nullptr) {
        os << node->data << " ";
        node = node->next;
    }
    return os;
}
