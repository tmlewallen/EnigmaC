//
//  rotor.c
//  EnigmaC
//
//  Created by Thomas on 10/6/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#include "rotor.h"
#include <stdio.h>


void advanceRotor(Rotor* r, int i){
	if (r->turnThreshold < 0){
		return;
	}
    r->turnCounter++;
    if (r->turnCounter >= r->turnThreshold){
        r->turnCounter = 0;
        r->offset++;
//		printf(" Advancing Rotor... ");
//		printRotor(r);
        if (r->offset > 25){
            r->offset = 0;
        }
    }
    else{
        r->turnCounter++;
    }
}

int input(Rotor* r, int a){
    advanceRotor(r, 1);
    int actualNdx = (a + r->offset) % 26;
    return r->input[actualNdx];
}

int output(Rotor* r, int a){
	int val = r->output[a];
	val = val - r->offset;
	if (val < 0){
		val = 26 + val;
	}
    return val;
}

void printRotor(Rotor* rotor){
	int* input = rotor->input;
	int* output = rotor->output;
	int offset = rotor->offset;
//	printf("Input: [");
//	for (int i = 0; i < 26; i++){
//		printf("%d, ", rotor->input[i]);
//	}
//	printf("]\n");
//	printf("Output: [");
//	for (int i = 0; i < 26; i++){
//		printf("%d, ", rotor->output[i]);
//	}
//	printf("]\n");
	printf("INPUT     OUTPUT\n");
	for (int i = 0; i < 26; i++){
		int k = (i + offset) % 26;
		printf("%d -> %d, %d -> %d\n", i, input[k], output[i], output[input[i]] + k);
	}
	
}
