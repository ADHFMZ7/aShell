#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUF_LEN 128 
#define MAX_ARG 64

void allocation_failure() {
	fprintf(stderr, "Memory allocation failed\n");
	exit(EXIT_FAILURE);
}

Process *init_process(Process *new_pipe) {
	Process *result = (Process *) calloc(1, sizeof(Process));
	if (result == NULL) {
		allocation_failure();
	}
	result->argv = (char **) malloc(BUF_LEN * sizeof(char*));
	if (result->argv == NULL) {
		allocation_failure();
	}
	result->pipe = new_pipe;
	return result;
}



Process *scan_tokens(char **tokens)
{

	Process *result = init_process(NULL);

	if (result == NULL) {
		allocation_failure();
	}

	Process *cur = result;

	
	for (int ix = 0; tokens[ix]; ix++) {
		if (cur->program_name == NULL) {
			cur->program_name = tokens[ix];
		}
		if (tokens[ix][0] == '|') {
			cur->pipe = init_process(cur);
			cur = cur->pipe;	
			continue;
		}
		cur->argv[cur->argc++] = tokens[ix];
	}
	return result;
}


