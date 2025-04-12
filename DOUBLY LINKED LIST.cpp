#include <iostream>
#include <string>

using namespace std;

// Define the structure for a student node in a doubly linked list
struct Student {
	int id;             // Student ID
	string name;         // Student name
	char sex;            // Student sex (M/F)
	int age;             // Student age
	char grade;          // Student grade
	string department;    // Student department
	float gpa;           // Student GPA
	Student *next;       // Pointer to the next student node
	Student *prev;       // Pointer to the previous student node
};

// Define the class for Doubly Linked List
class DoublyLinkedList {
	private:
		Student *head;         // Pointer to the head of the list

	public:
		// Constructor to initialize the head pointer
		DoublyLinkedList() {
			head = NULL; // Initialize the head to null, indicating an empty list
		}

		// Function to create a new student node
		Student *createStudent(int id, string name, char sex, int age, char grade, string department, float gpa) {
			Student *newStudent = new Student(); // Allocate memory for a new student node
			newStudent->id = id;                 // Assign the provided ID
			newStudent->name = name;             // Assign the provided name
			newStudent->sex = sex;               // Assign the provided sex
			newStudent->age = age;               // Assign the provided age
			newStudent->grade = grade;           // Assign the provided grade
			newStudent->department = department; // Assign the provided department
			newStudent->gpa = gpa;               // Assign the provided GPA
			newStudent->next = NULL;          // Initialize the 'next' pointer to null
			newStudent->prev = NULL;          // Initialize the 'prev' pointer to null
			return newStudent;                   // Return the newly created student node
		}

		// Function to insert a student at the beginning of the list
		void insertAtBeginning(int id, string name, char sex, int age, char grade, string department, float gpa) {
			Student *newStudent = createStudent(id, name, sex, age, grade, department, gpa); // Create a new student node
			if (head == NULL) { // If the list is empty
				head = newStudent; // Make the new student the head
			} else { // If the list is not empty
				newStudent->next = head; // New student's 'next' points to the current head
				head->prev = newStudent; // Current head's 'prev' points to the new student
				head = newStudent;       // Update the head to the new student
			}
			cout << "Student inserted at the beginning." << endl;
		}

		// Function to insert a student at the end of the list
		void insertAtEnd(int id, string name, char sex, int age, char grade, string department, float gpa) {
			Student *newStudent = createStudent(id, name, sex, age, grade, department, gpa); // Create a new student node
			if (head == NULL) { // If the list is empty
				head = newStudent; // Make the new student the head
				return;
			}
			Student *temp = head; // Start from the head
			while (temp->next != NULL) { // Traverse to the last node
				temp = temp->next;
			}
			temp->next = newStudent; // Link the last node's 'next' to the new student
			newStudent->prev = temp; // Link the new student's 'prev' to the last node
			cout << "Student inserted at the end." << endl;
		}

		// Function to insert a student at a specific position
		void insertAtPosition(int position, int id, string name, char sex, int age, char grade, string department, float gpa) {
			if (position <= 0) { // If the position is invalid
				cout << "Invalid position. Position should be greater than 0." << endl;
				return;
			}
			if (position == 1) { // If the position is the beginning
				insertAtBeginning(id, name, sex, age, grade, department, gpa);
				return;
			}

			Student *newStudent = createStudent(id, name, sex, age, grade, department, gpa); // Create a new student node
			Student *current = head;   // Start from the head
			int count = 1;         // Initialize a counter for the current position

			while (current != NULL && count < position - 1) { // Traverse to the node before the desired position
				current = current->next;
				count++;
			}

			if (current == NULL) { // If the previous node is null (position out of bounds)
				cout << "Position exceeds the length of the list." << endl;
				delete newStudent; // Clean up allocated memory
				return;
			}

			newStudent->next = current->next; // Link the new node's 'next' to the node at the desired position
			newStudent->prev = current;      // Link the new node's 'prev' to the previous node
			if (current->next != NULL) { // If there is a node after the insertion point
				current->next->prev = newStudent; // Update the 'prev' of the node after the insertion point
			}
			current->next = newStudent;      // Link the previous node's 'next' to the new node
			cout << "Student inserted at position " << position << "." << endl;
		}

		// Function to delete a student from the beginning of the list
		void deleteAtBeginning() {
			if (head == NULL) { // If the list is empty
				cout << "List is empty. Cannot delete." << endl;
				return;
			}
			Student *temp = head; // Store the current head
			head = head->next;   // Move the head to the next node
			if (head != NULL) { // If the list is not now empty
				head->prev = NULL; // Set the 'prev' of the new head to null
			}
			delete temp;          // Delete the old head
			cout << "Student deleted from the beginning." << endl;
		}

		// Function to delete a student from the end of the list
		void deleteAtEnd() {
			if (head == NULL) { // If the list is empty
				cout << "List is empty. Cannot delete." << endl;
				return;
			}
			if (head->next == NULL) { // If there is only one node
				delete head; // Delete the head
				head = NULL;  // Set head to null
				return;
			}
			Student *current = head; // Start from the head
			while (current->next != NULL) { // Traverse to the last node
				current = current->next;
			}
			current->prev->next = NULL; // Set the 'next' of the second last node to null
			delete current;    // Delete the last node
			cout << "Student deleted from the end." << endl;
		}

		// Function to delete a student at a specific position
		void deleteAtPosition(int position) {
			if (head == NULL) { // If the list is empty
				cout << "List is empty. Cannot delete." << endl;
				return;
			}
			if (position <= 0) { // If the position is invalid
				cout << "Invalid position. Position should be greater than 0." << endl;
				return;
			}
			if (position == 1) { // If the position is the beginning
				deleteAtBeginning();
				return;
			}

			Student *current = head; // Start from the head
			int count = 1;         // Initialize a counter for the current position

			while (current != NULL && count < position) { // Traverse to the node at the desired position
				current = current->next;
				count++;
			}

			if (current == NULL) { // If the current node is null (position out of bounds)
				cout << "Position exceeds the length of the list." << endl;
				return;
			}

			current->prev->next = current->next; // Update the 'next' of the previous node
			if (current->next !=NULL) { // If there is a node after the one to be deleted
				current->next->prev = current->prev; // Update the 'prev' of the next node
			}
			delete current;    // Delete the node at the specified position
			cout << "Student deleted from position " << position << "." << endl;
		}

		// Function to display all students in the list
		void displayStudents() {
			if (head == NULL) { // If the list is empty
				cout << "List is empty." << endl;
				return;
			}
			Student *current = head; // Start from the head
			cout << "\nStudent Records:" << endl;
			while (current != NULL) { // Traverse the list until the end
				cout << "ID: " << current->id << endl;
				cout << "Name: " << current->name << endl;
				cout << "Sex: " << current->sex << endl;
				cout << "Age: " << current->age << endl;
				cout << "Grade: " << current->grade << endl;
				cout << "Department: " << current->department << endl;
				cout << "GPA: " << current->gpa << endl;
				cout << "---" << endl;
				current = current->next; // Move to the next node
			}
		}
};

int main() {
	DoublyLinkedList studentList; // Create an instance of the DoublyLinkedList class
	int choice;                   // Variable to store user's choice
	int id, age;                  // Variables to store student ID and age
	char sex, grade;              // Variables to store student sex and grade
	string name, department;      // Variables to store student name and department
	float gpa;                    // Variable to store student GPA
	int position;                 // Variable to store the position for insertion/deletion

	do {
		cout << "\nMenu: Doubly Linked List Operations:" << endl;
		cout << "1. Insert at the Beginning" << endl;
		cout << "2. Insert at the End" << endl;
		cout << "3. Insert at a Specific Position" << endl;
		cout << "4. Delete from the Beginning" << endl;
		cout << "5. Delete from the End" << endl;
		cout << "6. Delete from a Specific Position" << endl;
		cout << "7. Display Students" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice; // Get user's choice

		switch (choice) {
			case 1: // Insert at the Beginning
				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Sex (M/F): ";
				cin >> sex;
				cout << "Enter Age: ";
				cin >> age;
				cout << "Enter Grade: ";
				cin >> grade;
				cout << "Enter Department: ";
				cin >> department;
				cout << "Enter GPA: ";
				cin >> gpa;
				studentList.insertAtBeginning(id, name, sex, age, grade, department, gpa);
				break;

			case 2: // Insert at the End
				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Sex (M/F): ";
				cin >> sex;
				cout << "Enter Age: ";
				cin >> age;
				cout << "Enter Grade: ";
				cin >> grade;
				cout << "Enter Department: ";
				cin >> department;
				cout << "Enter GPA: ";
				cin >> gpa;
				studentList.insertAtEnd(id, name, sex, age, grade, department, gpa);
				break;

			case 3: // Insert at a Specific Position
				cout << "Enter the position to insert at: ";
				cin >> position;
				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Sex (M/F): ";
				cin >> sex;
				cout << "Enter Age: ";
				cin >> age;
				cout << "Enter Grade: ";
				cin >> grade;
				cout << "Enter Department: ";
				cin >> department;
				cout << "Enter GPA: ";
				cin >> gpa;
				studentList.insertAtPosition(position, id, name, sex, age, grade, department, gpa);
				break;

			case 4: // Delete from the Beginning
				studentList.deleteAtBeginning();
				break;

			case 5: // Delete from the End
				studentList.deleteAtEnd();
				break;

			case 6: // Delete from a Specific Position
				cout << "Enter the position to delete from: ";
				cin >> position;
				studentList.deleteAtPosition(position);
				break;

			case 7: // Display Students
				studentList.displayStudents(); // Corrected this line
				break;

			case 0: // Exit
				cout << "Exiting program." << endl;
				break;

			default: // Invalid choice
				cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0); // Continue the loop until the user chooses to exit

	return 0; // Indicate successful program execution
}
