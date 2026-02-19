#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll: " << roll 
             << " | Name: " << name 
             << " | Marks: " << marks << endl;
    }
};

void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);
    s.input();
    file << s.roll << " " << s.name << " " << s.marks << endl;
    file.close();
    cout << "Student record added successfully!\n";
}

void viewStudents() {
    ifstream file("students.txt");
    Student s;
    while (file >> s.roll >> s.name >> s.marks) {
        s.display();
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. View Students\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 3);

    return 0;
}
