# **Hospital waiting list system**

## **Requirements**

The hospital's waiting list system 
The hospital contains 3 specialties, each specialty can handle a maximum of 5 patients in its waiting list.

When adding a patient, the system will ask for the specialty number, the patient's name, and the case type (urgent or normal).  
"If the patient case is urgent, they will be added to the front of the queue. If the case is normal, they will be added to the end of the queue."

If the doctor requests a patient from the queue and there are no patients, tell the doctor that there is no one and ask them to take a break.  
But if there is a patient in the queue, display the patient's name, ask them to go to the doctor, and remove them from the queue.

There is an option to display the patients in the waiting list of each specialty.  
It will print the specialty number, the number of patients in the waiting list, and below that, it will list the name and case of each patient in order.  
"Only print specialties that have patients."

If there are no patients in any specialty, print a message saying that all waiting lists in all specialties are empty and have no patients.

The system has a main menu that contains the required operations:  
1- Add new patient  
2- Print all patients  
3- Get next patient  
4- Exit  
\----------------------------------  
Enter choice:

Each option has its own screen to show its properties.


---
## **Design of structure**
The approach I will use to store patient data in order is using Nodes, and each Node will contain the patient's name, the patient's case (urgent or normal), and of course the pointer to the next Node.

The functions I will need are as follows:

- Add a patient to the front of the queue (handles if it's the first patient in the queue)
- Add a patient to the end of the queue
- Remove a patient from the front of the queue
- Display patient data
- Count the number of patients in the waiting list (how many patients are in the queue?)

As for the approach I will use to store the specialties, it will be a static manual approach.  
I will store the specialties in order in an array, where each specialty slot contains the pointer to the waiting list of that specific specialty.

---
## **Design of screens**

First page 
![image](https://github.com/user-attachments/assets/d9c2a8f6-8dc2-42fd-ade4-99cccf6035b7)



Add patient screen
![[AddPatientScreen.jpg]]



Show patient screen
![[ShowPatientScreen.jpg]]



Get patient screen
![[GetPatientScreen.jpg]]









