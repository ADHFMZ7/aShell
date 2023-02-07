#include <stdio.h>
#include <stdlib.h>
#include "term.h"
#include <unistd.h>
#include <string.h>
#include <util.h>

int launch_process(char **args)
{

	pid_t pid = fork();

	if (pid == -1)
	{
		printf("Failed to fork\n");
		return -1;
	}
	else if (pid == 0)
	{
		pid = getpid();
		fflush(stdout);
		if (execv(args[0], args) == -1) 
		{
			return -1;
		}
		return 0;
	}
	else
	{
		wait(NULL);
	}
	return pid;
}


int run(char *buffer)
{
	char **args = lsh_split_line(buffer);

	
	// we need to run the program with the proper arguments.

	return launch_process(args);
}

