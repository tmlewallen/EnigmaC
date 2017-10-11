//
//  rotor_generator.h
//  EnigmaC
//
//  Created by Thomas on 10/8/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#ifndef rotor_generator_h
#define rotor_generator_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "enigma.h"

#endif /* rotor_generator_h */

Enigma* generateRotors(int numberOfRotors, int numOfPlugs, int seed);
Rotor* buildRandomRotor();
Rotor* buildReflector();
void shuffle(int* array, int* recipricol, size_t n);
