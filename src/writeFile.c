/*
 * File: writeFile.c
 * ----------------
 * Writes restaurants to a file.
 * 
 * author: Max Turkot
 * version: 12/11/21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "writeFile.h"

/*
 * Writes a string with information about restaurants to a file with provided vilename.
 * 
 * char*: name of a new file.
 * char*: string with information about restaurants to be written.
 */
int writeFile(char* fileName, char* string) {
  FILE *outFile = fopen(fileName, "w");

  if (outFile == NULL) { // If failed to open a file.
    printf("Could not open file %s.\n", fileName);
    return -1;
  }

  fprintf(outFile, "%s", string);

  fclose(outFile);

  return 0;
}
