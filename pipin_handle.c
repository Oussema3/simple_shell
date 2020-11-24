#include "shell.h"

/**
*pipe_ad_redirection_checking - pipe ad redirection cheking
*@temp: character
*Return: int
*/

int pipe_ad_redirection_checking(char *temp[])
{
int i = 0;

while (temp[i] != NULL)
{
if (strcmp(temp[i], ">") == 0)
{
output_redirection_flag = 1;
output_file = temp[i + 1];
return (i);
}
if (strcmp(temp[i], "<") == 0)
{
input_redirection_flag = 1;
input_file = temp[i + 1];
return (i);
}
if (strcmp(temp[i], "|") == 0)
{
piping_flag = 1;
return (i);
}
i++;
}
return (i);
}

/**
*piping_handle - piping HANDLE
*@args: character
*@piping_args: character
*@pipefd: integer
*Return: void
*/

void piping_handle(char *args[], char *piping_args[], int pipefd[])
{
int pid;

pid = fork();
if (pid == 0)
{
dup2(pipefd[1], 1);
close(pipefd[0]);
execvp(args[0], args);
perror(args[0]);
}
else
{
dup2(pipefd[0], 0);
close(pipefd[1]);
execvp(piping_args[0], piping_args);
perror(piping_args[0]);
}
}
