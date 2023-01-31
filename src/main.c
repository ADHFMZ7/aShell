#include <stdio.h>
#include <stdlib.h>
#include "term.h"

#define VERSION_NUMBER "0.01"
#define BUFSIZE 128
#define PROMPT ">>> "

int main()
{

	printf("Ahmad's Terminal Emulator version %s\n", VERSION_NUMBER);

	// Initialize the terminal
	

	// start the execution loop

	char* buffer = malloc(sizeof(char) * BUFSIZE);
	size_t bufsize = BUFSIZE;

	while (1)
	{
		printf("%s", PROMPT);

		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			printf("\n");
			break;
		}


		run(buffer);

	}

	// terminate the program
	printf("Exiting Ahmad's Terminal Emulator\n");

	return 0;
}
