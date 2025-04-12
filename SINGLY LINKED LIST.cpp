#include <iostream>
#include <string>

using namespace std;

// Define the structure for a Student node
struct Student {
	int id;                     // Student ID
	string name;               // Student Name
	string sex;                // Student Sex
	int age;                   // Student Age
	char grade;                // Student Grade
	string department;         // Student Department
	float gpa;                 // Student GPA
	Student *next;             // Pointer to the next node

	// Constructor to initialize a new student node
	Student(int id, string name, string sex, int age, char grade, string department, float gpa)
		: id(id), name(name), sex(sex), age(age), grade(grade), department(department), gpa(gpa), next() {}
};

// Define the Singly Linked List class
class SinglyLinkedList {
	private:
		Student *head;  // Pointer to the head of the list

	public:
		// Constructor to initialize the head to nullptr
		SinglyLinkedList() : head(NULL) {}

		// Method to insert a student at the beginning of the list
		void insertFirst(int id, string name, string sex, int age, char grade, string department, float gpa) {
			// Create a new student node
			Student *newStudent = new Student(id, name, sex, age, grade, department, gpa);

			newStudent->next = head;  // Link new student to current head
			head = newStudent;         // Update head to new student
		}

		// Method to insert a student at the end of the list
		void insertEnd(int id, string name, string sex, int age, char grade, string department, float gpa) {
			// Create a new student node
			Student *newStudent = new Student(id, name, sex, age, grade, department, gpa);

			if (head == NULL) {  // If the list is empty
				head = newStudent;  // Set head to new student
				return;
			}

			Student *temp = head;  // Temporary pointer to traverse the list

			while (temp->next != NULL) {  // Find the last node
				temp = temp->next;  // Move to next node
			}

			temp->next = newStudent;  // Link last node to new student
		}

		// Method to insert a student at a specific position in the list
		void insertAtPosition(int id, string name, string sex, int age, char grade, string department, float gpa,
		                      int position) {
			if (position <= 0)
				return;  // Invalid position

			if (position == 1) {  // If position is 1, insert at beginning
				insertFirst(id, name, sex, age, grade, department, gpa);
				return;
			}

			Student *current = head;

			for (int i = 1; i < position - 1 && current != NULL; i++) {
				current = current->next;  // Traverse to the desired position
			}

			if (current == NULL) {  // If current is null (out of bounds)
				cout << "Position out of bounds." << endl;
				return;
			}

			// Create a new student node
			Student *newStudent = new Student(id, name, sex, age, grade, department, gpa);

			newStudent->next = current->next;  // Link new student to next node
			current->next = newStudent;          // Link current node forward to new student
		}

		// Method to delete the first student in the list
		void deleteFirst() {
			if (head == NULL)
				return;  // If list is empty

			Student *toDelete = head;  // Store the current head to delete later
			head = head->next;         // Move head to next student

			delete toDelete;           // Delete old head
		}

		// Method to delete the last student in the list
		void deleteEnd() {
			if (head == NULL)
				return;  // If list is empty
			if (head->next == NULL) {  // If there's only one student in the list
				delete head;               // Delete it and set head to nullptr
				head = NULL;
				return;
			}

			Student *secondLast = head;
			while (secondLast->next->next != NULL) {  // Find the second last node
				secondLast = secondLast->next;
			}

			delete secondLast->next;      // Delete last node
			secondLast->next = NULL;   // Set second last node's next to nullptr
		}

		// Method to delete a student at a specific position in the list
		void deleteAtPosition(int position) {
			if (head == NULL)
				return;  // If list is empty

			if (position == 1) {  // If position is 1, delete the first student
				deleteFirst();
				return;
			}

			Student *current = head;

			for (int i = 1; i < position - 1 && current != NULL; i++) {
				current = current->next;  // Traverse to the desired position
			}

			if (current == NULL || current->next == NULL)
				return;  // If position is invalid

			Student *toDelete = current->next;   // Store the current node to delete

			current->next = toDelete->next;      // Bypass and delete the current student node

			delete toDelete;                      // Delete current node
		}

		// Method to display all students in the list
		void display() const {
			if (head == NULL) {  // Check if list is empty
				cout << "List is empty." << endl;
				return;
			}

			Student *current = head;

			while (current !=NULL) {  // Traverse and print each student
				cout << "ID: " << current->id
				     << ", Name: " << current->name
				     << ", Sex: " << current->sex
				     << ", Age: " << current->age
				     << ", Grade: " << current->grade
				     << ", Department: " << current->department
				     << ", GPA: " << current->gpa << endl;

				current = current->next;  // Move to next student
			}
		}
};

// Main function for user interaction and testing the singly linked list implementation
int main() {
	SinglyLinkedList list;  // Create an instance of SinglyLinkedList

	int choice;

	do {
		cout << "\nMenu:Singly linked list\n";
		cout << "1. Insert at Beginning\n";              // Option for inserting at beginning
		cout << "2. Insert at End\n";                    // Option for inserting at end
		cout << "3. Insert at Specific Position\n";      // Option for inserting at specific position
		cout << "4. Delete at Beginning\n";              // Option for deleting first node
		cout << "5. Delete at End\n";                    // Option for deleting last node
		cout << "6. Delete at Specific Position\n";      // Option for deleting at specific position
		cout << "7. Display Students\n";                  // Option for displaying all students
		cout << "8. Exit\n";                              // Option for exiting program

		cout << "Enter your choice: ";                    // Prompt user for choice
		cin >> choice;

		switch (choice) {
			case 1: {  // Insert at Beginning case
				int id;
				string name, sex, department;
				int age;
				char grade;
				float gpa;

				cout << "Enter ID: ";                     // Prompt for ID input
				cin >> id;
				cout << "Enter Name: ";                   // Prompt for Name input
				cin >> name;
				cout << "Enter Sex: ";                    // Prompt for Sex input
				cin >> sex;
				cout << "Enter Age: ";                    // Prompt for Age input
				cin >> age;
				cout << "Enter Grade: ";                  // Prompt for Grade input
				cin >> grade;
				cout << "Enter Department: ";             // Prompt for Department input
				cin >> department;
				cout << "Enter GPA: ";                    // Prompt for GPA input
				cin >> gpa;

				list.insertFirst(id, name, sex, age, grade, department, gpa);  // Call insertFirst method with inputs

				break;
			}

			case 2: {  // Insert at End case
				int id;
				string name, sex, department;
				int age;
				char grade;
				float gpa;

				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Sex: ";
				cin >> sex;
				cout << "Enter Age: ";
				cin >> age;
				cout << "Enter Grade: ";
				cin >> grade;
				cout << "Enter Department: ";
				cin >> department;
				cout << "Enter GPA: ";
				cin >> gpa;

				list.insertEnd(id, name, sex, age, grade, department, gpa);  // Call insertEnd method with inputs

				break;
			}

			case 3: {  // Insert at Specific Position case
				int id, position;
				string name, sex, department;
				int age;
				char grade;
				float gpa;

				cout << "Enter Position: ";                 // Prompt for Position input
				cin >> position;

				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Sex: ";
				cin >> sex;
				cout << "Enter Age: ";
				cin >> age;
				cout << "Enter Grade: ";
				cin >> grade;
				cout << "Enter Department: ";
				cin >> department;
				cout << "Enter GPA: ";
				cin >> gpa;

				list.insertAtPosition(id, name, sex, age, grade, department, gpa,
				                      position);  // Call insertAtPosition method with inputs

				break;
			}

			case 4: {  // Delete at Beginning case
				list.deleteFirst();
				cout<<"delete:";                         // Call deleteFirst method

				break;
			}

			case 5: {  // Delete at End case
				list.deleteEnd(); 
				cout<<"delete:";                          // Call deleteEnd method

				break;
			}

			case 6: {  // Delete at Specific Position case
				int position;

				cout << "Enter Position: ";                 // Prompt for Position input
				cin >> position;

				list.deleteAtPosition(position);             // Call deleteAtPosition method with inputs

				break;
			}

			case 7: {  // Display Students case
				list.display();                             // Call display method

				break;
			}

			case 8:                                      // Exit case
				cout << "Exiting..." << endl;             // Print exit message

				break;

			default:
				cout << "Invalid choice. Please try again." << endl;   // Handle invalid choice
		}
	} while (choice != 8);                              // Continue until user chooses to exit

	return 0;                                          // End of program
}
