//
//  enigma.h
//  EnigmaC
//
//  Created by Thomas on 10/6/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#ifndef engima_h
#define enigma_h

#include <stdio.h>
#include <stdlib.h>
#include "rotor.h"

#endif /* rotors_h */


typedef struct enigma {
    Rotor** rotorArr;
    Rotor* reflector;
	Rotor* plugBoard;
    int len;
} Enigma;

int mapCharToInt(char c);

char mapIntToChar(int i);

char translate(Enigma* rs, char c);

void printEnigma(Enigma* e, int numOfRotors);
