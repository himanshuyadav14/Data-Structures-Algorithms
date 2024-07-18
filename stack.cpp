#include<iostream>
#include<stack>
using namespace std;

class Stack{
    //properties
    public:
        int *arr;
        int size;
        int top;
    
    //behaviour
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
         if(size - top > 1){
            top++;
            arr[top] = element;
         }else{
            cout<<"Stack Overflow"<<endl;
         }
    }

    void pop(){
        if(top>=0){
            top--;
        }else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top >= 0 && top < size){
            return arr[top];
        }
    }

    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }
};

int main(){
    
    Stack st(5);
    
    st.push(22);
    st.push(43);
    st.push(44);

    st.pop();

    cout<<st.peek();

    return 0;
}