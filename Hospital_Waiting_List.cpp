
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
	std::cout << "\t\t\t\t           Enter choice [1:4]   ";


}


int main() {

	Menu_Option_Screen();

	system("Pause>0");
	return 0;

}