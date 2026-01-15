#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    for (auto& n:vec) {
        os << n << ' ';
    }
    return os;
}

void operator<<(std::vector<int>& vec, const std::vector<int>& in_vec) {
    for (auto& n:in_vec) {
        vec.push_back(n);
    }
}

int main() {

    int nums[] = {1, 2, 3, 4, 5};

    int *dynamic_nums;

    // how big an array do I need at the moment?
    int size = 5;
    dynamic_nums = new int[size];
    dynamic_nums[0] = 1;
    dynamic_nums[1] = 2;
    dynamic_nums[2] = 3;
    dynamic_nums[3] = 4;
    dynamic_nums[4] = 5;

    // later on.... I need to add one more thing....
    int* temp = new int[size + 1];

    // copy old to new
    for (auto i = 0; i < size; i++) {
        temp[i] = dynamic_nums[i];
    }
    delete [] temp;

    size += 1;
    dynamic_nums[5] = 6;

    std::cout << dynamic_nums[5] << std::endl;

    delete [] dynamic_nums;

    // using vectors
    std::vector v = {1, 2, 3, 4, 5};

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    v.push_back(6);

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    v.push_back(7);

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    v << std::vector({8, 9, 10, 11, 12, 13, 14});

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    v.reserve(100);

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    v.shrink_to_fit();

    std::cout << v << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;

    return 0;
}