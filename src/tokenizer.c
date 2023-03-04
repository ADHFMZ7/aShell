#include "tokenizer.h"

typedef struct {
	const char *start;
	const char *current;
	int line;
} Tokenizer;

// typedef struct {
// 	enum TokenType type;
// 	int line;
// 	int process;
// } Token;


Tokenizer tokenizer;


void init_tokenizer(const char *source)
{
	tokenizer.start = source;	
	tokenizer.current = source;
	tokenizer.line = 1;
}

Token scan_token()
{
	Token result;
	result.type =		TOKEN_RIGHT_BRACE;
	result.line = tokenizer.line;


	return result;
}


