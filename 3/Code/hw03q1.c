// CSE240 Fall 2021 HW3

// Ariel Gael Gutierrez
// State the IDE that you use: Visual Studio

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Read before you start:
// You are given a partially complete program. Your job is to complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You should not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.

// Global Macro Values. They are used to define the size of 2D array of integers
#define NUM_ROWS 5
#define NUM_COLUMNS 5

#define NUM_STRINGS 5 
#define STRING_LENGTH 50

/* Forward Declarations */
void printMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void printAddScalar(int[NUM_ROWS][NUM_COLUMNS], int);
void squaredDiffMatrices(int[NUM_ROWS][NUM_COLUMNS], int[NUM_ROWS][NUM_COLUMNS]);
void rotateClockwiseMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void verticalFlipMatrix(int[NUM_ROWS][NUM_COLUMNS]);
int numOfVowelsChar(char s[NUM_STRINGS * STRING_LENGTH]);
char* concatOriginalReverseStrings(char strings[NUM_STRINGS * STRING_LENGTH]);

// Problem 1: printMatrix (5 points)
// Traverse the 2D array of integers variable 'matrix' (input from main)
// and print the contents in the following format (actual contents may vary)
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25
void printMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	// Enter code below
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

// Problem 2: printAddScalar (5 points)
// Traverse the 2D array of integers 'matrix', add scalar (input from main) to each element in the matrix
// and print it.
// e.g.
// int scalar = 10
// 1 2 3	    11 12 13
// 4 5 6	=>  14 15 16
// 7 8 9        17 18 19
void printAddScalar(int matrix[NUM_ROWS][NUM_COLUMNS], int scalar)
{
    // Enter code below
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			printf("%d ", matrix[i][j] + scalar);
		}
		printf("\n");
	}
}

// Problem 3: printSumDiagonal (5 points)
// Traverse the 2D array of integers 'matrix' and print the sum of the numbers in the matrix located diagonally
// from top left to bottom right position.
// e.g.
// 1 2 3		15
// 4 5 6	=>
// 7 8 9
void printSumDiagonal(int matrix[NUM_ROWS][NUM_COLUMNS])
{
    int sum = 0;
    // Enter code below
	for (int i = 0; i < NUM_ROWS; i++)
	{
		sum += matrix[i][i];
	}
	printf("%d\n", sum);
}

// Problem 4: squaredDiffMatrices (5 points)
// Traverse the 2D array of integers 'matrices' and print the difference of each squared value.
// Consider both matrices are of same dimensions.
// e.g.
// 1 2 3   1 2 3        0 0 0
// 4 5 6   1 2 3	=> 15 21 27
// 7 8 9   1 2 3 	   48 60 72
void squaredDiffMatrices(int matrix1[NUM_ROWS][NUM_COLUMNS], int matrix2[NUM_ROWS][NUM_COLUMNS])
{
    // Enter code below
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			printf("%d ", (matrix1[i][j] * matrix1[i][j]) - (matrix2[i][j] * matrix2[i][j]));
		}
		printf("\n");
	}
}

// Problem 5: rotateClockwiseMatrix (10 points)
// Take the 2D array of integers 'matrix' and print the matrix rotated 90 degrees clockwise.
// **Hint: Use printMatrix to print the result**
// e.g.
// 1 2 3	    7 4 1
// 4 5 6	=>  8 5 2
// 7 8 9        9 6 3
void rotateClockwiseMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	int matrix2[NUM_ROWS][NUM_COLUMNS];
	// Enter code below
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			matrix2[i][j] = matrix[(NUM_ROWS - 1) - j][i];
		}
	}
	printMatrix(matrix2);
}

// Problem 6: verticalFlipMatrix (10 points)
// Take the 2D array of integers 'matrix' and print the matrix flipped vertically.
// **Hint: Use printMatrix to print the result**
// e.g.
// 1 2 3	    3 2 1
// 4 5 6	=>  6 5 4
// 7 8 9        9 8 7
void verticalFlipMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
    int matrix2[NUM_ROWS][NUM_COLUMNS];
    // Enter code below
	for (int j = 0; j < NUM_COLUMNS; j++)
	{
		for (int i = 0; i < NUM_ROWS; i++)
		{
			matrix2[i][(NUM_COLUMNS-1)-j] = matrix[i][j];
		}
	}
	printMatrix(matrix2);
}

// Problem 7: concatOriginalReverseStrings (5 points)
// Make a new string by concatenating the original string to its reverse.
// You CANNOT use any string functions except for strlen().
// e.g.
// Hi Hello   => Hi HelloolleH iH
char* concatOriginalReverseStrings(char strings[NUM_STRINGS * STRING_LENGTH])
{
	int i, len;
	len = strlen(strings);
	char *new_string = (char *) malloc(2 * len + 1);
	// Enter code below
	for (i = 0; i < len; i++)
	{
		new_string[i] = strings[i];
	}

	int j = len-1;
	for (i; i < 2*len; i++)
	{
		new_string[i] = strings[j];
		j--;
	}
	new_string[i] = '\0';
	return new_string;
}

// Problem 8: numOfVowelsChar (5 points)
// Count all occurrences of vowel characters.
int numOfVowelsChar(char s[NUM_STRINGS * STRING_LENGTH])
{
    // Enter code below
	int len = strlen(s);
	char vowels[] = "aeiouAEIOU";
	int numVowels = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < strlen(vowels); j++)
		{
			if (s[i] == vowels[j])
			{
				numVowels++;
			}
		}
	}
	return numVowels;
}

// You should study and understand how this main() works.
// *** DO NOT modify it in any way ***
int main()
{
	printf("CSE240 HW3: 2D Integer Arrays\n\n");

	int matrix1[NUM_ROWS][NUM_COLUMNS] =
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};
	int matrix2[NUM_ROWS][NUM_COLUMNS] = {
	        {1, 2, 3, 4, 5},
	        {1, 2, 3, 4, 5},
	        {1, 2, 3, 4, 5},
	        {1, 2, 3, 4, 5},
	        {1, 2, 3, 4, 5}
	};
	int scalar = 10;

	printMatrix(matrix1);
	printf("\n\n");
	printAddScalar(matrix1, scalar);
	printf("\n\n");
	printSumDiagonal(matrix1);
	printf("\n\n");
	squaredDiffMatrices(matrix1, matrix2);
	printf("\n\n");
	rotateClockwiseMatrix(matrix1);
	printf("\n\n");
	verticalFlipMatrix(matrix1);

	char words[NUM_STRINGS * STRING_LENGTH];
	printf("\nEnter sentence with max 5 words: ");
	fgets(words, sizeof(words), stdin);
	words[strcspn(words, "\n")] = 0;
	// printf("%s", words);
	char* new_string = concatOriginalReverseStrings(words);
	printf("\nNew string: %s", new_string);

	printf("\nNumber of occurences of vowels: %d", numOfVowelsChar(words));
	int i = getchar();
	i = getchar(); // Keep console open
	return 0;
}
