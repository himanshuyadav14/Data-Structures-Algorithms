#include <iostream>
using namespace std;

// compile type polymorphism
// function overloading
class Poly
{
public:
    void fun()
    {
        cout << "I am a function with no arguments" << endl;
    }

    void fun(int x)
    {
        cout << "I am a function with int arguments" << endl;
    }

    void fun(double x)
    {
        cout << "I am a function with double arguments" << endl;
    }
};

// Operator overloading
class Complex
{
private:
    int real, imag;

public:
    // Parameterized constructor
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    // Overloading the + operator
    Complex operator+(Complex const &obj)
    {
        Complex res(0, 0);
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }

    // Display function
    void display()
    {
        cout << real << " + i" << imag << endl;
    }
};

// Run time polymorphism
// function overriding
class Base
{
public:
    virtual void print()
    {
        cout << "This is Base class print function" << endl;
    }

    void display()
    {
        cout << "This is the Base class display function" << endl;
    }
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "This is Derived class print function" << endl;
    }

    void display()
    {
        cout << "This is the Dervied class display function" << endl;
    }
};

int main()
{
    Poly obj;
    obj.fun();
    obj.fun(4);
    obj.fun(6.0);

    Complex c1(12, 7), c2(6, 7);
    Complex c3 = c1 + c2;
    c3.display();

    Base *basePointer;
    
    Derived d;
    basePointer = &d;

    
    basePointer->print();
    basePointer->display();
    
    return 0;
}