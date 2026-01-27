#ifndef LINKED_LIST_TEST
#define LINKED_LIST_TEST

#include "linked_list.h"

class LinkedListTest {
    std::string _filename;
    LinkedList _list;

    void test_add();
    void test_remove_node();
    void test_remove_first_node();
    void test_insert_in_the_middle();
    void test_insert_at_invalid_index();
    void test_insert_at_start();

public:
    explicit LinkedListTest(std::string filename);

    void run();
};

#endif