#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struct to represent a ticket
struct Passenger {
    string name;
    int age;
    char gender;
    string berth_preference;
};

// Function prototypes
void book_ticket(vector<Passenger>& booked_tickets, int& total_confirmed, int& total_rac, int& total_waiting);
void cancel_ticket(vector<Passenger>& booked_tickets, int& total_confirmed, int& total_rac, int& total_waiting);
void print_booked_tickets(const vector<Passenger>& booked_tickets);
void print_available_tickets(int total_confirmed, int total_rac, int total_waiting);

int main() {
    vector<Passenger> booked_tickets;
    int total_confirmed = 0;
    int total_rac = 0;
    int total_waiting = 0;

    int choice;
    while (true) {
        cout << "\nRailway Ticket Reservation System" << endl;
        cout << "1. Book Ticket" << endl;
        cout << "2. Cancel Ticket" << endl;
        cout << "3. Print Booked Tickets" << endl;
        cout << "4. Print Available Tickets" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                book_ticket(booked_tickets, total_confirmed, total_rac, total_waiting);
                break;
            case 2:
                cancel_ticket(booked_tickets, total_confirmed, total_rac, total_waiting);
                break;
            case 3:
                print_booked_tickets(booked_tickets);
                break;
            case 4:
                print_available_tickets(total_confirmed, total_rac, total_waiting);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

void book_ticket(vector<Passenger>& booked_tickets, int& total_confirmed, int& total_rac, int& total_waiting) {
    Passenger passenger;
    cout << "\nEnter passenger details:" << endl;
    cout << "Name: ";
    cin >> passenger.name;
    cout << "Age: ";
    cin >> passenger.age;
    cout << "Gender (M/F): ";
    cin >> passenger.gender;
    cout << "Berth Preference (Lower/Upper/Middle/SideLower/SideUpper): ";
    cin >> passenger.berth_preference;

    // Conditions for booking
    if (passenger.age < 5) {
        cout << "Children below age 5 are not allowed to book tickets." << endl;
        return;
    } else if (passenger.age >= 60 || (passenger.gender == 'F' && passenger.age >= 18)) {
        passenger.berth_preference = "Lower"; // Allocate lower berth for seniors and ladies with children
    }

    if (total_confirmed < 63) {
        booked_tickets.push_back(passenger);
        total_confirmed++;
        cout << "Ticket booked successfully." << endl;
    } else if (total_rac < 9) {
        booked_tickets.push_back(passenger);
        total_rac++;
        cout << "Ticket booked successfully in RAC." << endl;
    } else if (total_waiting < 10) {
        booked_tickets.push_back(passenger);
        total_waiting++;
        cout << "Ticket booked successfully in Waiting List." << endl;
    } else {
        cout << "No tickets available." << endl;
    }
}

void cancel_ticket(vector<Passenger>& booked_tickets, int& total_confirmed, int& total_rac, int& total_waiting) {
    cout << "\nEnter passenger name to cancel ticket: ";
    string name;
    cin >> name;

    // Find the passenger in booked tickets vector
    for (size_t i = 0; i < booked_tickets.size(); ++i) {
        if (booked_tickets[i].name == name) {
            if (booked_tickets[i].berth_preference == "Lower") {
                total_confirmed--;
            } else if (booked_tickets[i].berth_preference == "Upper") {
                total_rac--;
            } else if (booked_tickets[i].berth_preference == "Middle") {
                total_waiting--;
            }
            booked_tickets.erase(booked_tickets.begin() + i);
            cout << "Ticket for " << name << " cancelled successfully." << endl;
            return;
        }
    }
    cout << "Ticket not found." << endl;
}

void print_booked_tickets(const vector<Passenger>& booked_tickets) {
    cout << "\nBooked Tickets:" << endl;
    for (size_t i = 0; i < booked_tickets.size(); ++i) {
        const Passenger& passenger = booked_tickets[i];
        cout << "Name: " << passenger.name << ", Age: " << passenger.age << ", Gender: " << passenger.gender
             << ", Berth Preference: " << passenger.berth_preference << endl;
    }
    cout << "Total Booked Tickets: " << booked_tickets.size() << endl;
}

void print_available_tickets(int total_confirmed, int total_rac, int total_waiting) {
    cout << "\nAvailable Tickets:" << endl;
    cout << "Confirmed Tickets: " << 63 - total_confirmed << endl;
    cout << "RAC Tickets: " << 9 - total_rac << endl;
    cout << "Waiting List Tickets: " << 10 - total_waiting << endl;
}
