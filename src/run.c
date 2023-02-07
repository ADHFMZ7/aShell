#include <stdio.h>
#include "term.h"
#include <unistd.h>
#include <string.h>

int count_args(char *line)
{
	
	int num_lines = 0;
	int idx = 0;

	while (line[idx]) {
		if (line[idx] == ' '){
			num_lines++;
		}
	}
	return num_lines;

}

char **parse_line(char* line)
{		

	int num_lines = count_args(line);
	char *token;
	char **args = malloc(sizeof(char) * ;


	for (int i = 0; i < num_lines; i++) {
		args[i] = strtok(line, " ");	
	}

	return args;
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
		printf("Child's pid is %d\n", pid);
		return 0;
	}
	else
	{
		printf("Parent's pid is %d\n", getpid());
		printf("Parent thinks child's pid is %d\n", pid);
	}

	return pid;
}


int run(char *buffer)
{
	printf("%s", buffer);

	char **args = parse_line(buffer);

	
	// we need to run the program with the proper arguments.

	return launch_process(args);
}

