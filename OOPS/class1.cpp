#include<iostream>
#include "Hero.cpp"
using namespace std;

int main(){
    Hero ramesh;
    cout<<"Size of: "<<sizeof(ramesh)<<endl;
    cout<<"Level is: "<<ramesh.level<<endl;
    // cout<<"Health is: "<<ramesh.health<<endl;
    cout<<"Health is: "<<ramesh.getHealth()<<endl;
    ramesh.print();

    ramesh.setHealth(1);
    ramesh.level = 70;
    ramesh.print();
    return 0;
}