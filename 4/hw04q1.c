// CSE240 Fall 2021 HW4

// Ariel Gael Gutierrez
// State the IDE that you use: Visual Studio

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Read before you start:
// You are given a partially complete program. Complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.
// You can use only the strlen() of strings.h library to check string length. Do not use any other string functions 
// because you are supposed to use pointers for this homework. 
// **** DO NOT use arrays to store or to index the characters in the string ****

// Global Macro Values. They are used to define the size of 2D array of characters
#define NUM_STRINGS 4
#define STRING_LENGTH 50

// Forward Declarations
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]);
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);
void toUppercase(char[STRING_LENGTH]);
void toLowercase(char[STRING_LENGTH]);
void changeAllToUpperOrLower(char[NUM_STRINGS][STRING_LENGTH], char);
void encryptStrings(char[NUM_STRINGS][STRING_LENGTH], int);
void decryptStrings(char[NUM_STRINGS][STRING_LENGTH], int);
int isPalindrome(char s[STRING_LENGTH]);


// Problem 1: initializeStrings (5 points)
// Use pointer 'p' to traverse the 2D array of characters variable 'strings' (input from user in main() ) and set all characters in each
// array to a null terminator so that there is a 4 row and 50 column 2D array full of null terminators.
// The null terminator '\0' is used to denote the end of a string.
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* p = &strings[0][0];

	/* Since the array elements are in sequence in memory, you can use a pointer to advance through all of the elements linearly */
	for (int i = 0; i < NUM_STRINGS * STRING_LENGTH; i++)
	{
		*p = '\0';
		p++;
	}

}

// Problem 2: printStrings (5 points)
// Use pointer 'p' to traverse the 2D character array 'strings' and print each string.
// See the example outputs provided in the word document. Each string should be printed on a new line.
void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* p = &strings[0][0];
	
	/* The for loop scrolls through all of the words, and the while loop scrolls through all of the letters */
	for (int i = 0; i < NUM_STRINGS; i++)
	{
		p = &strings[i]; // Advances the pointer to the location of the next word

		while (*p != 0)
		{
			printf("%c", *p); // Prints out a letter in the word
			p++;
		}

		printf("\n"); // Advances to the next line when the end of a world is reached
	}
}

// Problem 3: toUppercase() and toLowercase() (15 points)
// Problem 3-1: toUppercase 
// Convert the string in the array 's' to an uppercase string.
// Traverse the input using pointer 'p' and covert the character to an uppercase letter if it is lowercase.
// You need to write down the code to check whether or not the character is lowercase.
// HINT: Use a pointer to change the ASCII value of a character.
//       The ASCII value of 'a'= 97 and the ASCII value of 'A' = 65 so the difference between them is 32.
void toUppercase(char s[STRING_LENGTH]) {
	char* p = &s[0];

	/* While loop scrolls through all of the elements in the array */
	while (*p != 0)
	{
		if (*p > 96 && *p < 123) // Checks if the element is a lowercase letter
		{
			*p = *p - 32; // Shifts the element so that it can be interpreted as an uppercase letter
		}
		p++;
	}
	
}

// Problem 3-2: toLowercase 
// HINT : This should be very similar to toUppercase().
// Convert the string in the array 's' to an lowercase string.
// Traverse the input using pointer 'p' and convert the character to a lowercase letter if it is uppercase.
// You need to write down the code to check whether or not the character is uppercase.
// HINT: Use a pointer to change the ASCII value of a character.
//       The ASCII value of 'a'= 97 and the ASCII value of 'A' = 65 so the difference between them is 32.
void toLowercase(char s[STRING_LENGTH]) {
	char* p = &s[0];
	
	/* While loop scrolls through all of the elements in the array */
	while (*p != 0)
	{
		if (*p > 64 && *p < 91) // Checks if the element is an uppercase letter
		{
			*p = *p + 32; // Shifts the element so that it can be interpreted as a lowercase letter
		}
		p++;
	}
}



// Problem 4: changeAllToUpperOrLower (5 points)
// Change all words in the array 'strings' to uppercase or lowercase based on the value of char variable 'set'.
// If the value of char 'set' is 'u' or 'U', change all words to uppercase strings.
// If the value of char 'set' is 'l' or 'L', change all words to lowercase strings.
// No change, otherwise.
// You may use toUppercase() and toLowercase() here.
void changeAllToUpperOrLower(char strings[NUM_STRINGS][STRING_LENGTH], char set) {
	char* ptr = &strings[0][0];
	
	/* For loop scrolls through all of the strings */
	for (int i = 0; i < NUM_STRINGS; i++)
	{
		ptr = &strings[i]; // Moves the location of the pointer to the next string

		/* Sets the current string to uppercase letters */
		if (set == 'u' || set == 'U')
		{
			toUppercase(ptr);
		}

		/* Sets the current string to lowercase letters */
		else if (set == 'l' || set == 'L')
		{
			toLowercase(ptr);
		}
	}
}


// Problem 5: encryptStrings (5 points)
// Use pointer 'p' to traverse the 2D character array 'strings' and encrypt each string in 2 steps as follows- 
// 1) Change all strings to lowercase strings. Hint: Use 'changeAllToUpperOrLower()' for this step.
// 2) Shift the characters forward by the integer value of 'key'.
// If the string is "HELLO" and key = 2, Changing the string to lowercase string will get you "hello" and adding key to it will result in "jgnnq".
// Once the value of 'key' gets larger, you will extend past alphabetical characters and reach non-alphabetical characters. Thats ok.
// NOTE: DO NOT encrypt the null terminator character. Use the null terminator to find the end string.
//		 If you could not implement changeAllToUpperOrLower(), skip using it in this function. You will receive partial credit.
void encryptStrings(char strings[NUM_STRINGS][STRING_LENGTH], int key)
{
	char* p = &strings[0][0];
	
	changeAllToUpperOrLower(strings, 'l'); // Sets the current string to all lowercase letters

	/* For loop scrolls through all of the strings in the array */
	for (int i = 0; i < NUM_STRINGS; i++)
	{
		p = strings[i]; // Sets the pointer to the next string

		/* While loop is used to scroll through all of the characters in a string */
		while (*p != 0)
		{
			*p += key; // Shifts the letter by the number in the key
			p++;
		}
	}
}

// Problem 6: decryptStrings (5 points)
// HINT: This should be very similiar to the encryption function defined above in encryptStrings().
// Use pointer 'p' to traverse the 2D character array 'strings' and decrypt each string in 2 steps as follows- 
// 1) Shift the characters backward by the integer value of 'key'.
// 2) Change all strings to uppercase. Hint: Use 'changeAllToUpperOrLower()' for this step.
// NOTE: DO NOT decrypt the null characters.
//		 If you could not implement changeAllToUpperOrLower(), skip using it in this function. You will receive partial credit.
void decryptStrings(char strings[NUM_STRINGS][STRING_LENGTH], int key)
{
	char* p = &strings[0][0];
	
	/* For loop is used to scroll through all of the strings */
	for (int i = 0; i < NUM_STRINGS; i++)
	{
		p = strings[i]; // Moves pointer to the next string

		/* While loop is used to scroll through all of the characters in the string */
		while (*p != 0)
		{
			*p -= key; // Shifts the element backwards by the key number to regain the decrypted element
			p++;
		}
	}

	changeAllToUpperOrLower(strings, 'u'); // Changes all of the letters in the array to uppercase forms
}


// Problem 7: isPalindrome (10 points)
// Return 1 if string s is palindrome.
// Parse through the string to check if 1st char==last char, 2nd char == (last-1) char, and so on..
// Return 1 if string is palindrome. Return 0 if string is not palindrome.
// A palindrome is a sequence of characters which when reversed, is the same sequence of characters.
// Palindrome string examples: rotor, noon, madam
// Note: you may use reverseOneString() here but it is not necessary to use it. 
int isPalindrome(char s[STRING_LENGTH])
{
	char* p = s;
	
	int slen = strlen(s);   // Finds the length of the string which will become important to find the last spot in the array
	char* q = &s[slen - 1]; // Creates a new pointer that starts at the last memory address of the word

	/* While loop is used to scroll through all of the characters in the array */
	while (*p != 0)
	{
		if (*p != *q) // Checks if the character at address p is the same as its corresponding reverse character at address q
		{
			return 0;
		}

		/* Scrolls pointer p forward and q backwards to find their corresponding normal and reverse place */
		p++;
		q--;
	}

	return 1;
}


// You should study and understand how main() works.
// *** DO NOT modify it in any way ***
int main()
{
	char strings[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 50
	int i, key;
	char input[STRING_LENGTH];
	char result[STRING_LENGTH * 2];

	printf("CSE240 HW4: Pointers\n\n");
	initializeStrings(strings);

	for (i = 0; i < NUM_STRINGS; i++)
	{
		printf("Enter a string: ");				// prompt for string
		fgets(input, sizeof(input), stdin);		// store input string
		input[strlen(input) - 1] = '\0';		// convert trailing '\n' char to '\0' (null terminator)
		strcpy(strings[i], input);				// copy input to 2D strings array
	}

	printf("\nEnter a key value for encryption: "); // prompt for integer key
	scanf("%d", &key);

	printf("\nMake strings uppercase before encryption:\n");
	changeAllToUpperOrLower(strings, 'U');
	printStrings(strings);

	encryptStrings(strings, key);
	printf("\nEncrypted Strings:\n");
	printStrings(strings);
	decryptStrings(strings, key);
	printf("\nDecrypted Strings:\n");
	printStrings(strings);

	getchar();															// flush out newline '\n' char

	printf("\nChecking for palindrome. Enter a string: ");				// prompt for string
	fgets(input, sizeof(input), stdin);									// store input string
	input[strlen(input) - 1] = '\0';									// convert trailing '\n' char to '\0' (null terminator)

	if (isPalindrome(input))
		printf("\nThe string is a palindrome");
	else
		printf("\nThe string is not a palindrome");

	getchar();									// keep VS console open
	return 0;
}