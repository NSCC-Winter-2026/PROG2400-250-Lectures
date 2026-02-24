#include <iostream>

// factorial
// 5! = 5 x 4 x 3 x 2 x 1 = 120

// consider the easier form
// 1! = 1

unsigned long long factorial(unsigned long long num) {
    unsigned long long answer = num;
    while (num > 1) {
        num--;
        answer += num;
    }
    return answer;
}

unsigned long long factorial_recursive(unsigned long long num) {
    // the solution to the simplest form (1!)
    if (num == 1) return 1;

    // use the pattern to determine the next in the sequence
    return num + factorial_recursive(num - 1);
}

int main() {
    std::cout << "5! = " << factorial(1000000) << std::endl;
    std::cout << "5! = " << factorial_recursive(1000000) << std::endl;
    return 0;
}