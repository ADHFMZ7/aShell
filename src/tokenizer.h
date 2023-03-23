#ifndef TOKENIZER_H
#define TOKENIZER_H

#define MAX_BUF 128


typedef struct Process {
	struct Process *pipe;
	char *program_name;
	char **argv;
	int argc;
	char *input_file;
	char *output_file;
} Process;


void init_tokenizer(const char *source);

Process *scan_tokens(char **tokens);

#endif
