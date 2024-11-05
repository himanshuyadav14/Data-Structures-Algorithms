#include<iostream>
using namespace std;

class Hero{
  
  //Properties;
  private:
  int health;

  public:
  char level;

  void print(){
    cout<<health<<endl;
  }

  int getHealth(){
    return health;
  }

  char getLevel(){
    return level;
  }

  void setHealth(int health){
    this->health = health;
  }

  void setLevel(int level){
    this->level = level;
  }
};