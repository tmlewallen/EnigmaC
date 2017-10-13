//
//  scanner.c
//  EnigmaC
//
//  Created by Thomas on 10/10/17.
//  Copyright © 2017 Thomas. All rights reserved.
//

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
	char c;
	while(readChar(fp, &c)) {
		charCount++;
	}
	rewind(fp);
	char* buffer = malloc(sizeof(char) * charCount);
	charCount = 0;
	while(readChar(fp, &c)){
		int cInt = (int) c;
		if (cInt >= 97 && cInt <= 122){
			cInt = cInt - 32;
			c = (char) cInt;
		}
		if ((cInt >= 65 && cInt <= 90) || c == 32 || c == '\n' || c == '\r'){
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
