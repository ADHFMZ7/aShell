#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <util.h>
#include "term.h"
#include "tokenizer.h"


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
			fprintf(stderr, "cd: no such file or directory\n");	
			return 1;
		}
		return 0;
	}
	else if (strcmp("exit", args[0]) == 0)
	{
		//exit_shell();
		exit(EXIT_SUCCESS);
	}
	else {
		return launch_process(args);
	}
}
