
#include <string>
#include <iostream>

struct Node {

	std::string fullName{ " " };
	bool isUrgent{ 0 };

	Node* next = nullptr;

};


void Insert_Patient_In_Front(Node*& head, std::string fullName) {


	Node* newNode = new Node;

	newNode->fullName = fullName;
	newNode->isUrgent = 1;

	if (head == nullptr) {

		head = newNode;
		return;

	}

	newNode->next = head;
	head = newNode;
	
}

void Insert_Patient_At_End(Node*& head, std::string fullName) {

	Node* newNode = new Node;

	newNode->fullName = fullName;
	newNode->isUrgent = 0;

	if (head == nullptr) {

		head = newNode;
		return;

	}


	Node* temp = head;
	while (temp->next != nullptr) {

		temp = temp->next;

	}

	temp->next = newNode;
	
}

void Delete_Patient_In_Front(Node*& head) {

	if (head == nullptr) return;

	Node* temp = head;
	head = head->next;

	delete temp;

	
}

int Number_Of_patient_In_waitingList(Node* head) {

	int counter = 0;

	while (head != nullptr) {

		counter++;
		head = head->next;

	}

	return counter;

}


int Read_Number_Between_2Numbers(std::string message, std::string errorMessage, int from, int to) {

	int number = 0;

	std::cout << message;
	std::cin >> number;

	while (number < from || number > to) {


		std::cout << errorMessage;
		std::cin >> number;

	}

	return number;

}

void Perform_Choice(int choice) {


	switch (choice) {

	case 1:
		// Add new patient
		break;

	case 2:
		// print all patient
		break;

	case 3:
		// Get next patient
		break;

	case 4:
		//Exit

	}


}

void Header_Of_Menu_Option() {

	std::cout << "\t\t\t\t       ___ Hospital (Waiting list) ___ \n\n\n";

}

void Menu_Option_Screen() {


	Header_Of_Menu_Option();

	std::cout << "\t\t\t\t_-_-_-_-_-_-_-_ Menu Options _-_-_-_-_-_-_-_\n\n";

	std::cout << "\t\t\t\t           [1] Add new patient\n";
	std::cout << "\t\t\t\t           [2] Print all patients\n";
	std::cout << "\t\t\t\t           [3] Get next patient\n";
	std::cout << "\t\t\t\t           [4] Exit\n\n";

	std::cout << "\t\t\t\t-_-_-_-_-_-_-_-_-_-_-_ -_-_-_-_-_-_-_-_-_-_-\n\n";

	int choice = Read_Number_Between_2Numbers("\t\t\t\t           Enter choice [1:4] ", 
		"\t\t\t\t  InValid number, Enter again [1:4] ", 1, 4);

	Perform_Choice(choice);

}


int main() {

	Menu_Option_Screen();

	system("Pause>0");
	return 0;

}