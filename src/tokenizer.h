#ifndef TOKENIZER_H
#define TOKENIZER_H

#define MAX_BUF 128

enum TokenType {
	TOKEN_PIPE,
	TOKEN_
};



typedef struct Process {
	Process *pipe;
	char *program_name;
	char **args;
} Process;


void init_tokenizer(const char *source);

Process *scan_tokens(char **tokens);

#endif
