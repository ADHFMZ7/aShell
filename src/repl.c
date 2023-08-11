#include "repl.h"
#include <stdlib.h>
#include <stdio.h>
#include "run.h"
#include "config.h"
#include <readline/readline.h>
#include <readline/history.h>

static char *buffer = (char *)NULL;

int repl()
{

    // This is where I will parse configs and apply them
    // config();

    // start the execution loop

    for(;;)
    {
	if (buffer)
	{
	    free (buffer);
	    buffer = (char *)NULL;
	}
	buffer = readline("\033[0;31m>>> \033[0m");

	if (buffer && *buffer)
	    add_history (buffer);
	run(buffer);
    }
	// terminate the program
	printf("Exiting Ahmad's Shell\n");
	free(buffer);
	return 0;
}

