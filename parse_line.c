#include "shell.h"

/**
*read_parse_line - read the line
*@args: character
*@line: character
*@piping_args: char
*Return: integer
*/

int read_parse_line(char *args[], char *line[], char *piping_args[])
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
