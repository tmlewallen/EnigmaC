//
//  rotors.h
//  EnigmaC
//
//  Created by Thomas on 10/6/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#ifndef rotors_h
#define rotors_h

#include <stdio.h>
#include "rotor.h"

#endif /* rotors_h */


typedef struct rotors {
    Rotor** rotorArr;
    Rotor* reflector;
    int len;
} Rotors;

int mapCharToInt(char c);

char mapIntToChar(int i);

char translate(Rotors* rs, char c);
