#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int>q;
    q.push(17);
    q.push(11);
    q.push(1);
    q.push(7);
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;

    cout<<q.front()<<endl;
    cout<<q.back();

    return 0;
}