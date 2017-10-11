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
#include "scanner.h"

#define DEFAULT_SEED 1024

//args: random seed --seed
//message (file)
int main(int argc, const char * argv[]) {
    int seed = DEFAULT_SEED;
    char* filename = "";
    char* message = "";
	unsigned long msgLen = 0;
	int numOfRotors = 3;
	int numOfPlugs = 2;
	
    bool seedInput = false;
    bool fileInput = false;
    bool messageInput = false;
	bool numOfRotorsInput = false;
	bool plugsInput = false;
	
    if (argc == 1){
        printf("Usage: enigma {text} [--file] [--seed] [--rotors] [--plugs]\n");
        return 1;
    }
    int i = 1;
    while (i < argc){
        if (strcmp(argv[i], "--file") == 0 && i+1 < argc){
			filename = malloc(strlen(argv[i+1] + 1));
            strcpy(filename, argv[i+1]);
            fileInput = true;
            i++;
        }
        else if (strcmp(argv[i], "--seed") == 0 && i+1 < argc){
            seed = atoi(argv[i+1]);
            seedInput = true;
            i++;
        }
		else if (strcmp(argv[i], "--rotors") == 0 && i+1 < argc){
			numOfRotors = atoi(argv[i+1]);
			numOfRotorsInput = true;
			i++;
		}
		else if (strcmp(argv[i], "--plugs") == 0 && i+1 < argc){
			numOfPlugs = atoi(argv[i+1]);
			plugsInput = true;
			i++;
		}
        else{
			msgLen = strlen(argv[i]);
			message = malloc(msgLen);
            strcpy(message, argv[i]);
            messageInput = true;
        }
        i++;
    }
    if (!seedInput){
        printf("No seed provided. Using 1024 as seed...\n");
    }
	if (!numOfRotorsInput){
		printf("No rotor count provided. Defaulting to 3...\n");
	}
	if (!plugsInput){
		printf("No plug count provided. Defaulting to 2...\n");
	}
	if (fileInput){
		FILE* fp = fopen(filename, "r");
		if (fp == NULL){
			fprintf(stderr, "Error opening file %s", filename);
		}
		message = readMessage(fp);
		msgLen = strlen(message);
	}
    Enigma* e = generateRotors(numOfRotors, numOfPlugs, seed);
	char* encryptedMsg = malloc(msgLen);
	for (unsigned long i = 0; i < msgLen; i++){
//		printf("%c (%d) -> %d\n", message[i], (int)message[i], mapCharToInt(message[i]));
		encryptedMsg[i] = translate(e, message[i]);
	}
	printf("%s\n", encryptedMsg);
    return 0;
}
