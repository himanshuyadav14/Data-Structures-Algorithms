#include <iostream>
#include <vector>
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
class Animal
{
public:
    virtual void speak() = 0;//pure virtual function (Abstract class)
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "bark....." << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Meow....." << endl;
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

    Animal *p;
    vector<Animal *> animals;

    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for (int i = 0; i < 5; i++)
    {
        p = animals[i];
        p->speak();
    }

    return 0;
}