#include <iostream>
#include <optional>

struct Data {
    int num {-1};
    std::string id;
};
std::ostream& operator<<(std::ostream& os, const Data& data) {
    os << "num: " << data.num << ", id: " << data.id;
    return os;
}

class Stack {
    struct Node {
        Data data;
        Node* next {nullptr};
    };

    Node* _top {nullptr};
public:
    virtual ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    void push(const Data& data) {
        const auto node = new Node {data};

        node->next = _top;
        _top = node;
    }

    [[nodiscard]] std::optional<Data> top() const {
        if (_top == nullptr) return std::nullopt;
        return std::make_optional<Data>(_top->data);
    }

    void pop() {
        const auto node = _top;
        _top = _top->next;
        delete node;
    }

    [[nodiscard]] bool empty() const {
        return _top == nullptr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
};

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
    auto node = stack._top;
    while (node != nullptr) {
        os << node->data << std::endl;
        node = node->next;
    }
    return os;
}

int main() {

    Stack stack;

    // test 1 : add items to the stack
    std::cout << "Test 1: add items to the stack" << std::endl;
    std::cout << "------------------------------" << std::endl;

    stack.push({1, "one"});
    stack.push({2, "two"});
    stack.push({3, "three"});
    stack.push({4, "four"});
    stack.push({5, "five"});

    std::cout << stack << std::endl;

    // test 2 : remove items from the stack
    std::cout << "Test 2: remove items from the stack" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    if (stack.top().has_value()) {
        std::cout << stack.top().value() << std::endl;
        stack.pop();
        std::cout << stack << std::endl;
    }

    // test 3 : remove all items from the stack
    std::cout << "Test 3: remove all items from the stack" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    while (!stack.empty()) {
        std::cout << stack.top().value_or(Data {999, "stupid id"}) << std::endl;
        stack.pop();
        std::cout << stack << std::endl;
    }

    return 0;
}