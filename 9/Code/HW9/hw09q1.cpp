// CSE240 Fall 2021 HW9
// Ariel Gael Gutierrez
// Write the compiler used: Visual Studio

// READ BEFORE YOU START:
// You are given a partially completed program which consist of a class 'Patient' defined in patient.h
// The definitions of class member functions are to be filled in patient.cpp
// hw09q1.c (this file) creates an array of objects 'p[]' and uses a menu driven program to add a patient, display patient info, 
// sort the patient list and to find the oldest patient(by birth year).
// You should start completing the program from from Q1. Question numbers are given around line 33.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// If you modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().

// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****

#include "patient.h"
#include <iostream>
#include <string>

#define MAX_PATIENTS 5

using namespace std;

// forward declaration of functions (already implmented)
void executeAction(char);

// functions that need implementation:
// in patient.cpp :
// Q1 Patient constructor		// 2 points
// Q2 Patient member functions // 18 points

// in this file (hw09q1.cpp) : Q3 to Q6
int addPatient(string name_input, int age_input, int DOByear_input, int ID_input); // 10 points
void displayPatients();				// 5 points
void sort();						// 10 points
void oldestPatient();		// 5 points


Patient s[MAX_PATIENTS];		// array of objects
int currentCount = 0;				// number of patients in the list


int main()
{
	char choice = 'i';		// initialized to a dummy value
	do
	{
		cout << "\nCSE240 HW9\n";
		cout << "Please select an action:\n";
		cout << "\t a: add a new patient\n";
		cout << "\t d: display patient list\n";
		cout << "\t s: sort the patients in descending order based on age (within a range)\n";
		cout << "\t n: display the oldest patient whose name starts with a specific letter\n";
		cout << "\t q: quit\n";
		cin >> choice;
		cin.ignore();			// ignores the trailing \n
		executeAction(choice);
	} while (choice != 'q');

	return 0;
}


// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input;
	int age_input, DOByear_input, ID_input, result = 0;

	switch (c)
	{
	case 'a':	// add patient
				// input patient details from user
		cout << "Please enter patient name: ";
		getline(cin, name_input);
		cout << "Please enter age: ";
		cin >> age_input;
		cin.ignore();
		cout << "Please enter year of birth: ";
		cin >> DOByear_input;
		cin.ignore();
		cout << "Please enter ID: ";
		cin >> ID_input;
		cin.ignore();

		// add the patient to the list
		result = addPatient(name_input, age_input, DOByear_input, ID_input);
		if (result == 0)
			cout << "\nThat patient is already in the list or list is full! \n\n";
		else
			cout << "\nPatient successfully added to the list! \n\n";
		break;

	case 'd':		// display the list
		displayPatients();
		break;

	case 's':		// sort the list
		sort();
		break;

	case 'n':		// find and display oldestt patient
		oldestPatient();
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// Q3 addPatient (10 points)
// This function adds a new patient with the details given in function arguments.
// Add the patient in 'p' (array of objects) only if there is remaining capacity in the array and if the patient does not already exist in the list
// This function returns 1 if the patient is added successfully, else it returns 0 for the cases mentioned above.
// Assume user enters age in 0.0 - any positive integer range.
int addPatient(string name_input, int age_input, int DOByear_input, int ID_input)
{
	/* Check if array is full */
	if (currentCount < MAX_PATIENTS)
	{
		/* Check if patient already exists by their ID */
		for (int i = 0; i < currentCount; i++)
		{
			if (ID_input == s[i].getID())
			{
				return 0;
			}
		}

		/* Add the new patient to the list */
		s[currentCount].setName(name_input);
		s[currentCount].setAge(age_input);
		s[currentCount].setDOByear(DOByear_input);
		s[currentCount].setID(ID_input);

		/* Add to the patient count and return success */
		currentCount++;
		return 1;
	}

	/* Array is full, don't add more patients */
	else
	{
		return 0;
	}
}

// Q4 displayPatients (5 points)
// This function displays the list of patients.
// Parse the object array 'p' and display the details of all patientss in the array. See expected output given in question file.
// You can call the class function 'displayPatients()' here. Note that these are two different functions.
// Patient::displayPatient() displays details of one Patient object, while displayPatients() should display all patients
void displayPatients()
{
	/* Parse through the array of patients and display them one by one */
	for (int i = 0; i < currentCount; i++)
	{
		s[i].displayPatient();
		cout << endl;
	}
}

// Q5 sort (10 points)
// This function sorts the patients in descending order of age, and then display the patients within a given range.
// You may use the 'temp' object for sorting logic, if needed.

void sort()
{
	Patient temp;
	int lower_bound;
	int higher_bound;

	/* Ask user for lower and higher bound of ages */
	cout << "Please enter the lower bound of age: ";
	cin >> lower_bound;
	cin.ignore();
	cout << "Please enter the higher bound of age: ";
	cin >> higher_bound;
	cin.ignore();

	/* Insertion sort from oldest to youngest */
	for (int i = 0; i < currentCount; i++)
	{
		for (int j = i; j < currentCount; j++)
		{
			/* If the age of a patient further down in the array is greater, swap them */
			if (s[j].getAge() > s[i].getAge())
			{
				temp = s[j];
				s[j] = s[i];
				s[i] = temp;
			}
		}
	}

	/* Parse through the array to find patients fitting the age and display them */
	for (int k = 0; k < currentCount; k++)
	{
		if (s[k].getAge() >= lower_bound && s[k].getAge() <= higher_bound)
		{
			s[k].displayPatient();
			cout << endl;
		}
	}
}

// Q6 oldestPatient (5 points)
// This functions displays patients who is oldest and whose name starts with a specific letter
// Parse the array to check if the patient is the oldest patient based of the character input
// If the patient is the oldest patient year then copy that patient's details (object's data members) 
// to 'newPatient' object created using 'new' and display those patient details using 'newPatient' object.
// Finally delete the 'newPatient' object.
// NOTE: You necessarily have to use the 'newPatient' object to store the patient details in it and delete it after displaying.
//       You should not display patient details using 'p[]' object.

void oldestPatient()
{
	char startingCharacter;				// Ask the user for a character
	Patient* newPatient = new Patient;

	/* Ask user for starting character */
	cout << "Enter the first letter of patients' first name: ";
	cin >> startingCharacter;
	cin.ignore();

	int maxAge = 0;  // Maximum age of patient that has the starting character
	int maxPos = -1; // Index in array where the maximum aged patient is

	/* Parse through the list and get the max age and position of the patient with the max age */
	for (int i = 0; i < currentCount; i++)
	{
		if ((s[i].getName()[0] == startingCharacter) && (s[i].getAge() > maxAge))
		{
			maxAge = s[i].getAge();
			maxPos = i;
		}
	}

	/* Add data to new patient and display it */
	if (maxPos != -1)
	{
		newPatient->setName(s[maxPos].getName());
		newPatient->setAge(s[maxPos].getAge());
		newPatient->setDOByear(s[maxPos].getDOByear());
		newPatient->setID(s[maxPos].getID());
		newPatient->displayPatient();
	}

	delete(newPatient); // Free memory taken up by the new patient
}
