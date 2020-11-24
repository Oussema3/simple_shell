#include "shell.h"

/**
*check_line - check the line
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

/**
*read_parse_line - read the parse read_line
*@args: character
*@line: character
*@piping_args: character
*Return: integer
*/
int read_parse_line(char *args[], char line[], char *piping_args[])
{
char *temp[MAX_WORD];
int i = 0;
int pos;
read_line(line);
process_line(temp, line);

check_line(temp);

pos = pipe_ad_redirection_checking(temp);
while (i < pos)
{
args[i] = temp[i];
i++;
}
args[i] = NULL;
i++;
if (piping_flag == 1)
{
int j = 0;
while (temp[i] != NULL)
{
piping_args[j] = temp[i];
i++;
j++;
}
}
return (1);
}
