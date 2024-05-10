
// CSE240 Fall 2021 HW5
// Ariel Gael Gutierrez
// Write the compiler used: Visual studio

// READ BEFORE YOU START:
// You are given a partially completed program that creates a list of books, like book's record.
// Each record has this information: book title, author, type of the book, book id and aisle in which the book is to be kept.
// The struct 'libraryRecord' holds information of one book. bookType is enum type.
// An array of structs called 'list' is made to hold the list of books.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// You should not modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().
// You can use string library functions.

// WRITE COMMENTS FOR IMPORTANT STEPS IN YOUR CODE.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) // for Visual Studio Only

#define MAX_BOOKS 15
#define MAX_NAME_LENGTH 25

/* enum type */
typedef enum { Nonfiction = 0, Fiction } bookType; 

// struct for book details
struct libraryRecord {					
	char bookTitle[MAX_NAME_LENGTH];
	char author[MAX_NAME_LENGTH];
	bookType booktype;
	unsigned int bookId;
	unsigned int aisle;
};

struct libraryRecord list[MAX_BOOKS]; // declare list of books
int count = 0;						  // the number of books currently stored in the list (initialized to 0)

// functions already implemented:
void flushStdIn();
void executeAction(char);
void save(char* fileName);

// functions that need implementation:
int add(char* bookTitle_input, char* author_input, char* booktype_input, unsigned int bookId_input, unsigned int aisle_input); // 20 points
void sort();				  // 10 points
int delete(unsigned int bookId_input);  // 10 points
void load(char* fileName);		  // 10 points
void display();				  // given


int main()
{
	char* fileName = "Book_List.txt";
	load(fileName);	// load list of books from file (if it exists). Initially there will be no file.
	char choice = 'i';		// initialized to a dummy value
	do
	{
		printf("\nEnter your selection:\n");
		printf("\t a: Add a new book\n");
		printf("\t d: Display book list\n");
		printf("\t r: Remove a book from list\n");
		printf("\t s: Sort book list by ID\n");
		printf("\t q: Quit\n");
		choice = getchar();
		flushStdIn();
		executeAction(choice);
	} while (choice != 'q');

	// save list of books to file (overwrites file, if it exists)
	save(fileName);
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
void executeAction(char c)
{
	char bookTitle_input[MAX_NAME_LENGTH], author_input[MAX_NAME_LENGTH];
	unsigned int bookId_input, aisle_input, add_result = 0;
	char booktype_input[20];
	switch (c)
	{
		case 'a':
			// input book record from user
			printf("\nEnter book title: ");
			fgets(bookTitle_input, sizeof(bookTitle_input), stdin);
			bookTitle_input[strlen(bookTitle_input) - 1] = '\0';	// discard the trailing '\n' char
			printf("Enter author name: ");
			fgets(author_input, sizeof(author_input), stdin);
			author_input[strlen(author_input) - 1] = '\0';	// discard the trailing '\n' char
			printf("Enter book type (Fiction/ Nonfiction): ");
			fgets(booktype_input, sizeof(booktype_input), stdin);
			booktype_input[strlen(booktype_input) - 1] = '\0';	// discard the trailing '\n' char
			printf("Please enter book ID number: ");
			scanf("%d", &bookId_input);
			printf("Please enter aisle number: ");
			scanf("%d", &aisle_input);
			flushStdIn();

			// add the book to the list
			add_result = add(bookTitle_input, author_input, booktype_input, bookId_input, aisle_input);
			if (add_result == 0)
				printf("\nBook is already on the list! \n\n");
			else if (add_result == 1)
				printf("\nBook successfully added to the list! \n\n");
			else
				printf("\nUnable to add. Book list is full! \n\n");

			break;
		case 'r':
			printf("Please enter ID number of book to be deleted: ");
			scanf("%d", &bookId_input);
			flushStdIn();
			int delete_result = delete(bookId_input);
			if (delete_result == 0)
				printf("\nBook not found in the list! \n\n");
			else
				printf("\nBook deleted successfully! \n\n");
			break;
		case 'd': 
			display();	
			break;
		case 's': 
			sort();		
			break;
		case 'q': 
			break;
		default: 
			printf("%c is invalid input!\n", c);
	}
}

// Q1 : add (20 points)
// This function is used to add a book into the list. You can simply add the new book to the end of list (array of structs).
// Do not allow the book to be added to the list if it already exists in the list. You can do that by checking book names AND IDs already in the list.
// If the book already exists then return 0 without adding it to the list. If the book does not exist in the list then add the book at the end of the list and return 1.
// If book list is full, then do not add new book to the list and return 2.
// NOTE: Notice how return type of add() is checked in case 'a' of executeAction()
// NOTE: You must convert the string 'booktype_input' to an enum type and store it in the list because the booktype has enum type (not string type).
// The list should be case sensitive. For instance, 'Roger' and 'roger' should be considered two different names.
// Hint: 'count' holds the number of books currently in the list
int add(char* bookTitle_input, char* author_input, char* booktype_input, unsigned int bookId_input, unsigned int aisle_input)
{
	/* Check if the book list is full */
	if (count < MAX_BOOKS)
	{
		/* Checks if the title or id of the book matches */
		for (int i = 0; i < count; i++)
		{
			if ((strcmp(bookTitle_input, list[i].bookTitle) == 0) || (bookId_input == list[i].bookId))
			{
				return 0;
			}
		}
		
		/* Copy the input strings to the structure */
		strcpy(list[count].bookTitle, bookTitle_input);
		strcpy(list[count].author, author_input);

		/* Turn input string into enum */
		bookType type = 0;
		if (strcmp(strlwr(booktype_input), "fiction") == 0)
		{
			type = Fiction;
		}
		else if (strcmp(strlwr(booktype_input), "nonfiction") == 0)
		{
			type = Nonfiction;
		}
		list[count].booktype = type; // Set the book type to fiction or nonfiction

		/* Copy input numbers into corresponding structure stuff */
		list[count].bookId = bookId_input;
		list[count].aisle = aisle_input;

		count++; // Add to the book count
		return 1;
	}

	/* Book list is full */
	else
	{
		return 2;
	}
}



// This function displays the book list with the details (struct elements) of each book. 
void display()
{
	char* booktypeString = "Nonfiction";						// dummy init

	for (int i = 0; i < count; i++)								// iterate through the list
	{
		printf("\nBook Title: %s", list[i].bookTitle);			// display Book title
		printf("\nAuthor Name: %s", list[i].author);			// display author

		if (list[i].booktype == Nonfiction)						// find what to display for book type
			booktypeString = "Nonfiction";
		else
			booktypeString = "Fiction";
	
		printf("\nBook Type: %s", booktypeString);			// display book type
		printf("\nBook ID: %d", list[i].bookId);			// display book id
		printf("\nAisle number: %d", list[i].aisle);		// display aisle number
		printf("\n");
	}

}

// Q2 : sort (10 points)
// This function is used to sort the list(array of structs) numerically by book ID.
// Parse the list and compare the book IDs to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new array of structs having sorted books.
// Hint: Use a temp struct (already declared) if you need to swap two structs in your logic and try implementing the bubble sort
void sort()
{
	struct libraryRecord libraryTemp;	// needed for swapping structs. Not absolutely necessary to use.

	/* Bubble Sort */
	for (int i = 0; i < count - 1; i++) // Element to be checked
	{
		for (int j = 0; j < count - i - 1; j++) // last i elements are already sorted
		{
			if (list[j].bookId > list[j + 1].bookId) // If this element is bigger than the next, swap them
			{
				libraryTemp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = libraryTemp;
			}
		}
	}

	// display message for user to check the result of sorting.
	printf("\nBook list sorted! Use display option 'd' to view sorted list.\n");
}

// save() is called at the end of main()
// This function saves the array of structures to file. It is already implemented.
// You should read and understand how this code works. It will help you with 'load()' function.
// save() is called at end of main() to save the book list to a file.
// The file is saved at the same place as your C file. For VS, the default directory looks like this:
// C:\Users\<username>\Documents\Visual Studio 2017\Projects\Project1\Project1
// You can simply delete the file to 'reset the list' or to avoid loading from it.
void save(char* fileName)
{
	FILE* file;
	int i, booktypeValue = 0;
	file = fopen(fileName, "wb");		// open file for writing

	fwrite(&count, sizeof(count), 1, file);		// First, store the number of books in the list

	// Parse the list and write book record to file

	for (i = 0; i < count; i++)
	{
		fwrite(list[i].bookTitle, sizeof(list[i].bookTitle), 1, file);
		fwrite(list[i].author, sizeof(list[i].author), 1, file);
		// convert enum to a number for storing
		if (list[i].booktype == Nonfiction)
			booktypeValue = 0;		// 0 for Nonfiction
		else
			booktypeValue = 1;		// 1 for Fiction

		fwrite(&booktypeValue, sizeof(booktypeValue), 1, file);
		fwrite(&list[i].bookId, sizeof(list[i].bookId), 1, file);
		fwrite(&list[i].aisle, sizeof(list[i].aisle), 1, file);
	}

	fclose(file);			// close the file after writing
}

// Q3 : delete (10 points)
// This function is used to delete a book by ID.
// Parse the list and compare the book IDs to check which one should be deleted.
// Restore the array structure after removal of the book record.
// Return 0 if the specified ID was not found. Return 1 upon successful removal of a record.
int delete(unsigned int bookId_input)
{
	struct libraryRecord libraryTemp;	// needed for swapping structs. Not absolutely necessary to use.
	
	/* Search for the element that is alike to this one */
	int likeIndex = -1; // Index of element alike
	for (int i = 0; i < count; i++)
	{
		if (list[i].bookId == bookId_input)
		{
			likeIndex = i;
			break;
		}
	}
	/* If there is no element alike, return 0 */
	if (likeIndex == -1)
	{
		return 0;
	}

	/* Move elements from the alike index backwards */
	for (int i = likeIndex; i < count - 1; i++)
	{
		list[i] = list[i + 1];
	}
	count--; // Allows the garbage value at the end to be overwritten/not displayed
	return 1;
}

// Q4:  load (10 points)
// This function is called in the beginning of main().
// This function reads the book list from the saved file and builds the array of structures 'list'. 
// In the first run of the program, there will be no saved file because save() is called at the end of program.
// So at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
// (See expected output of add() in homework question file. It displays "Book_List.txt not found" because the file did not exist initially.)
// If the file exists, then parse the book list to read the book details from the file.
// Use the save function given above as an example of how to write this function. Notice the order in which the struct elements are saved in save()
// You need to use the same order to read the list back.
// NOTE: The saved file is not exactly readable because all elements of the struct are not string or char type.
//       So you need to implement load() similar to how save() is implemented. Only then the 'list' will be loaded correctly.
//		You can simply delete the file to 'reset the list' or to avoid loading from it.
void load(char* fileName)
{
	// Enter code here
	FILE* file;
	int i, booktypeValue = 0;
	file = fopen(fileName, "rb");		// open file for reading

	// Parse the list and write book record to file
	if (file != NULL)
	{
		fread(&count, sizeof(count), 1, file);		// First, store the number of books in the list

		/* Read everything else */
		for (i = 0; i < count; i++)
		{
			fread(list[i].bookTitle, sizeof(list[i].bookTitle), 1, file);
			fread(list[i].author, sizeof(list[i].author), 1, file);
			fread(&booktypeValue, sizeof(booktypeValue), 1, file);
			fread(&list[i].bookId, sizeof(list[i].bookId), 1, file);
			fread(&list[i].aisle, sizeof(list[i].aisle), 1, file);
		}

		fclose(file);			// close the file after reading
	}

	return;
}