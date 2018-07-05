//
//  enigma_generator.c
//  EnigmaC
//
//  Created by Thomas on 10/8/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#include "enigma_generator.h"
#ifndef RAND_MAX
#define RAND_MAX 32767
#endif


Enigma* generateEnigma(int numberOfRotors, int numOfPlugs, int seed){
    srand((unsigned)seed);
    Enigma* e = malloc(sizeof(Enigma));
	Rotor** rotorArr = malloc(sizeof(Rotor*) * numberOfRotors - 1);
	for (int i = 0; i < numberOfRotors - 1; i++){
		rotorArr[i] = buildRandomRotor();
	}
	e->rotorArr = rotorArr;
	e->reflector = buildReflector();
	e->plugBoard = buildPlugboard(numOfPlugs);
	e->len = numberOfRotors - 1; //1 rotor is reflector
    return e;
}

Rotor* buildRandomRotor(){
	Rotor* rotor = malloc(sizeof(Rotor));
	//Initialize positions
	rotor->offset = rand() % 26;
	rotor->turnCounter = 0;
	
	//generate turn threshold for a rotor
	rotor->turnThreshold = rand() % 26;

	//allocate character map arrays
	int* input = malloc(sizeof(int) * 26);
	int* output = malloc(sizeof(int) * 26);
	
	//populate character maps with 0-25
	for (int i = 0; i < 26; i++){
		input[i] = i;
		output[i] = i;
	}
	//shuffle the arrays
	shuffle(input, output, 26);
	
//	printf("INPUT     OUTPUT\n");
//	for (int i = 0; i < 26; i++){
//		printf("%c -> %c, %c -> %c\n", mapIntToChar(i), mapIntToChar(input[i]), mapIntToChar(i),mapIntToChar(output[i]));
//	}
	
	rotor->input = input;
	rotor->output = output;
	return rotor;
}

Rotor* buildReflector() {
	Rotor* rotor = malloc(sizeof(Rotor));
	rotor->offset = 0;
	rotor->turnCounter = 0;
	rotor->turnThreshold = -1;
	
	//allocate character map arrays
	int* input = malloc(sizeof(int) * 26);
	int* output = malloc(sizeof(int) * 26);
	
	for (int i = 0; i < 26; i++){
		input[i] = i;
		output[i] = i;
	}
	
	//populate character maps with 0-25
	bool flipped[26];
	for (int i = 0; i < 26; i++){
		flipped[i] = false;
	}
	for (int i = 0; i < 26; i++){
		int ndxA = i;
		if (flipped[i]){
			continue;
		}
		int ndxB = rand() % 26;
		if (flipped[ndxB]) { //if random index is already flipped...
			ndxB = 25;
			while (flipped[ndxB] && ndxB > i){ //iterate backwards over array to find non-flipped ndx
				ndxB--;
			}
		}
		flipped[ndxA] = true;
		flipped[ndxB] = true;
		int s = input[ndxA];
		input[ndxA] = input[ndxB];
		input[ndxB] = s;
	}
	
	rotor->input = input;
	rotor->output = output;
	return rotor;
}

Rotor* buildPlugboard(int numOfPlugs) {
	Rotor* rotor = malloc(sizeof(Rotor));
	rotor->offset = 0;
	rotor->turnCounter = 0;
	rotor->turnThreshold = -1;
	
	//allocate character map arrays
	int* input = malloc(sizeof(int) * 26);
	
	for (int i = 0; i < 26; i++){
		input[i] = i;
	}
	
	//populate character maps with 0-25
	bool flipped[26];
	for (int i = 0; i < 26; i++){
		flipped[i] = false;
	}
	for (int i = 0; i < numOfPlugs; i++){
		int ndxA = rand() % 26;
		if (flipped[ndxA]){
			while(flipped[ndxA]){
				ndxA = (ndxA + 1) % 26;
			}
		}
		int ndxB = rand() % 26;
		if (flipped[ndxB]) { //if random index is already flipped...
			while(flipped[ndxB]){
				ndxB = (ndxB + 1) % 26;
			}
		}
		flipped[ndxA] = true;
		flipped[ndxB] = true;
		int s = input[ndxA];
		input[ndxA] = input[ndxB];
		input[ndxB] = s;
	}
	rotor->input = input;
	return rotor;
}


void shuffle(int *array, int* reciprocal, size_t n)
{
	if (n > 1) {
		int i;
		for (i = 0; i < n - 1; i++) {
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
			reciprocal[array[i]] = i;
			reciprocal[array[j]] = j;
		}
	}
}
