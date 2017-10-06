//
//  rotor.h
//  EnigmaC
//
//  Created by Thomas on 10/6/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#ifndef rotor_h
#define rotor_h


#endif /* rotor_h */

typedef struct rotor {
    int* input;
    int* output;
    int offset;
    int turnThreshold;
    int turnCounter;
} Rotor;

void advanceRotor(Rotor* r, int i);

int input(Rotor* r, int a);

int output(Rotor* r, int a);
