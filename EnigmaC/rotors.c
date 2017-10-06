//
//  rotors.c
//  EnigmaC
//
//  Created by Thomas on 10/6/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#include "rotors.h"

int mapCharToInt(char c){
    int intVal = c - '0';
    if (intVal >= 97 && intVal <= 122){
        intVal = intVal - 32;
    }
    return intVal - 65;
}

char mapIntToChar(int i){
    return (char) i + 65;
}

char translate(Rotors* rs, char c){
    int ndx = mapCharToInt(c);
    for (int i = 0; i < rs->len; i++){
        Rotor* r = rs->rotorArr[i];
        ndx = input(r, ndx);
    }
    Rotor* reflector = rs->reflector;
    ndx = input(reflector, ndx);
    for (int i = rs->len-1; i >= 0; i--){
        Rotor* r = rs->rotorArr[i];
        ndx = output(r, ndx);
    }
    return mapIntToChar(ndx);
}
