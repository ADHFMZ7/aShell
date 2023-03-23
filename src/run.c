#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <util.h>
#include "term.h"
#include "tokenizer.h"
#include <fcntl.h>

int launch_process(Process *process, int in_fd, int out_fd, int *prev_pipefd) {
    int *pipefd = NULL;
    if (process->pipe) {
        pipefd = (int *) malloc(sizeof(int) * 2);
        if (pipe(pipefd) == -1) {
            perror("Pipe");
            exit(EXIT_FAILURE);
        }
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Child process

        // // Set up input redirection
        // if (in_fd != STDIN_FILENO) {
        //     if (dup2(in_fd, STDIN_FILENO) == -1) {
        //         perror("dup2");
        //         exit(EXIT_FAILURE);
        //     }
        //     close(in_fd);
        // }
        //
        // // Set up output redirection
        // if (out_fd != STDOUT_FILENO) {
        //     if (dup2(out_fd, STDOUT_FILENO) == -1) {
        //         perror("dup2");
        //         exit(EXIT_FAILURE);
        //     }
        //     close(out_fd);
        // }
        //
        // // Set up piping
        // if (prev_pipefd) {
        //     close(prev_pipefd[1]); // Close the write end of the previous pipe
        //     if (dup2(prev_pipefd[0], STDIN_FILENO) == -1) {
        //         perror("dup2");
        //         exit(EXIT_FAILURE);
        //     }
        //     close(prev_pipefd[0]);
        // }
        //
        // if (process->pipe) {
        //     if (dup2(pipefd[0], STDIN_FILENO) == -1) {
        //         perror("dup2");
        //         exit(EXIT_FAILURE);
        //     }
        //     close(pipefd[0]);
        // }

        if (process->input_file) {
            int fd = open(process->input_file, O_RDONLY); 
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            if (dup2(fd, STDOUT_FILENO) == -1) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(fd);
        }
        if (process->output_file) {
            int fd = open(process->output_file, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            if (dup2(fd, STDOUT_FILENO) == -1) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(fd);
        }

        if (execvp(process->program_name, process->argv) == -1) {
            fprintf(stderr, "ash: Failed to execute %s\n", process->program_name);
            exit(EXIT_FAILURE);
        }

        exit(pid);
    }
    else {
        // Parent process

        // if (prev_pipefd) {
        //     close(prev_pipefd[0]); // Close the read end of the previous pipe
        //     close(prev_pipefd[1]); // Close the write end of the previous pipe
        // }
        //
        // if (process->pipe) {
        //     launch_process(process->pipe, pipefd[0], out_fd, pipefd);
        //     close(pipefd[0]);
        //     close(pipefd[1]);
        // }
        //else {
            int status;
            waitpid(pid, &status, 0);
        //}
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
		printf("Exiting Ahmad shell\n");
        
		exit(EXIT_SUCCESS);
	}
	else {
		return launch_process(head, STDIN_FILENO, STDOUT_FILENO, NULL);
	}
}
