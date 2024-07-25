#include<iostream>
using namespace std;

class Kqueues{
    int *arr;
    int *front;
    int *next;
    int *rear;
    int freeSpot;
    int n, k;

    public:
        Kqueues(int n, int k){
            this->n = n;
            this->k = k;
            arr = new int[n];
            next = new int[n];
            front = new int[k];
            rear = new int[k];
            freeSpot = 0;

            for(int i=0; i<k; i++){
                front[i] = -1;
                rear[i] = -1;
            }

            for(int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
        }

        void push(int data, int qn){
            //overflow condition
            if(freeSpot == -1){
                cout<<"No Empty spaces is present"<<endl;
                return;
            }

            //find first free index
            int index = freeSpot;

            //update freeSpot
            freeSpot = next[index];

            //check weather first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }else{
                //Link new element to the previous element
                next[rear[qn-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        int pop(int qn){
            //underflow
            if(front[qn-1] == -1){
                return -1;
            }

            //find index to pop
            int index = front[qn-1];

            //front update
            front[qn-1] = next[index];

            //freeSlots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;

            return arr[index];
        }
};

int main(){
    Kqueues q(20,3);
    
    q.push(34,1);
    q.push(30,1);
    q.push(20,2);
    q.push(25,1);

    cout<<q.pop(1)<<endl;
    cout<<q.pop(2)<<endl;
    cout<<q.pop(2)<<endl;

    return 0;
}