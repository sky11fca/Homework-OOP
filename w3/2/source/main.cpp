#include <iostream>
#include "../headers/canvas.h"

int main() {
    Canvas canvas(20, 10);

    canvas.DrawLine(1, 1, 18, 8, '*');
    canvas.DrawRect(3, 3, 15, 7, '#');
    canvas.FillRect(5, 5, 10, 6, '@');
    canvas.DrawCircle(14, 3, 3, '&');
    canvas.FillCircle(5, 8, 2, '%');

    std::cout << "Before Clear:" << std::endl;
    canvas.Print();
    
    canvas.Clear();

    std::cout << "After Clear:" << std::endl;
    canvas.Print();

    return 0;
}