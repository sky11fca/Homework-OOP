#include "Number.h"
#include <algorithm>

Number::Number(const char *value, int base) : value(value), base(base)
{
}

Number::Number(int value) : base(10)
{
    this->value = std::to_string(value);
}

Number::~Number()
{
}

Number::Number(const Number &other) : value(other.value), base(other.base)
{
}

Number::Number(Number &&other) : value(std::move(other.value)), base(other.base)
{
}
Number &Number::operator=(const Number &other)
{
    if (this != &other)
    {
        value = other.value;
        base = other.base;
    }
    return *this;
}

Number &Number::operator=(Number &&other)
{
    if (this != &other)
    {
        value = std::move(other.value);
        base = other.base;
    }
    return *this;
}

char &Number::operator[](int index)
{
    return value[index];
}

bool Number::operator>(const Number &other)
{
    return std::stoi(value, nullptr, base) > std::stoi(other.value, nullptr, base);
}

bool Number::operator<(const Number &other)
{
    return std::stoi(value, nullptr, base) < std::stoi(other.value, nullptr, base);
}

bool Number::operator>=(const Number &other)
{
    return std::stoi(value, nullptr, base) >= std::stoi(other.value, nullptr, base);
}

bool Number::operator<=(const Number &other)
{
    return std::stoi(value, nullptr, base) <= std::stoi(other.value, nullptr, base);
}

bool Number::operator==(const Number &other)
{
    return value == other.value && base == other.base;
}

Number Number::operator+(const Number &other)
{
    int maxBase = std::max(base, other.base);
    return Number(std::to_string(std::stoi(value, nullptr, base) + std::stoi(other.value, nullptr, other.base)), maxBase);
}

Number Number::operator-(const Number &other)
{
    int maxBase = std::max(base, other.base);
    return Number(std::to_string(std::stoi(value, nullptr, base) - std::stoi(other.value, nullptr, other.base)), maxBase);
}

Number &Number::operator+=(const Number &other)
{
    *this = *this + other;
    return *this;
}

Number &Number::operator-=(const Number &other)
{
    *this = *this - other;
    return *this;
}

Number &Number::operator--()
{
    value = value.substr(1);
    return *this;
}

Number Number::operator--(int)
{
    Number temp = *this;
    value.pop_back();
    return temp;
}

void Number::SwitchBase(int newBase)
{
    int decimalValue = std::stoi(value, nullptr, base);
    std::string newValue;
    while (decimalValue > 0)
    {
        int remainder = decimalValue % newBase;
        char digit = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
        newValue = digit + newValue;
        decimalValue /= newBase;
    }
    value = newValue;
    base = newBase;
}

void Number::Print()
{
   printf("%s", value);
}

int Number::GetDigitsCount()
{
    return value.size();
}

int Number::GetBase()
{
    return base;
}