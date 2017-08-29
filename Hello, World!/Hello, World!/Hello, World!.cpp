// Hello, World!.cpp : How many different ways can I write my greetings to the world.
// Christopher Fischer
// 8/28/2017
// Valencia Community College

#include "stdafx.h";
#include <time.h>
#include <iostream>
#include <malloc.h>
#include <Windows.h>


// Uses puts.
void outSloppy(char* phrase) {
	puts(phrase);
	Sleep(200);
}
// Uses printf, which is more useful then puts but is be a security risk if you code it like I have.
// (if you're wondering what I'm talking about, change one of the greetings to a word then %i%i%i%i%i)
void outClean(char* phrase) {
	printf(phrase);
	Sleep(200);
}
// Returns a random int, allowing mod and sum to determain range.
int getRand(int mod, int sum) {
	return (rand() % mod) + sum;
}
// Uses printf, choosing random characters and backing out until it has the correct one.
void printRandom(char phrase[]) {
	// Its easier just to pass in the char array.
	printf("\n");
	for (int i = 0; phrase[i + 1] != '\0'; i++) {
		char randomCharacter = getRand(90, 32);
		printf("%c", randomCharacter);
		do
		{
			printf("\b");
			randomCharacter = getRand(90, 32);
			printf("%c", randomCharacter);
			Sleep(3);
		} while (randomCharacter != phrase[i]);
		//printf("\nEquals, %i  %i\n", (int)((r % 90) + 33, (int)*phrase));
	}
	printf("\n");
}
// Creates a folder in working dir with the system command.
void printFolder(char phrase[]) {
	// offset is length of the command.
	const int offset = sizeof("mkdir \"") - 1;;
	char command[40] = "mkdir \"";
	for (int i = 0; phrase[i] != '\0'; i++) {
		command[i + offset] = phrase[i];

		// Are we on our last letter?
		if (phrase[i + 1] == '\0') {
			command[i + offset] = '\"';
		}
	}
	system(command);
}
// Function creates a txt and a dat file containing the string.
void printToFile(char phrase[]) {
	const char datName[8] = "buf.dat"; // hehe
	const char* writingMode = "a";
	FILE* stream = fopen(datName, writingMode);
	fprintf(stream, phrase);
	fclose(stream);
}
// Asks if you like pie. Demonstration of simple input/output and an switch statement & recursion.
void doYouLikePie(int counter) {
	if (counter == 3) {
		// Wherever we take input, sometimes we get unexpected results.
		// So we'll ask the user three times then just quit if it doesn't work.
		return;
	}
	printf("\nDo you like pie?\n");
	char response[50];
	scanf("%s", response);
	switch (response[0]) {
	case 'y':
	case 'Y':
		printf("I like pie too!");
		break;
	case 'n':
	case 'N':
		printf("You heathen! How could you.");
		break;
	default:
		printf("I didn't understand that.");
		doYouLikePie(counter + 1);
	}
	printf("\n");
}
// Helper function.
int zeroOne(char c) {
	switch (c) {
	case '1':
		return 1;
		break;
	default:
		return 0;
		break;
	}
}
// Takes in eight ASCII ones and zeros and turns it into the character.
void binaryInput() {
	printf("\nPlease put in eight ones and zeros.\n");
	char response[16];
	scanf("%s", response);
	printf("%s", response);
	char asciiChar = 0;
	for (int i = 7; i >= 0; i--) {
		// This is a spegetti statement, so I'll break it down here.
		// We're adding to the integer value of final.
		// We find out if it's a zero or a one.
		// We then multiply that int by 2 to the power of
		// it's place.
		printf("\nAdding %i  -   The current index is %i, and the current number is %i, power is %i", ((zeroOne(response[i]))*(2 ^ (8 - i))), (i), zeroOne(response[i]), ((2 ^ (8 - i))));
		asciiChar += ((zeroOne(response[i])))*(2 ^(8 - i));
	}
	printf("%i", asciiChar);
	printf("%c", asciiChar);
}

int main()
{
	// Need to do the srand to init seed program wide.
	srand(time(NULL));

	// Declare our greetings.
	char greetings[3][20] = { "Hello, World!\n", "'ello, Mate!\n", "'ello, Poppet!\n" };
	// Store into a pointer as it's easier to write.
	char* greeting = greetings[getRand(3, 0)];

	// Function calls. 
	outSloppy(greeting);
	Sleep(300);
	outClean(greeting);
	Sleep(300);
	printRandom(greeting);
	Sleep(300);
	printFolder(greeting);
	Sleep(300);
	doYouLikePie(0);
	Sleep(300);
	printToFile(greeting);
	Sleep(300);
	binaryInput();

	// Buffer keeps it from closing right away.
	char response[50];
	scanf("%s", response);
	return 0;
}



/*
The sources below are broken up by function and what specifically I used them for.

printToFile - Computer Science, A Structured Approach to C pages 400-403. Taught me to use fputs

*/