#include <iostream>

int main() {

    // basic integers
    auto a = 0xFF;
    auto b = 0x1234'5678ul;
    auto c = 0x1122'3344'5566'7788ull;

    std::cout << std::hex << std::showbase;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    // basic pointers
    auto a_ptr = (void *)0xFF;
    auto b_ptr = (void *)0x1234'5678ul;
    auto c_ptr = (void *)0x1122'3344'5566'7788ull;

    std::cout << a_ptr << std::endl;
    std::cout << b_ptr << std::endl;
    std::cout << c_ptr << std::endl;

    auto num = 0x1234;

    auto ptr = &num;
    std::cout << "ptr = " << ptr << std::endl;

    // read and write to memory
    std::cout << "*ptr = " << *ptr << std::endl;
    *ptr = 0x9999;

    std::cout << "num = " << num << std::endl;

    num = 1;
    for (char* i = (char*)0x5ffe30; i < (char*)0x5ffe40; ++i) {
        *i = (char)num++;
    }

    return 0;
}