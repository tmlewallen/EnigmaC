//
//  enigma_generator.h
//  EnigmaC
//
//  Created by Thomas on 10/8/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#ifndef enigma_generator_h
#define enigma_generator_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "enigma.h"

#endif /* rotor_generator_h */

Enigma* generateEnigma(int numberOfRotors, int numOfPlugs, int seed);
Rotor* buildRandomRotor();
Rotor* buildReflector();
Rotor* buildPlugboard(int numOfPlugs);
void shuffle(int* array, int* recipricol, size_t n);
