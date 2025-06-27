#include <iostream>
#include <vector>
#include <string>
using namespace std;

// A Seat holds a number and passenger's name
struct Seat {
    int number;
    string passenger;
};

// A Bus has details + 32 seats
class Bus {
    string number, driver, arrival, departure, from, to;
    vector<Seat> seats;

public:
    Bus(string no, string d, string arr, string dep, string f, string t)
        : number(no), driver(d), arrival(arr), departure(dep), from(f), to(t) {
        for (int i = 1; i <= 32; ++i)
            seats.push_back({i, ""}); // All seats empty at start
    }

    string getNumber() { return number; }

    void showDetails() {
        cout << "Bus: " << number << ", Driver: " << driver
             << ", From: " << from << " To: " << to
             << ", Arrival: " << arrival << ", Departure: " << departure << endl;
    }

    void showSeats() {
        for (auto &seat : seats) {
            cout << "Seat " << seat.number << ": ";
            cout << (seat.passenger.empty() ? "Available" : seat.passenger) << endl;
        }
    }

    void bookSeat(int seatNo, string name) {
        if (seatNo < 1 || seatNo > 32) {
            cout << "Invalid seat number.\n";
            return;
        }

        if (seats[seatNo - 1].passenger.empty()) {
            seats[seatNo - 1].passenger = name;
            cout << "Seat " << seatNo << " booked for " << name << "!\n";
        } else {
            cout << "Sorry, seat already booked.\n";
        }
    }
};

// This class manages multiple buses
class BusManager {
    vector<Bus> buses;

public:
    void addBus(string no, string d, string arr, string dep, string f, string t) {
        buses.push_back(Bus(no, d, arr, dep, f, t));
        cout << "Bus added!\n";
    }

    void showAllBuses() {
        for (auto &b : buses)
            b.showDetails();
    }

    void showSeats(string busNo) {
        for (auto &b : buses) {
            if (b.getNumber() == busNo) {
                b.showSeats();
                return;
            }
        }
        cout << "Bus not found.\n";
    }

    void reserveSeat(string busNo, int seatNo, string name) {
        for (auto &b : buses) {
            if (b.getNumber() == busNo) {
                b.bookSeat(seatNo, name);
                return;
            }
        }
        cout << "Bus not found.\n";
    }
};

// Main menu
int main() {
    BusManager manager;
    int choice;

    do {
        cout << "\n--- Bus Reservation Menu ---\n";
        cout << "1. Add Bus\n";
        cout << "2. Book Seat\n";
        cout << "3. Show Seats\n";
        cout << "4. Show All Buses\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string no, driver, arr, dep, from, to;
            cout << "Bus Number: "; cin >> no;
            cout << "Driver: "; cin >> driver;
            cout << "Arrival Time: "; cin >> arr;
            cout << "Departure Time: "; cin >> dep;
            cout << "From: "; cin >> from;
            cout << "To: "; cin >> to;
            manager.addBus(no, driver, arr, dep, from, to);
        }
        else if (choice == 2) {
            string no, name;
            int seat;
            cout << "Bus Number: "; cin >> no;
            cout << "Seat Number (1-32): "; cin >> seat;
            cout << "Passenger Name: "; cin >> name;
            manager.reserveSeat(no, seat, name);
        }
        else if (choice == 3) {
            string no;
            cout << "Bus Number: "; cin >> no;
            manager.showSeats(no);
        }
        else if (choice == 4) {
            manager.showAllBuses();
        }
        else if (choice == 5) {
            cout << "Thank you for using the system!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
