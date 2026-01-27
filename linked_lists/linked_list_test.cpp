#include "linked_list_test.h"

LinkedListTest::LinkedListTest(std::string filename) : _filename(std::move(filename)) {

}


void LinkedListTest::test_add() {
    // test 1 - add some nodes to the linked list

    _list.add(1);
    _list.add(2);
    _list.add(3);
    _list.add(4);
    _list.add(5);

    std::cout << "Test 1 - add nodes to list" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << _list << std::endl;
}

void LinkedListTest::test_remove_node() {
    // test 2 - delete a node from the list

    // delete the node with the value 3
    _list.remove(3);

    std::cout << "Test 2 - delete node from list" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << _list << std::endl;
}

void LinkedListTest::test_remove_first_node() {
    // test 3 - delete the first node from the list

    // delete the node with the value 1
    _list.remove(1);

    std::cout << "Test 3 - delete the first node from list" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << _list << std::endl;
}

void LinkedListTest::test_insert_in_the_middle() {
    // test 4 - insert in the middle of the list

    // insert the node with the value 10 before the node with index 2
    _list.insert(10, 2);

    std::cout << "Test 4 - insert a node in the middle" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << _list << std::endl;
}

void LinkedListTest::test_insert_at_invalid_index() {
    // test 5 - insert at an invalid index

    // insert the node with the value 11 before the node with index 20
    _list.insert(11, 20);

    std::cout << "Test 5 - insert a node at an invalid index" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << _list << std::endl;
}

void LinkedListTest::test_insert_at_start() {
    // test 6 - insert at the start of the chain

    // insert the node with the value 12 before the node with index 1
    _list.insert(12, 1);

    std::cout << "Test 6 - insert a node before index 1" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << _list << std::endl;
}

void LinkedListTest::run() {

    test_add();
    test_remove_node();
    test_remove_first_node();
    test_insert_in_the_middle();
    test_insert_at_invalid_index();
    test_insert_at_start();
}
