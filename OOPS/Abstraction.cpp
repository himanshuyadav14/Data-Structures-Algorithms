#include <iostream>
using namespace std;

class Hero
{
    // Properties;
private:
    int health;

public:
    char *name;
    char level;
    static int timeToComplete;

    Hero()
    {
        cout << "constructor called" << endl;
        name = new char[100];
    }

    // copy constructor for deep copy
    Hero(Hero &temp)
    {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);

        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print()
    {
        cout << endl;
        cout << "[ Name is: " << name << ",";
        cout << " Health is: " << health << ",";
        cout << " Level is: " << level << " ]";
        cout << endl;
    }

    // Getter/ Setter
    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    void setHealth(int health)
    {
        this->health = health;
    }

    void setLevel(int level)
    {
        this->level = level;
    }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    ~Hero()
    {
        cout << "Destructor called" << endl;
    }

    static int random()
    {
        return timeToComplete;
    }
};