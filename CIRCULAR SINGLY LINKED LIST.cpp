#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    int age;
    string department;
    float gpa;

    Student(int id, string fName, string lName, int age, string dept, float gpa)
        : id(id), firstName(fName), lastName(lName), age(age), department(dept), gpa(gpa) {}
};

class Node {
public:
    Student data;
    Node* next;

    Node(Student student) : data(student), next(nullptr) {};
};

class CircularSinglyLinkedList {
private:
    Node* tail;

public:
    CircularSinglyLinkedList() : tail(nullptr) {}

    void insertAtBeginning(Student student) {
        Node* newNode = new Node(student);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail; // Point to itself
        } else {
            newNode->next = tail->next; // New node points to the first node
            tail->next = newNode; // Last node points to new node
        }
    }

    void insertAtEnd(Student student) {
        Node* newNode = new Node(student);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail; // Point to itself
        } else {
            newNode->next = tail->next; // New node points to the first node
            tail->next = newNode; // Last node points to new node
            tail = newNode; // Update tail to new node
        }
    }

    void insertAtPosition(Student student, int position) {
        if (position <= 1) {
            insertAtBeginning(student);
            return;
        }

        Node* newNode = new Node(student);
        Node* current = tail->next;

        for (int i = 1; i < position - 1 && current->next != tail->next; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        if (current == tail) { // Update tail if inserted at the end
            tail = newNode;
        }
    }

    void deleteFromBeginning() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* toDelete = tail->next; // First node
        if (toDelete == tail) { // Only one node
            delete toDelete;
            tail = nullptr;
        } else {
            tail->next = toDelete->next; // Bypass the first node
            delete toDelete;
        }
    }

    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = tail->next;
        if (current == tail) { // Only one node
            delete current;
            tail = nullptr;
            return;
        }

        while (current->next != tail) {
            current = current->next; // Find the second-to-last node
        }

        delete tail; // Delete the last node
        current->next = tail->next; // Bypass the last node
        tail = current; // Update tail
    }

    void deleteAtPosition(int position) {
        if (tail == nullptr || position < 1) {
            cout << "Invalid position or list is empty." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* current = tail->next;

        for (int i = 1; i < position - 1 && current->next != tail->next; i++) {
            current = current->next;
        }

        if (current->next == tail->next) {
            cout << "Position out of bounds." << endl;
            return;
        }

        Node* toDelete = current->next;
        current->next = toDelete->next;

        if (toDelete == tail) { // Update tail if deleting the last node

ChatGPT 4.5 | DeepSeek | Midjourney, [4/5/2025 3:55 AM]
            tail = current;
        }

        delete toDelete;
    }

    void display() const {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* current = tail->next; // Start from the first node
        do {
            cout << "ID: " << current->data.id 
                 << ", Name: " << current->data.firstName << " " << current->data.lastName 
                 << ", Age: " << current->data.age 
                 << ", Department: " << current->data.department 
                 << ", GPA: " << current->data.gpa << endl;
            current = current->next;
        } while (current != tail->next);
    }

    ~CircularSinglyLinkedList(); {
        while (tail != nullptr) {
            deleteFromBeginning();
        }
    }
};

void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Insert at Beginning\n";
    cout << "2. Insert at End\n";
    cout << "3. Insert at Specific Position\n";
    cout << "4. Delete from Beginning\n";
    cout << "5. Delete from End\n";
    cout << "6. Delete from Specific Position\n";
    cout << "7. Display List\n";
    cout << "8. Exit\n";
}

int main() {
    CircularSinglyLinkedList list;
    int choice;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, age;
                string firstName, lastName, department;
                float gpa;

                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Department: ";
                cin >> department;
                cout << "Enter GPA: ";
                cin >> gpa;

                list.insertAtBeginning(Student(id, firstName, lastName, age, department, gpa));
                break;
            }
            case 2: {
                int id, age;
                string firstName, lastName, department;
                float gpa;

                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Department: ";
                cin >> department;
                cout << "Enter GPA: ";
                cin >> gpa;

                list.insertAtEnd(Student(id, firstName, lastName, age, department, gpa));
                break;
            }
            case 3: {
                int id, age, position;
                string firstName, lastName, department;
                float gpa;

                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Department: ";
                cin >> department;
                cout << "Enter GPA: ";
                cin >> gpa;

                cout << "Enter Position: ";
                cin >> position;

                list.insertAtPosition(Student(id, firstName, lastName, age, department, gpa), position);
                break;
            }
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6: {
                int position;
                cout << "Enter Position to Delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;
            }
            case 7:
                list.display();
                break;
            case 8:

ChatGPT 4.5 | DeepSeek | Midjourney, [4/5/2025 3:55 AM]
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
