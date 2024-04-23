#include <iostream>
using namespace std;

constexpr float operator"" _Kelvin(long double kelvin) {
    return kelvin - 273.15;
}

constexpr float operator"" _Fahrenheit(long double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout << "300 Kelvin is " << a << " Celsius." << endl;
    cout << "120 Fahrenheit is " << b << " Celsius." << endl;

    return 0;
}