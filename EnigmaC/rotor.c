//
//  rotor.c
//  EnigmaC
//
//  Created by Thomas on 10/6/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#include "rotor.h"


void advanceRotor(Rotor* r, int i){
    r->turnCounter++;
    if (r->turnCounter >= r->turnThreshold){
        r->turnCounter = 0;
        r->offset++;
        if (r->offset >= 26){
            r->offset = 0;
        }
    }
    else{
        r->turnCounter++;
    }
}

int input(Rotor* r, int a){
    advanceRotor(r, 1);
    int actualNdx = a + r->offset % 26;
    return r->input[actualNdx];
}

int output(Rotor* r, int a){
    advanceRotor(r, 1);
    int actualNdx = a + r->offset % 26;
    return r->output[actualNdx];
}
