// Hello, World!.cpp : How many different ways can I write my greetings to the world.
// Christopher Fischer
// 8/28/2017
// Valencia Community College

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <malloc.h>
#include <Windows.h>

// Sloppy but this is just easier to make.



// Choose one of three random greetings.
int getIndex() {
	// Time isn't REALLY random, but it works here.
	return time(NULL) % 3;
}

// Uses puts, which for a variety of reasons I feel is useless in the real world.
void outSloppy(char* phrase) {
	puts(phrase);
	Sleep(200);
}

// Uses printf, which is more useful then puts but can be a security risk if you code it like I have.
void outClean(char* phrase) {
	printf(phrase);
	Sleep(200);
}

void printRandom(char* phrase) {
	srand(time(NULL));
	int r = (rand() % 90) + 33;
	// The root of the bug here is in the pointers. Gonna look at it with fresh eyes tommorow.
	for (int i = 0; *phrase; ++phrase) {
		printf("Looking for %c", *phrase);
		while ((int)((r% 90)+33) != (int)*phrase) {
			r = (rand() % 90) + 33;
			printf("%c", r);
			Sleep(50);
			printf("\b");
			}
		printf("\nEquals, %i  %i\n", (int)((r % 90) + 33, (int)*phrase));
		printf("%c ", r);
		}
	}




int main()
{
	char greetings[3][20] = { "Hello, World!\n", "'ello, Mate!\n", "'ello, Poppet!\n" };
	char* greeting = greetings[getIndex()];
	outSloppy(greeting);
	outClean(greeting);
	printRandom(greeting);
	//printf("cough %s",greeting);
	char* buffer = "esd";
	scanf(buffer);
	return 0;
}