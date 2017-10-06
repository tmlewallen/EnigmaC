//
//  main.c
//  EnigmaC
//
//  Created by Thomas on 10/6/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#include <stdio.h>
#include "rotors.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Rotor* rotor = (Rotor*) malloc(sizeof(Rotor));
    int alphaInArr[26];
    for (int i = 0; i < 26; i++){
        alphaInArr[i] = i;
    }
    int alphaOutArr[26];
    for (int i = 0; i < 26; i++){
        alphaOutArr[i] = i;
    }
    rotor->input = alphaInArr;
    rotor->output = alphaOutArr;
    rotor->offset = 0;
    
    
    printf("Hello, World!\n");
    return 0;
}
