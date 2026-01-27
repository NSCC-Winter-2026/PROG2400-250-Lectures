#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

class LinkedList {
    struct Node {
        int data {-1};
        Node* next {nullptr};
    };

    Node* _start {nullptr};

public:
    void add(int data);

    /// inserts nodes in the linked list
    /// the linked list starts at index 1
    /// @param data the data to insert
    /// @param before_idx the index of the node to insert before
    void insert(int data, int before_idx);

    /// deletes a node in the linked list
    /// @param data the data of the node to delete
    void remove(int data);

#if 0
    void list();
    void list(int lineno);
    void list(int start, int end);
#endif

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
};

std::ostream& operator<<(std::ostream& os, const LinkedList& list);

#endif