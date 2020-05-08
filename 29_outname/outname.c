#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
	const char *ext = ".counts";
	char *outName = malloc(strlen(inputName) + strlen(ext) + 1);
	strcpy(outName, inputName);
	strcat(outName, ext);

	return outName;
}
