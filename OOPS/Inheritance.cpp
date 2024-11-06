#include <iostream>
using namespace std;
// Inheritance
class Human
{
public:
    int height;
    int weight;
    int age;

    int getAge()
    {
        return this->age;
    }

    void setWeight(int wt)
    {
        this->weight = wt;
    }
};

// Inherit
class Male : private Human
{
public:
    string color;

    void sleep()
    {
        cout << "Male is sleeping" << endl;
    }

    int getHeight(){
        return this->height;
    }
};

int main()
{
    Male object1;
    cout<<object1.getHeight()<<endl;

    // cout<<object1.age<<endl;
    // cout<<object1.height<<endl;
    // cout<<object1.weight<<endl;
    // cout<<object1.color<<endl;
    // object1.sleep();

    // object1.setWeight(30);
    // cout<<object1.weight<<endl;

    return 0;
}