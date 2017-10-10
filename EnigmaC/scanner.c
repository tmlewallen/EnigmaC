//
//  scanner.c
//  EnigmaC
//
//  Created by Thomas on 10/10/17.
//  Copyright © 2017 Thomas. All rights reserved.
//
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif
#include <stdbool.h>
#include <stdlib.h>
#include "scanner.h"


bool readChar(FILE *fp, char* c){
	int result = fscanf(fp, "%c", c);
	if (result == EOF){
		return false;
	}
	if (result == 0){
		fprintf(stderr, "Error reading char <%c>", fgetc(fp));
		return false;
	}
	return true;
}

char* readMessage(FILE *fp){
	int charCount = 0;
	int bufferCount = 1;
	char* buffer = malloc(sizeof(char) * BUFFER_SIZE);
	
	char c;
	while(readChar(fp, &c)){
		if (charCount > bufferCount * BUFFER_SIZE){
			bufferCount++;
			buffer = realloc(buffer, sizeof(char) * bufferCount * BUFFER_SIZE);
		}
		int cInt = (int) c;
		if (cInt >= 97 && cInt <= 122){
			cInt = cInt - 32;
			c = (char) cInt;
		}
		if ((cInt >= 65 && cInt <= 90) || cInt == 32 || cInt == 10 || cInt == 13){
			buffer[charCount] = c;
			charCount++;
		}
	}
	
	char* result = malloc(sizeof(char) * charCount);
	for (int i = 0; i < charCount; i++){
		result[i] = buffer[i];
	}
	free(buffer);
	return result;
}
