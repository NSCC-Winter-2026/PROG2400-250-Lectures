#include <iostream>

struct Student {
    std::string name {"uninitialized name"};
    std::string id {"W000000"};
};
std::ostream& operator<<(std::ostream& os, const Student& data) {
    os << data.name << " (" << data.id << ")";
    return os;
}

class Queue {
    struct Node {
        Student data;
        Node* next {nullptr};
    };

    Node* _front {nullptr};
    Node* _back {nullptr};

public:
    void push_back(const Student& data) {
        const auto node = new Node({data});

        // is this the first node in the queue
        if (_front == nullptr) {
            _front = node;
            _back = node;
        } else {
            _back->next = node;
            _back = node;
        }
    }

    [[nodiscard]] Student front() const {
        // -1 means an empty queue
        return _front != nullptr ? _front->data : Student {"empty queue?"};
    }

    void pop_front() {

        const auto temp = _front;

        // is this the last node?
        if (_front == _back) {
            _front = nullptr;
            _back = nullptr;
        } else {
            // disconnect node from front of queue
            _front = _front->next;
        }

        // delete the node
        delete temp;
    }

    [[nodiscard]] bool empty() const {
        return _front == nullptr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue& queue);
};

std::ostream& operator<<(std::ostream& os, const Queue& queue) {
    auto node = queue._front;
    while (node != nullptr) {
        os << node->data << std::endl;
        node = node->next;
    }
    return os;
}

int main() {

    Queue queue;

    // test 1 : add some data to the queue
    std::cout << "Test 1: add data to the queue" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    queue.push_back({"John Smith", "W111111"});
    queue.push_back({"Jane Doe", "W222222"});
    queue.push_back({"Jill Hill", "W333333"});
    queue.push_back({"Jack Sprat", "W444444"});
    queue.push_back({"Bill Hill", "W555555"});

    std::cout << queue << std::endl;

    // test 2 : get data from the front of the queue
    std::cout << "Test 2: read data from the queue" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    std::cout << queue.front() << std::endl;

    // test 3 : remove some data from the queue
    std::cout << "Test 3: remove data from the queue" << std::endl;
    std::cout << "----------------------------------" << std::endl;

    queue.pop_front();
    std::cout << queue << std::endl;

    // test 4 : remove all data from the queue
    std::cout << "Test 4: remove all data from the queue" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    while (!queue.empty()) {
        queue.pop_front();
        std::cout << queue << std::endl;
    }

    return 0;
}