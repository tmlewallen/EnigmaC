//
//  enigma.c
//  EnigmaC
//
//  Created by Thomas on 10/6/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#include "enigma.h"

static char* r1 = "     +-----+";
static char* r2 = "     | +-+ +-+";
static char* r3 = "+----+ | | |";
static char* r4 = "|    | +-+ +-+";
static char* r5 = "|    | | | |";
static char* r6 = "|    | +-+ +-+";
static char* r7 = "|    | | | |";
static char* r8 = "|    | +-+ +-+";
static char* r9 = "|    | |%c| |";
static char* r10 ="|    | +-+ +-+";
static char* r11 ="|    | | | |";
static char* r12 ="|    | +-+ +-+";
static char* r13 ="|    | | | |";
static char* r14 ="|    | +-+ +-+";
static char* r15 ="+----+ | | |";
static char* r16 ="     | +-+ +-+";
static char* r17 ="     +-----+";

static char* rf1 ="   +------+";
static char* rf2 ="   |      +-+";
static char* rf3 ="+--+      |";
static char* rf4 ="|  |      +-+";
static char* rf5 ="|  |      |";
static char* rf6 ="|  |      +-+";
static char* rf7 ="|  |      |";
static char* rf8 ="|  |      +-+";
static char* rf9 ="|  |      |";
static char* rf10="|  |      +-+";
static char* rf11="|  |      |";
static char* rf12="|  |      +-+";
static char* rf13="|  |      |";
static char* rf14="|  |      +-+";
static char* rf15="+--+      |";
static char* rf16="   |      +-+";
static char* rf17="   +------+";



int mapCharToInt(char c){
    int intVal = (int)c;
    if (intVal >= 97 && intVal <= 122){
        intVal = intVal - 32;
    }
    return intVal - 65;
}

char mapIntToChar(int i){
    return (char) i + 65;
}

char translate(Enigma* rs, char c){
//	printf("\n\nTranslating input %c\n", c);
	int asciiChar = (int) c;
	if (asciiChar == 32 || asciiChar == 10 || asciiChar == 13){
		return c;
	}
    int ndx = mapCharToInt(c);
	Rotor* plugBoard = rs->plugBoard;
	ndx = plugBoard->input[ndx];
//	printf("Input...\n");
    for (int i = 0; i < rs->len; i++){
//		printf("Rotor : %d\n", i);
//		printf("%c -> ", mapIntToChar(ndx));
        Rotor* r = rs->rotorArr[i];
        ndx = input(r, ndx);
//		printf("(ndx = %d, %c)\n", ndx, mapIntToChar(ndx));
    }
//	printf("Reflector...\n");
    Rotor* reflector = rs->reflector;
//	printf("%c -> ", mapIntToChar(ndx));
    ndx = input(reflector, ndx);
//	printf("%c\n", mapIntToChar(ndx));
//	printf("Output...\n");
    for (int i = rs->len-1; i >= 0; i--){
//		printf("Rotor : %d\n", i);
//		printf("%c -> ", mapIntToChar(ndx));
        Rotor* r = rs->rotorArr[i];
        ndx = output(r, ndx);
//		printf("%c\n", mapIntToChar(ndx));
    }
	ndx = plugBoard->input[ndx];
    return mapIntToChar(ndx);
}

void printEnigma(Enigma* e, int numOfRotors){
	char* inputs = malloc(sizeof(char) * 52);
	char* outputs = malloc(sizeof(char) * 52);
	for (int i = 0; i < numOfRotors - 1; i++){
		Rotor* r = e->rotorArr[i];
		
		for (int j = 0; j < 52; j = j + 2){
			inputs[j] = mapIntToChar(j / 2);
			inputs[j+1] = ' ';
			outputs[j] = mapIntToChar(r->input[j / 2]);
			outputs[j+1] = ' ';
		}
		char* rStr = malloc(sizeof(char) * 12);
		char startPos = mapIntToChar(r->offset);
		int turnP = r->turnThreshold;
		sprintf(rStr, r9, startPos);
		printf("ROTOR %d : \n", i + 1);
		printf("%s\n", r1);
		printf("%s\n", r2);
		printf("%s\n", r3);
		printf("%s\n", r4);
		printf("%s\n", r5);
		printf("%s Mapping: %s\n", r6, inputs);
		printf("%s            %s\n", r7, outputs);
		printf("%s\n", r8);
		printf("%s   Starting Position : %c\n", rStr, startPos);
		printf("%s\n", r10);
		printf("%s   Turn Period : %d\n", r11, turnP);
		printf("%s\n", r12);
		printf("%s\n", r13);
		printf("%s\n", r14);
		printf("%s\n", r15);
		printf("%s\n", r16);
		printf("%s\n", r17);
		free(rStr);
	}
	Rotor* r = e->reflector;
	for (int j = 0; j < 52; j = j + 2){
		inputs[j] = mapIntToChar(j / 2);
		inputs[j+1] = ' ';
		outputs[j] = mapIntToChar(r->input[j / 2]);
		outputs[j+1] = ' ';
	}
	printf("REFLECTOR : \n");
	printf("%s\n", rf1);
	printf("%s\n", rf2);
	printf("%s\n", rf3);
	printf("%s\n", rf4);
	printf("%s\n", rf5);
	printf("%s Mapping: %s\n", rf6, inputs);
	printf("%s            %s\n", rf7, outputs);
	printf("%s\n", rf8);
	printf("%s\n", rf9);
	printf("%s\n", rf10);
	printf("%s\n", rf11);
	printf("%s\n", rf12);
	printf("%s\n", rf13);
	printf("%s\n", rf14);
	printf("%s\n", rf15);
	printf("%s\n", rf16);
	printf("%s\n", rf17);
	
	r = e->plugBoard;
	inputs = malloc(sizeof(char) * 52);
	outputs = malloc(sizeof(char) * 52);
	for (int j = 0; j < 52; j = j + 2){
 		char c1 = mapIntToChar(j / 2);
		char c2 = mapIntToChar(r->input[j/2]);
		if (c1 == c2){
			c1 = ' ';
			c2 = ' ';
		}
		inputs[j] = c1;
		outputs[j] = c2;
		inputs[j+1] = ' ';
		outputs[j+1] = ' ';
	}
	printf("PLUGBOARD : \n");
	printf("   Mapping: %s\n", inputs);
	printf("            %s\n", outputs);
	free(inputs);
	free(outputs);
}
