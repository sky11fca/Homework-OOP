#include <string>
using namespace std;

class Number
{
   string value;
   int base;
public:
   Number(const char * value, int base); // where base is between 2 and 16
   Number(int value);
    ~Number();

   // add operators and copy/move constructor

   Number(const Number &other);            // Copy constructor
   Number(Number &&other);                 // Move constructor
   Number &operator=(const Number &other); // Copy assignment operator
   Number &operator=(Number &&other);      // Move assignment operator

   char &operator[](int index);            // Index operator
   bool operator>(const Number &other);    // Relation operators
   bool operator<(const Number &other);
   bool operator>=(const Number &other);
   bool operator<=(const Number &other);
   bool operator==(const Number &other);
   Number operator+(const Number &other);   // Addition
   Number operator-(const Number &other);   // Subtraction
   Number &operator+=(const Number &other); // Compound addition
   Number &operator-=(const Number &other); // Compound subtraction
   Number &operator--();                    // Prefix decrement
   Number operator--(int);   

   void SwitchBase(int newBase);
   void Print();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base
};