#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 64
#define DELIM " \t\r\n\a"
char **split_line(char *line)
{
	int bufsize = BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens) {
		fprintf(stderr, "ash: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				fprintf(stderr, "ash: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}

int count_args(char *args)
{
	if (args[0] == '\0' || args[0] == '\n') return 0;
	int count = 0;
	for (int i = 0; args[i] != '\0'; i++)
	{
		if (args[i] == ' ' && args[i+1] != ' ')
		{
			count++;
		}
	}
	return ++count;
}

