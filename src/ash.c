// This file implements the shell

#include <stdio.h>
#include <stdlib.h>
#include "run.h"
#include "repl.h"

#define VERSION_NUMBER "0.01"
#define BUFSIZE 1024

int main(int argc, char **argv)
{

	printf("Ahmad's Terminal Emulator version %s\n", VERSION_NUMBER);

	if (argc == 1)
	{

		// configure the REPL 


		return repl(BUFSIZE);
	}
	else if (argc == 2)
	{
		// implement running scripts
		printf("Running file %s\n", argv[1]);
		//return interpret(argv[1]);
	}
	else 
	{
		printf("Incorrect usage. Try again.\n");
		return -1;
	}
}
