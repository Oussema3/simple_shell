#include "shell.h"

/**
*check_line - Cheking read_line
*@temp: character
*Return: void
*/

void check_line(char *temp[])
{
int i = 0;
int pipe_cnt = 0;
int output_redirection_cnt = 0;
int input_redirection_cnt = 0;
int total_cnt = 0;

if (temp[i] == NULL)
{
printf("NO COMMAND\n");
return;
}
while (temp[i] != NULL)
{
if (strcmp(temp[i], ">") == 0)
output_redirection_cnt++;

if (strcmp(temp[i], "<") == 0)
input_redirection_cnt++;

if (strcmp(temp[i], "|") == 0)
pipe_cnt++;
i++;
}
total_cnt = input_redirection_cnt + output_redirection_cnt + pipe_cnt;
if (total_cnt > 1)
{
printf("ERR: OUR SHELL DOES NOT HANDLE THAT CASE\n");
temp[0] = NULL;
}
}
