#include "repl.h"
#include <stdlib.h>
#include <stdio.h>
#include "run.h"

#define PROMPT ">>> "


int repl(size_t bufsize)
{

	// This is where I will parse configs and apply them


	char *buffer = malloc(sizeof(char) * bufsize);

	// start the execution loop


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
	printf("Exiting Ahmad's Shell\n");

	return 0;
}
