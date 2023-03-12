#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <util.h>
#include "term.h"
#include "tokenizer.h"


int launch_process(Process *process)
{

	pid_t pid = fork();

	if (pid == -1)
	{
		fprintf(stderr, "Failed to fork\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		pid = getpid();
		fflush(stdout);
		char *envs[] = {(char*) "PATH=/bin:/usr/bin", 0};

		if (execvp(process->program_name, process->argv) == -1) 
		{
			printf("Failed to execute %s\n", process->program_name);
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

	char **args = split_line(buffer);

	Process *head = scan_tokens(args);	

	if (strcmp("cd", head->program_name) == 0) 
	{
		if (chdir(head->argv[1]) == -1)
		{
			fprintf(stderr, "cd: no such file or directory\n");	
			return 1;
		}
		return 0;
	}
	else if (strcmp("exit", head->program_name) == 0)
	{
		//exit_shell();
		exit(EXIT_SUCCESS);
	}
	else {
		return launch_process(head);
	}
}
