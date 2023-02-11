#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <util.h>
#include "term.h"


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
		char *envs[] = {(char*) "PATH=/bin:/usr/bin", 0};

		if (execvp(args[0], args) == -1) 
		{
			printf("Failed to execute %s\n", args[0]);
		}
			exit(pid);
	}
	else
	{
		wait(NULL);
	}
	return 0;
}


int run(char *buffer)
{
	int argc = count_args(buffer);
	if (!argc) return 0;

	char **args = split_line(buffer);

	if (strcmp("cd", args[0]) == 0) 
	{
		if (chdir(args[1]) == -1)
		{
			printf("cd: no such file or directory\n");	
			return -1;
		}
		return 0;
	}
	return launch_process(args);
}


