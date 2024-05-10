// CSE240 Fall 2021 HW 7 & 8
// Ariel Gael Gutierrez
// Write the compiler used: Visual Studio

// READ BEFORE YOU START:
// You are given a partially completed program that creates a linked list of employee information.
// The global linked list 'list' is a list of employees with each node being struct 'employeeNode'.
// 'employeeNode' consists of struct 'employee' which has: employee name, room number, and a linked list of 'supervisors'.
// The linked list of supervisors has each node containing simply the name of the supervisor.
// HW7 ignores the 'supervisors' linked list since there is no operation/manipulation to be done on 'supervisors' list in HW7.
// HW8 has operations/manipulations to be done with 'supervisors' list like add a supervisor, display last added supervisor.

// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// If you modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().
// You can use string library functions.

// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****
// ***** Before implementing any function, see how it is called in executeAction() *****


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996) // for Visual Studio

#define MAX_NAME 30

// global linked list 'list' contains the list of employees
struct employeeNode {
	struct employee* employee;
	struct employeeNode* next;
} *list = NULL;				// currently empty list

// structure "employee" contains the employee's name, room number and linked list of supervisors
struct employee {
	char name[MAX_NAME];
	unsigned int roomNumber;
	struct supervisor* supervisors;		// linked list 'supervisors' contains names of supervisors
};

// structure 'supervisor' contains supervisor's name 
struct supervisor {
	char name[MAX_NAME];
	struct supervisor* next;
};

// forward declaration of functions (already implmented)
void flushStdIn();
void executeAction(char);

// functions that need implementation:
// HW 7
void addEmployee(char* employeeNameInput, unsigned int roomNumInput); // 20 points
void displayEmployeeList(struct employeeNode* tempList);	      // 15 points
struct employee* searchEmployee(char* employeeNameInput);	      // 15 points
//HW 8
void addSupervisor(char* employeeNameInput, char* supervisorNameInput);	// 15 points
void displayEmployeeSupervisorList(struct employeeNode* tempList);	// 15 points
void removeEmployee(char* employeeNameInput);			        // 20 points

int main()
{
	char selection = 'a';		// initialized to a dummy value
	do
	{
		printf("\nCSE240 HW 7,8\n");
		printf("Please enter your selection:\n");
		printf("HW7:\n");
		printf("\t a: add a new employee to the list\n");
		printf("\t d: display employee list (no supervisors)\n");
		printf("\t b: search for an employee on the list\n");
		printf("\t q: quit\n");
		printf("HW8:\n");
		printf("\t c: add a supervisor of a employee\n");
		printf("\t l: display employees who report to a specific supervisor\n");
		printf("\t r: remove an employee\n");
		printf("\t q: quit\n");

		selection = getchar();
		flushStdIn();
		executeAction(selection);
	} while (selection != 'q');

	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	char employeeNameInput[MAX_NAME], supervisorNameInput[MAX_NAME];
	unsigned int roomNumInput;
	struct employee* searchResult = NULL;

	switch (c)
	{
	case 'a':	// add employee
				// input employee details from user
		printf("\nPlease enter employee's name: ");
		fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
		employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter room number: ");
		scanf("%d", &roomNumInput);
		flushStdIn();

		if (searchEmployee(employeeNameInput) == NULL)
		{
			addEmployee(employeeNameInput, roomNumInput);
			printf("\nEmployee successfully added to the list!\n");
		}
		else
			printf("\nThat employee is already on the list!\n");
		break;

	case 'd':		// display the list
		displayEmployeeList(list);
		break;

	case 'b':		// search for an employee on the list
		printf("\nPlease enter employee's name: ");
		fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
		employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchEmployee(employeeNameInput) == NULL)
			printf("\nEmployee name does not exist or the list is empty! \n\n");
		else
		{
			printf("\nEmployee name exists on the list! \n\n");
		}
		break;

	case 'r':		// remove employee
		printf("\nPlease enter employee's name: ");
		fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
		employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchEmployee(employeeNameInput) == NULL)
			printf("\nEmployee name does not exist or the list is empty! \n\n");
		else
		{
			removeEmployee(employeeNameInput);
			printf("\nEmployee successfully removed from the list! \n\n");
		}
		break;

	case 'c':		// add supervisor
		printf("\nPlease enter employee's name: ");
		fgets(employeeNameInput, sizeof(employeeNameInput), stdin);
		employeeNameInput[strlen(employeeNameInput) - 1] = '\0';	// discard the trailing '\n' char

		if (searchEmployee(employeeNameInput) == NULL)
			printf("\nEmployee name does not exist or the list is empty! \n\n");
		else
		{
			printf("\nPlease enter supervisor's name: ");
			fgets(supervisorNameInput, sizeof(supervisorNameInput), stdin);
			supervisorNameInput[strlen(supervisorNameInput) - 1] = '\0';	// discard the trailing '\n' char

			addSupervisor(employeeNameInput, supervisorNameInput);
			printf("\nSupervisor added! \n\n");
		}
		break;

	case 'l':		// list supervisor's employees
		displayEmployeeSupervisorList(list);
		break;

	case 'q':		// quit
		break;

	default: printf("%c is invalid input!\n", c);
	}
}

// HW7 Q1: addEmployee (20 points)
// This function is used to insert a new employee in the linked list. 
// You must insert the new employee to the head of linked list 'list'.
// You need NOT check if the employee already exists in the list because that is taken care by searchEmployee() called in executeAction(). Look at how this function is used in executeAction().
// Don't bother to check how to implement searchEmployee() while implementing this function. Simply assume that employee does not exist in the list while implementing this function.
// NOTE: The function needs to add the employee to the head of the list.
// NOTE: This function does not add supervisors to the employee info. There is another function addSupervisor() in HW8 for that.
// Hint: In this question, no supervisors means NULL supervisors.

void addEmployee(char* employeeNameInput, unsigned int roomNumInput)
{
	/* Create a new employee and employee node */
	struct employee* newEmp = (struct employee*)malloc(sizeof(struct employee));
	struct employeeNode* newNode = (struct employeeNode*)malloc(sizeof(struct employeeNode));

	/* There is enough memory to add the new employee */
	if (newEmp != 0 && newNode != 0)
	{
		/* Instantiate employee with stuff */
		strcpy(newEmp->name, employeeNameInput);
		newEmp->roomNumber = roomNumInput;
		newEmp->supervisors = NULL;

		/* Instantiate employee node with stuff */
		newNode->employee = newEmp;
		newNode->next = NULL;

		/* Add to empty list */
		if (list == NULL)
		{
			list = newNode;
		}

		/* Add to list */
		else
		{
			newNode->next = list;
			list = newNode;
		}
	}

	/* There isn't enough memory, tell the user */
	else
	{
		printf("Not enough memory to add employee!\n");
	}
}

// HW7 Q2: displayEmployeeList (15 points)
// This function displays the employee details (struct elements) of each employee.
// Parse through the linked list 'list' and print the employee details ( name and room number) one after the other. See expected output screenshots in homework question file.
// You should not display supervisor names (because they are not added in HW7).
// You MUST use recursion in the function to get full points. Notice that 'list' is passed to the function argument. Use recursion to keep calling this function till end of list.

void displayEmployeeList(struct employeeNode* tempList)
{
	/* Check if list is empty to begin with */
	if (tempList == NULL)
	{
		printf("\nNo employees!\n");
		return;
	}

	/* Scroll to the end of the list */
	if (tempList->next != NULL)
	{
		displayEmployeeList(tempList->next);
	}

	/* Print the employee */
	printf("\nEmployee name: %s\n", tempList->employee->name);
	printf("Room number: %d\n", tempList->employee->roomNumber);
}

// HW7 Q3: searchEmployee (15 points)
// This function searches the 'list' to check if the given employee exists in the list. Search by employee name.
// If it exists then return that 'employee' node of the list. Notice the return type of this function.
// If the employee does not exist in the list, then return NULL.
// NOTE: After implementing this fucntion, go to executeAction() to comment and un-comment the lines mentioned there which use searchEmployee()
//       in case 'a', case 'r', case 'l' (total 3 places)
struct employee* searchEmployee(char* employeeNameInput)
{

	struct employeeNode* tempList = list;			// work on a copy of 'list'

	/* Iterate through the list */
	while (tempList != NULL)
	{
		/* Check if employee exists */
		if (strcmp(tempList->employee->name, employeeNameInput) == 0)
		{
			return tempList->employee;
		}

		/* Scroll to the next node */
		tempList = tempList->next;
	}

	return NULL; // Employee isn't on the list
}



// HW8 Q1: addSupervisor (15 points)
// This function adds supervisor's name to a employee node.
// Parse the list to locate the employee and add the supervisor to that employee's 'supervisors' linked list. No need to check if the employee name exists on the list. That is done in executeAction().
// If the 'supervisors' list is empty, then add the supervisor. If the employee has existing supervisors, then you may add the new supervisor to the head or the tail of the 'supervisors' list.
// You can assume that the same supervisor name does not exist. So no need to check for existing supervisor names, like we do when we add new employee.
// NOTE: Make note of whether you add the supervisor to the head or tail of 'supervisors' list. 
//       (Sample solution has supervisor added to the tail of 'supervisors' list. You are free to add new supervisor to head or tail of 'supervisors' list.)

void addSupervisor(char* employeeNameInput, char* supervisorNameInput)
{
	struct supervisor* newSup = (struct supervisor*)malloc(sizeof(struct supervisor)); // Create a new supervisor node

	/* Add supervisor if there is enough memory for it */
	if (newSup != 0)
	{
		/* Instantiate the new supervisor with values */
		strcpy(newSup->name, supervisorNameInput);
		newSup->next = NULL;

		struct employee* tempEmp = searchEmployee(employeeNameInput); // Get the employee using the search function

		/* Add supervisor to empty supervisors list */
		if (tempEmp->supervisors == NULL)
		{
			tempEmp->supervisors = newSup;
		}

		/* Add supervisor to head of supervisors list */
		else
		{
			newSup->next = tempEmp->supervisors;
			tempEmp->supervisors = newSup;
		}
	}

	/* Not enough memory to add a supervisor, let the user know */
	else
	{
		printf("Not enough memory to add supervisor!\n");
	}
}

// HW8 Q2: displayEmployeeSupervisorList (15 points)
// This function prompts the user to enter a supervisor name. This function then searches for employees with this supervisor.
// Parse through the linked list passed as parameter and print the matching employee details ( name and room number) one after the other. See expected output screenshots in homework question file.
// HINT: Use inputs gathered in executeAction() as a model for getting the supervisor name input.
// NOTE: You may re-use some HW7 Q2 displayEmployeeList(list) code here.
void displayEmployeeSupervisorList(struct employeeNode* tempList)
{
	char supervisorNameInput[MAX_NAME]; // Supervisor name input
	int matches = 0;					// Number of people with that supervisor

	/* Get supervisor name from user */
	printf("\nPlease enter supervisor's name: ");
	fgets(supervisorNameInput, sizeof(supervisorNameInput), stdin);
	supervisorNameInput[strlen(supervisorNameInput) - 1] = '\0';	// discard the trailing '\n' char

	/* Scroll through the list of employees */
	while (tempList != NULL)
	{
		struct supervisor* tempSup = tempList->employee->supervisors; // Pointer to employee's supervisors

		/* Scroll through the list of supervisors */
		while (tempSup != NULL)
		{
			/* Check if the supervisor name matches and print employee if it does */
			if (strcmp(supervisorNameInput, tempSup->name) == 0)
			{
				printf("\nEmployee name: %s\n", tempList->employee->name);
				printf("Room number: %d\n", tempList->employee->roomNumber);
				matches++;
			}

			tempSup = tempSup->next; // Iterate to next supervisor
		}

		tempList = tempList->next; // Iterate through employee list
	}

	/* No matches were found, let user know */
	if (matches == 0)
	{
		printf("\nNo employee has that supervisor!\n");
	}
}

// HW8 Q3: removeEmployee (20 points)
// This function removes an employee from the list.
// Parse the list to locate the employee and delete that 'employee' node.
// You need not check if the employee exists because that is done in executeAction()
//removeEmployee() is supposed to remove employee details like name and room number.
// The function will remove supervisors of the employee too.
// When the employee is located in the 'list', after removing the employee name and room number, parse the 'supervisors' list of that employee
// and remove the supervisors.

void removeEmployee(char* employeeNameInput)
{

	struct employeeNode* tempList = list;	// work on a copy of 'list'

	struct employeeNode* befTempList = list; // Pointer pointing to node before tempList node

	/* Iterates through the employeeNode list */
	while (tempList != NULL)
	{
		/* Look for employee that matches the name */
		if (strcmp(tempList->employee->name, employeeNameInput) == 0)
		{
			// Free Supervisor List
			//-----------------------------------------------------------
			struct supervisor* tempSup = tempList->employee->supervisors; // Temporary pointer to iterate through supervisors list

			/* Iterate through supervisors and removed them from the list */
			while (tempList->employee->supervisors != NULL)
			{
				tempList->employee->supervisors = tempList->employee->supervisors->next;
				free(tempSup);
				tempSup = tempList->employee->supervisors;
			}
			//-----------------------------------------------------------

			// Free employee
			//-------------------------------------------------------
			free(tempList->employee); // Free memory of employee structure in employeeNode
			//-------------------------------------------------------

			// Free employeeNode
			//-------------------------------
			/* If employee is at the beginning, move the head */
			if (tempList == list)
			{
				list = tempList->next;
			}

			/* Move the next pointer of the previous node to the next of the node to be removed */
			else
			{
				befTempList->next = tempList->next;
			}

			/* Free the node and return since the value was deleted */
			free(tempList);
			return;
			//-------------------------------
		}

		/* Correctly iterate through the list */
		befTempList = tempList;
		tempList = tempList->next;
	}

}


