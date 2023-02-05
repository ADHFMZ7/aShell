#include <stdio.h>
#include "term.h"
#include <unistd.h>

char **parse_line(char* line)
{		


	
}


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

		return 0;
	}
	else
	{
		printf("child's pid is %d\n", pid);
		printf("Parent's pid is potentially %d\n", getpid());
	}

	return (int) pid;
}


int run(char *buffer)
{
	printf("%s", buffer);

	char **args = parse_line(buffer);

	
	// we need to run the program with the proper arguments.

	return launch_process(args);
}

