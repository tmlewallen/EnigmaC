//
//  rotor_generator.c
//  EnigmaC
//
//  Created by Thomas on 10/8/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#include "rotor_generator.h"
#ifndef RAND_MAX
#define RAND_MAX 32767
#endif


Rotors* generateRotors(int numberOfRotors, int seed){
    srand((unsigned)seed);
    Rotors* rotors = malloc(sizeof(Rotors));
	Rotor** rotorArr = malloc(sizeof(Rotor*) * numberOfRotors - 1);
	for (int i = 0; i < numberOfRotors - 1; i++){
		rotorArr[i] = buildRandomRotor();
	}
	rotors->rotorArr = rotorArr;
	rotors->reflector = buildReflector();
	rotors->len = numberOfRotors - 1; //1 rotor is reflector
    return rotors;
}

Rotor* buildRandomRotor(){
	Rotor* rotor = malloc(sizeof(Rotor));
	//Initialize positions
	rotor->offset = 0;
	rotor->turnCounter = 0;
	
	//generate turn threshold for a rotor
	rotor->turnThreshold = -1;

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
	
//	printf("INPUT      OUTPUT\n");
//	for (int i = 0; i < 26; i++){
//	printf("%c -> %c, %c -> %c\n", mapIntToChar(i), mapIntToChar(input[i]), mapIntToChar(input[i]),mapIntToChar(output[input[i]]));
//	}
	
	rotor->input = input;
	rotor->output = output;
	return rotor;
}

Rotor* buildReflector() {
	Rotor* rotor = malloc(sizeof(Rotor));
	rotor->offset = 0;
	rotor->turnCounter = 0;
	rotor->turnThreshold = rand() % 26;
	
	//allocate character map arrays
	int* input = malloc(sizeof(int) * 26);
	int* output = malloc(sizeof(int) * 26);
	
	//populate character maps with 0-25
	for (int i = 0; i < 14; i++){
		int opposite = 25-i;
		input[i] = opposite;
		input[opposite] = i;
	}
//	printf("Reflector...\n");
//	printf("INPUT      OUTPUT\n");
//	for (int i = 0; i < 26; i++){
//		printf("%c -> %c, %c -> %c\n", mapIntToChar(i), mapIntToChar(input[i]), mapIntToChar(input[i]),mapIntToChar(output[input[i]]));
//	}
	
	rotor->input = input;
	rotor->output = output;
	return rotor;
}

void shuffle(int *array, int* recipricol, size_t n)
{
	if (n > 1) {
		int i;
		for (i = 0; i < n - 1; i++) {
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
			recipricol[array[i]] = i;
			recipricol[array[j]] = j;
		}
	}
}
