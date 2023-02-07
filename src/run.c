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
		char *envs[] = {(char*) "PATH=/bin", 0};
		char command[80];
		strcpy(command, "/bin/");
		strcat(command, args[0]);
		if (execve(command, args, envs) == -1) 
		{
			printf("Failed to execute %s\n", args[0]);
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
	char **args = split_line(buffer);

	
	// we need to run the program with the proper arguments.

	return launch_process(args);
}

