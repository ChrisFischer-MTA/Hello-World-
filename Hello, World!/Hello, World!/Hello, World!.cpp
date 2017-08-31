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
			Sleep(6);
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
// Math has a pow function, but I'd rather write my own.
int pow(int x, int y) {
	if (y == 0 || y < 0) {
		return 1;
	}
	else {
		return x*pow(x, y - 1);
	}
}
// Takes in eight ASCII ones and zeros and turns it into the character.
void binaryInput() {
	printf("\nPlease put in eight ones and zeros.\n");
	char response[9];
	scanf("%s", response);
	int currentValue = 0;
	int returnedSum = 0;
	for (int i = 7; i >= 0; i--) {
		//printf("\n\nIteration of loop- %i\n", i);
		currentValue = zeroOne(response[i]);
		currentValue = currentValue*(pow(2, (7 - i)));
		returnedSum += currentValue;
	}
	printf("The ASCII equivelent of what you typed is (assuming it's printable) -%c\n\n", returnedSum);
}
// Function should get a byte (taken as a char) and print out the binary value
void binaryOutput(char* phrase, int x, int length) {
	if (x == 0) {
		printf("This function translates ASCII back to binary and outputs it -");
	}
	if (x == length || x > length)
		return;
	int c = phrase[x];
	char arr[10];
	memset(arr, 0, 9);
	for (int i = 7; i >= 0; i--) {
		// We can safely assume 8, as that's the max char can hold.
		if (pow(2, i) <= c) {
			arr[7-i] = '1';
			c -= pow(2, i);
		}
		else {
			arr[7-i] = '0';
		}
	}
	printf("%s ",arr);
	binaryOutput(phrase, x + 1, length);
}
// Function should demonstrate printf spacers just because why not.
void rightLeftCenter(char* phrase) {
	printf("Go away I say!");
	printf("%60s\n", phrase);
	printf("Come back!");
	printf("%18s\n", phrase);
}
// Function should make a nice looking triangle.
void triangle(char* phrase) {
	int length = 0;
	for (int i = 0; phrase[i] != '\0'; i++) {
		if (phrase[i + 1] == '\0')
			length = i;
	}
	for (int i = 1; i < length+1; i++) {
		printf("%*c\n", -(length / length-i)+1, phrase[i-1]);
	}
	for (int i = 0; i < 3; i++) {
		printf("\n");
	}

	for (int i = length; i >= 0; i--) {
		printf("%*c\n", -(length / length - i) + 1, phrase[i - 1]);
	}
}
// Function to get length of char array with spaces as sizeof doesn't work for me.
int getSize(char* phrase) {
	for (int i = 0; phrase[i] != '\0'; i++) {
		if (phrase[i + 1] == '\0'){
			return i;
		}
	
	}
	return -1;
}
// Gets input and reads it backwards.
void goBackwards() {
	char response[30];
	printf("\n\nType something and I'll malform it. (No spaces please...)\n");
	printf("Backwards - ");
	scanf("%s", response);
	for (int i = getSize(response); i >= 0; i--) {
		printf("%c",response[i]);
	}
	printf(" \n");
	printf("\nEvery odd letter - ");
	for (int i = 1; i < getSize(response); i+=2) {
			printf("%c", response[i]);
	}
	printf("\n\nEvery even letter - ");
	for (int i = 0; i < getSize(response); i += 2) {
		printf("%c", response[i]);
	}
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
	Sleep(2000);
	outClean(greeting);
	Sleep(2000);
	printRandom(greeting);
	Sleep(2000);
	printFolder(greeting);
	Sleep(2000);
	doYouLikePie(0);
	Sleep(2000);
	printToFile(greeting);
	Sleep(2000);
	binaryInput();
	Sleep(2000);
	rightLeftCenter(greeting);
	Sleep(2000);
	triangle(greeting);
	Sleep(2000);
	binaryOutput(greeting, 0, getSize(greeting));
	Sleep(300);
	goBackwards();

	// Buffer keeps it from closing right away.
	char response[50];
	scanf("%s%s%s%s%s%s", response);
	return 0;
}



/*
The sources below are broken up by function and what specifically I used them for.

printToFile - Computer Science, A Structured Approach to C pages 400-403. Taught me to use fputs
randomCharacter - Learned the backspace from stdout from stack exchaange.

*/