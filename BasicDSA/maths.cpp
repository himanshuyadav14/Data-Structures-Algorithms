#include<iostream>
using namespace std;
void printBinary(int n){
    for(int i=10; i>=0; i--){
        cout<<((n>>i)&1);
    }
    cout<<endl;
}
int main(){
    // printBinary(4);
    // printBinary(8 | (1<<i));
    
    return 0;
}

//For set the bit
// printBinary(a | (1<<1));

//for unset the bit
//printBinary(a&(~(1<<3)));

//For toggle the bit
// printBinary(a^(1<<2));

// __builtin_popcount();
// __builtin_popcountll();