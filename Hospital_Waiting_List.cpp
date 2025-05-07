
#include <string>
#include <iostream>



struct Node {

	std::string fullName{ " " };
	bool isUrgent{ 0 };

	Node* next = nullptr;

};


Node* head1 = nullptr, * head2 = nullptr, * head3 = nullptr;
Node* _Specialization[3] = { head1 , head2 , head3};

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

void Print_Patients(Node* head) {

	short number = 1;

	while (head != nullptr) {

		std::cout << "\t\t\t   " << number << ". " << head->fullName << "      his Case is: ";
		std::cout << ((head->isUrgent == 1) ? "Urgent\n" : "Normal\n");

		head = head->next;
		number++;

	}

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

std::string Read_text(std::string message) {

	std::string text = "";

	std::cout << message;
	std::getline(std::cin >> std::ws, text);

	return text;
}


void Go_Back_To_main_Menu() {

	std::cout << "\n\n\nPress any key to go back to main options...";
	system("Pause>0");

}






void Add_New_Patient_screen() {


	std::cout << "___ Add Patient ___\n\n";

	int specialization = Read_Number_Between_2Numbers("Enter number of specialization[1:3] : ", "Invalid number, Enter again [1:3]: ", 1, 3);


	if (Number_Of_patient_In_waitingList(_Specialization[specialization - 1]) == 5) {

		std::cout << "The waiting list is full, Come back later";
		system("Pause>0");
		return;

	}


	std::string fullName = Read_text("Enter Full name: ");
	bool isUrgent = Read_Number_Between_2Numbers("Enter case (1-> Urgent, 0-> Noraml): ", 
		"Invalid input, Enter again (1-> Urgent, 0-> Noraml): ", 0, 1);


	if (isUrgent) {
		Insert_Patient_In_Front(_Specialization[specialization - 1], fullName); 
	}
	else {
		Insert_Patient_At_End(_Specialization[specialization - 1], fullName); 
	}


}

void Print_All_Patient() {


	std::cout << "\t\t___ Show all patients ___\n\n\n";

	for (int i = 0; i < 3; i++) {


		int numberOfPatient = Number_Of_patient_In_waitingList(_Specialization[i]);

		std::cout << "\t\t\t         Specialization [" << (i + 1) << "] Have [" << numberOfPatient << "] Patients\n\n";
		std::cout << "\t\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";

		if (numberOfPatient == 0) {

			std::cout << "\t\t\t   There is no patient on this specialization waiting list\n";
		}
		else {

			Print_Patients(_Specialization[i]); 

		}

		std::cout << "\n\t\t\t-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n\n\n\n";

	}


}

void Get_Next_Patient() {

	std::cout << "___ Get next patient ___\n\n";

	short numberOfSpecialization = Read_Number_Between_2Numbers("Enter number of specialization[1:3]: ", 
		"Invalid Input, Enter again[1:3]: ", 1, 3);

	short numberOfPatient = Number_Of_patient_In_waitingList(_Specialization[numberOfSpecialization]);

	if (numberOfPatient == 0) {

		std::cout << "The waiting list is empty, Take break a, Doctor.\n";

	}
	else {

		std::cout << _Specialization[numberOfSpecialization]->fullName << ", Go to the doctor.\n";
		Delete_Patient_In_Front(_Specialization[numberOfSpecialization]);


	}


}




void Perform_Choice(int choice) {


	switch (choice) {

	case 1:
		std::system("cls");
		Add_New_Patient_screen();
		Go_Back_To_main_Menu();
		break;

	case 2:
		std::system("cls");
		Print_All_Patient();
		Go_Back_To_main_Menu();
		break;

	case 3:
		// Get next patient
		break;

	}


}

void Header_Of_Menu_Option() {

	std::cout << "\t\t\t\t       ___ Hospital (Waiting list) ___ \n\n\n";

}

bool Menu_Option_Screen() {


	Header_Of_Menu_Option();

	std::cout << "\t\t\t\t_-_-_-_-_-_-_-_ Menu Options _-_-_-_-_-_-_-_\n\n";

	std::cout << "\t\t\t\t           [1] Add new patient\n";
	std::cout << "\t\t\t\t           [2] Print all patients\n";
	std::cout << "\t\t\t\t           [3] Get next patient\n";
	std::cout << "\t\t\t\t           [4] Exit\n\n";

	std::cout << "\t\t\t\t-_-_-_-_-_-_-_-_-_-_-_ -_-_-_-_-_-_-_-_-_-_-\n\n";

	int choice = Read_Number_Between_2Numbers("\t\t\t\t           Enter choice [1:4]: ", 
		"\t\t\t\t  InValid number, Enter again [1:4]: ", 1, 4);

	if (choice == 4)
		return false;

	Perform_Choice(choice);

	return true;
}

	
int main() {

	bool contnuie = true;

	while (contnuie) {

		system("cls");
		contnuie = Menu_Option_Screen();

	}

	system("Pause>0");
	return 0;

}