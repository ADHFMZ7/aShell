#ifndef TOKENIZER_H
#define TOKENIZER_H


enum TokenType {
	TOKEN_PIPE,
	TOKEN_EOF,
	TOKEN_RIGHT_BRACE,
	TOKEN_LEFT_BRACE
};



typedef struct {
	enum TokenType type;
	int line;
	int process;
} Token;


void init_tokenizer(const char *source);

void scan_tokens();

#endif
