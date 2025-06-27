#include <iostream>
#include <string>
using namespace std;

// Define the structure of a node in the linked list
struct Student {
    int id;
    string name;
    int age;
    Student* next; // Pointer to the next node
};

// Head pointer for the linked list
Student* head = nullptr;

// Function to add a new record
void addRecord() {
    Student* newStudent = new Student;
    cout << "Enter Student ID: ";
    cin >> newStudent->id;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, newStudent->name);
    cout << "Enter Student Age: ";
    cin >> newStudent->age;
    newStudent->next = nullptr;

    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    cout << "Record added successfully.\n";
}

// Function to search for a record
void searchRecord() {
    if (head == nullptr) {
        cout << "No records found.\n";
        return;
    }

    int searchID;
    cout << "Enter Student ID to search: ";
    cin >> searchID;

    Student* temp = head;
    while (temp != nullptr) {
        if (temp->id == searchID) {
            cout << "Record Found:\n";
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Age: " << temp->age << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Record not found.\n";
}

// Function to modify a record
void modifyRecord() {
    if (head == nullptr) {
        cout << "No records found.\n";
        return;
    }

    int modifyID;
    cout << "Enter Student ID to modify: ";
    cin >> modifyID;

    Student* temp = head;
    while (temp != nullptr) {
        if (temp->id == modifyID) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, temp->name);
            cout << "Enter new Age: ";
            cin >> temp->age;
            cout << "Record updated successfully.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Record not found.\n";
}

// Function to delete a record
void deleteRecord() {
    if (head == nullptr) {
        cout << "No records found.\n";
        return;
    }

    int deleteID;
    cout << "Enter Student ID to delete: ";
    cin >> deleteID;

    if (head->id == deleteID) {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Record deleted successfully.\n";
        return;
    }

    Student* current = head;
    Student* previous = nullptr;

    while (current != nullptr && current->id != deleteID) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Record not found.\n";
    } else {
        previous->next = current->next;
        delete current;
        cout << "Record deleted successfully.\n";
    }
}

// Function to display all records
void displayRecords() {
    if (head == nullptr) {
        cout << "No records to display.\n";
        return;
    }

    Student* temp = head;
    cout << "\nStudent Records:\n";
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", Age: " << temp->age << endl;
        temp = temp->next;
    }
}

// Function to display the menu
void menu() {
    int choice;
    do {
        cout << "\nStudent Information System\n";
        cout << "1. Add New Record\n";
        cout << "2. Search Record\n";
        cout << "3. Modify Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Display All Records\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(); break;
            case 2: searchRecord(); break;
            case 3: modifyRecord(); break;
            case 4: deleteRecord(); break;
            case 5: displayRecords(); break;
            case 6: cout << "Exiting the system. Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
