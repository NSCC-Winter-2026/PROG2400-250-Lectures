#include <iostream>
#include <sstream>

int main() {

    std::string user_input;
    std::string command;


    std::cout << "Enter a command and two numbers: ";
    std::getline(std::cin, user_input);

    std::stringstream ss(user_input);
    ss >> command;

    if (command.length() > 1) {
        std::cout << "You entered some text: ";
        std::cout << user_input << std::endl;
    } else {
        std::cout << "You may have entered a command." << std::endl;

        if (!ss.eof()) {
            std::cout << "There is still stuff in the stream!" << std::endl;

            // try to extract the start number
            auto start = -1;
            ss >> start;

            if (ss.fail()) {
                ss.clear();
                std::cout << "You entered some text." << std::endl;
            } else {
                auto end = -1;
                ss >> end;
                if (ss.fail()) {
                    ss.clear();
                    std::cout << "You entered some text." << std::endl;
                } else {
                    std::cout << "You may have entered a command." << std::endl;

                    std::cout << "command: " << command;
                    std::cout << ", start: " << start;
                    std::cout << ", end: " << end << std::endl;
                }
            }
        }
    }


    return 0;
}