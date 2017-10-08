//
//  main.c
//  EnigmaC
//
//  Created by Thomas on 10/6/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "rotor_generator.h"

#define DEFAULT_SEED 1024

//args: random seed --seed
//message (file)
int main(int argc, const char * argv[]) {
    // insert code here...
    int seed = DEFAULT_SEED;
    char* filename = "";
    char* message = "";
    bool seedInput = false;
    bool fileInput = false;
    bool messageInput = false;
    if (argc == 1){
        printf("Usage: enigma {text} [--file] [--seed]\n");
        return 1;
    }
    int i = 1;
    while (i < argc){
        if (strcmp(argv[i], "--file") == 0 && i+1 < argc){
            strcpy(filename, argv[i+1]);
            fileInput = true;
            i++;
        }
        else if (strcmp(argv[i], "--seed") == 0 && i+1 < argc){
            seed = atoi(argv[i+1]);
            seedInput = true;
            i++;
        }
        else{
            strcpy(message, argv[i]);
            messageInput = true;
        }
        i++;
    }
    if (!seedInput){
        printf("No seed provided. Using 1024 as seed...");
    }
    Rotors* rotors = generateRotors(seed);
        
    

    return 0;
}
