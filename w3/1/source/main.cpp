#include <iostream>
#include "../headers/Math.h"

int main() {
    // Examples of using Math class methods
    std::cout << "Addition of 5 and 7: " << Math::Add(5, 7) << std::endl;
    std::cout << "Multiplication of 3 and 4: " << Math::Mul(3, 4) << std::endl;
    std::cout << "Addition of 1.5 and 2.5: " << Math::Add(1.5, 2.5) << std::endl;
    std::cout << "Multiplication of 2.5 and 3.5: " << Math::Mul(2.5, 3.5) << std::endl;
    std::cout << "Sum of 3 integers (3, 6, 9): " << Math::Add(3, 3, 6, 9) << std::endl;
    std::cout << "Sum of 4 integers (4, 8, 12, 16): " << Math::Add(4, 4, 8, 12, 16) << std::endl;

    char* concatenated_string = Math::Add("Hello, ", "world!");
    if (concatenated_string != nullptr) {
        std::cout << "Concatenated string: " << concatenated_string << std::endl;
        delete[] concatenated_string;
    } else {
        std::cout << "One of the strings is null!" << std::endl;
    }

    return 0;
}