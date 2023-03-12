#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



Process *scan_tokens(char **tokens)
{

	Process *result = (Process *) malloc(sizeof(Process));

	if (result == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	result->pipe = NULL;	

	Process *cur = result;

	
	for (int ix = 0; tokens[ix]; ix++) {
		if (cur->program_name == NULL) {
			cur->program_name = tokens[ix];
		}
		else if (tokens[ix][0] == '|') {
			cur->pipe = (Process *) malloc(sizeof(Process));
			cur = cur->pipe;	
			cur->pipe= NULL;
		}
		else {
			cur->args 	
		}
		
	}
	








	return result;
}


