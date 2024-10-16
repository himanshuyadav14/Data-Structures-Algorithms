#include<iostream>
#include<thread>
#include<unistd.h>  // for sleep function in Linux/Unix

using namespace std;

void taskA() {
    for (int i = 0; i < 10; i++) {
        sleep(1);  // Sleep for 1 second
        cout << "Task A : " << i << endl;
    }
}

void taskB() {
    for (int i = 0; i < 10; i++) {
        sleep(1);  // Sleep for 1 second
        cout << "Task B : " << i << endl;
    }
}

int main() {
    // Create two threads that execute taskA and taskB concurrently
    thread t1(taskA);
    thread t2(taskB);

    // Wait for both threads to finish
    t1.join();  // Join thread t1 to the main thread
    t2.join();  // Join thread t2 to the main thread

    return 0;
}
