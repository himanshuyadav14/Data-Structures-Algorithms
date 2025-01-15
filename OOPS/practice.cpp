#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

atomic<bool> flag[2] = {false, false};
atomic<int> turn;

void critical_section(int id) {
    cout << "Process " << id << " is in the critical section.\n";
    this_thread::sleep_for(chrono::milliseconds(500)); // Simulate work
    cout << "Process " << id << " is leaving the critical section.\n";
}

void peterson(int id) {
    int other = 1 - id;

    // Entry section
    flag[id] = true;
    turn = other;
    while (flag[other] && turn == other) {
        // Busy wait
    }

    // Critical section
    critical_section(id);

    // Exit section
    flag[id] = false;
}

int main() {
    thread t1(peterson, 0);
    thread t2(peterson, 1);

    t1.join();
    t2.join();

    return 0;
}
