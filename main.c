#include "shell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_WORD 10
#define MAX_CHAR 100

int input_redirection_flag;
int output_redirection_flag;
int piping_flag;

char *input_file = NULL;
char *output_file = NULL;

/**
*pipe_ad_redirection_checking - pipe ad redirection checking
*@temp: character
*Return: integer
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
*piping_handle - piping handle
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
/**
*main - main function
*Return: void
*/
int main(void)
{
char *args[MAX_WORD];
char *piping_args[MAX_WORD];
char line[MAX_CHAR];
int pipefd[2];
pipe(pipefd);
while (read_parse_line(args, line, piping_args))
{
int pid = fork();
if (pid == 0)
{
if (input_redirection_flag == 1 && input_file != NULL)
dup2(open(input_file, O_RDWR | O_CREAT, 0777), 0);
if (output_redirection_flag == 1 && output_file != NULL)
dup2(open(output_file, O_RDWR | O_CREAT, 0777), 1);
if (piping_flag == 1)
{
piping_handle(args, piping_args, pipefd);
}
execvp(args[0], args);
}
else
{
waitpid(pid, 0, 0);
input_redirection_flag = 0;
output_redirection_flag = 0;
piping_flag = 0;
}
}
return (0);
}
