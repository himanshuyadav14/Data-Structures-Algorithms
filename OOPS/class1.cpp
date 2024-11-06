#include<iostream>
#include "Hero.cpp"
using namespace std;

int main(){
    // Hero* ramesh = new Hero();//object instantiate //dynamic
    // cout<<"Size of: "<<sizeof(ramesh)<<endl;
    // cout<<"Level is: "<<ramesh->level<<endl;
    // // cout<<"Health is: "<<ramesh.health<<endl;
    // cout<<"Health is: "<<ramesh->getHealth()<<endl;
    // ramesh->print();

    // ramesh->setHealth(1);
    // ramesh->level = 70;
    // ramesh->print();
    
    Hero hero1;
    
    hero1.setHealth(10);
    hero1.setLevel('D');
    char name[] = "Himanshu";
    hero1.setName(name);

    hero1.print();

    //use default copy constructor
    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'G';
    hero1.print();

    hero2.print();

    return 0;
}