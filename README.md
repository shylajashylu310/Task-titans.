//Write a C++ Program:

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;
    float marks;

public:
    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << left << setw(10) << rollNo
             << setw(20) << name
             << setw(10) << marks << endl;
    }

    int getRollNo() const {
        return rollNo;
    }
};

class StudentManager {
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        s.input();
        students.push_back(s);
        cout << "Student added successfully!\n";
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        cout << "\nStudent List:\n";
        cout << left << setw(10) << "Roll No"
             << setw(20) << "Name"
             << setw(10) << "Marks" << endl;
        cout << string(40, '-') << endl;

        for (const auto &s : students) {
            s.display();
        }
    }

    void saveToFile(const string &filename) const {
        ofstream outFile(filename, ios::out | ios::trunc);
        if (!outFile) {
            cerr << "File could not be opened!\n";
            return;
        }

        for (const auto &s : students) {
            outFile << s.getRollNo() << "," << s.name << "," << s.marks << "\n";
        }

        outFile.close();
        cout << "Data saved to file successfully.\n";
    }

    void loadFromFile(const string &filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "File not found. Starting with empty records.\n";
            return;
        }

        students.clear();
        Student s;
        string line;
        while (getline(inFile, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);

            s = Student();
            s.rollNo = stoi(line.substr(0, pos1));
            s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            s.marks = stof(line.substr(pos2 + 1));

            students.push_back(s);
        }

        inFile.close();
        cout << "Data loaded from file successfully.\n";
    }

    void searchByRoll(int roll) const {
        bool found = false;
        for (const auto &s : students) {
            if (s.getRollNo() == roll) {
                cout << "Record found:\n";
                cout << left << setw(10) << "Roll No"
                     << setw(20) << "Name"
                     << setw(10) << "Marks" << endl;
                cout << string(40, '-') << endl;
                s.display();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Student with Roll No " << roll << " not found.\n";
    }
};

int main() {
    StudentManager manager;
    manager.loadFromFile("students.txt");

    int choice, roll;

    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search by Roll Number\n";
        cout << "4. Save to File\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.displayAll();
                break;
            case 3:
                cout << "Enter Roll Number to search: ";
                cin >> roll;
                manager.searchByRoll(roll);
                break;
            case 4:
                manager.saveToFile("students.txt");
                break;
            case 5:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

//Write a c++ program on bank:
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class BankAccount {
    int accountNumber;
    char name[50];
    char accountType;
    float balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cin.ignore();
        cout << "Enter Account Holder Name: ";
        cin.getline(name, 50);
        cout << "Enter Account Type (S for Savings / C for Current): ";
        cin >> accountType;
        cout << "Enter Initial Deposit (>=500 for Savings, >=1000 for Current): ";
        cin >> balance;
        cout << "\nAccount Created Successfully!\n";
    }

    void showAccount() const {
        cout << "\nAccount No: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nType: "
