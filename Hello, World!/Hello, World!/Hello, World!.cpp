// Hello, World!.cpp : How many different ways can I write my greetings to the world.
// Christopher Fischer
// 8/28/2017
// Valencia Community College

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <malloc.h>
#include <Windows.h>


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
// Returns a random int, allowing mod and sum to be two different controls on that int.
int getRandInt(int mod, int sum) {
	// I waste CPU cycles by doing the function this way.
	// But this is just easier to write and this doesn't
	// matter.
	return (rand() % mod) + sum;
}
// Uses printf, choosing random characters and backing out until it has the correct one.
void printRandom(char phrase[]) {
	// Its easier just to pass in the char array.
	printf("\n");
	for (int i = 0; phrase[i+1] != '\0'; i++) {
		char r = getRandInt(90, 32);
		printf("%c", r);
		do
		{	printf("\b");
			r = getRandInt(90, 32);
			printf("%c", r);
			Sleep(3);
		} while (r != phrase[i]);
		//printf("\nEquals, %i  %i\n", (int)((r % 90) + 33, (int)*phrase));
		}
	printf("\n");
	}
int main()
{
	// Need to do the srand to init seed program wide.
	srand(time(NULL));
	
	// Declare our greetings.
	char greetings[3][20] = { "Hello, World!\n", "'ello, Mate!\n", "'ello, Poppet!\n" };
	// Store into a pointer as it's easier to write.
	char* greeting = greetings[getRandInt(3,0)];

	// Function calls. 
	outSloppy(greeting);
	Sleep(200);
	outClean(greeting);
	Sleep(200);
	printRandom(greeting);
	Sleep(200);
	char* buffer = "esd";
	scanf(buffer);
	return 0;
}



/*
Sources.

Overall, I used stack exchange for a few things. A lot of the ideas came organically from my head, but I do occasionally either run into syntatical issues or I'm missing a piece of knowledge
(like in printRandom, I didn't know about how to back up in stdout.)

The sources below are broken up by function and what specifically I used them for.


*/