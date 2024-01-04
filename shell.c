#include "shell.h"
/*
 * main - UNIX command line interpreter
 * @argc: counter
 * @argv: vector
 *
 * Return: On success, 0, otherwise, error message
 */
int main(int argc, char **argv)
{
	(void)argc,(void)argv;
	char *td_buf = NULL, *td_token;
	size_t td_counter = 0, ssize_t td_reader;
	pid_t _tdchild_id;
	int d, td_status;
	char **tdarray;

	while(1)
	{
		write(STDOUT_FILENO, "tdShell$", 9);
		td_reader getline(&td_buf, &td_counter, stdin);

		if(td_reader == -1)
		{
			perror("Leaving shell ...");
			exit() /*we'll deal with error handling*/
		}
		
		td_token = strtok(td_buf, "\n");
		tdarray = malloc(sizeof(char *) * 1024);
		d = 0;
		
		while(td_token)
		{
			tdarray[d] = td_token;
			td_token strtok(NULL, "\n");
			d++;
		}
		tdarray[d] = NULL;

		_tdchild_id = fork();
		if(_tdchild_id == -1)
		{
			perror("Creation failure");
			exit()
		}
		if(_tdchild_id == 0)
		{
			if(execve(tdarray[0], tdarray, NULL) == -1)
			{
				perror("Execution failure");
				exit();
			}
		}
		else
		{
			wait(&td_status);
		}
	}
	free(td_buf);
	return(0);
}
