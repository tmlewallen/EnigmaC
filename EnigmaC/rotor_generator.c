//
//  rotor_generator.c
//  EnigmaC
//
//  Created by Thomas on 10/8/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#include "rotor_generator.h"


Rotors* generateRotors(int seed){
    srand((unsigned)seed);
    Rotors* rotors = malloc(sizeof(Rotors));
    return rotors;
}
