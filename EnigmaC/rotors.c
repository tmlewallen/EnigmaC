//
//  rotors.c
//  EnigmaC
//
//  Created by Thomas on 10/6/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#include "rotors.h"

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

char translate(Rotors* rs, char c){
	printf("\n\nTranslating input %c\n", c);
    int ndx = mapCharToInt(c);
	printf("Input...\n");
    for (int i = 0; i < rs->len; i++){
		printf("Rotor : %d\n", i);
		printf("%c -> ", mapIntToChar(ndx));
        Rotor* r = rs->rotorArr[i];
        ndx = input(r, ndx);
		printf("(ndx = %d, %c)\n", ndx, mapIntToChar(ndx));
    }
	printf("Reflector...\n");
    Rotor* reflector = rs->reflector;
	printf("%c -> ", mapIntToChar(ndx));
    ndx = input(reflector, ndx);
	printf("%c\n", mapIntToChar(ndx));
	printf("Output...\n");
    for (int i = rs->len-1; i >= 0; i--){
		printf("Rotor : %d\n", i);
		printf("%c -> ", mapIntToChar(ndx));
        Rotor* r = rs->rotorArr[i];
        ndx = output(r, ndx);
		printf("%c\n", mapIntToChar(ndx));
    }
    return mapIntToChar(ndx);
}
