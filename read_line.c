#include "shell.h"

/**
*remove_end0fLine - remove the end of line
*@line: The procced line
*Return: void
*/
void remove_end0fLine(char line[])
{
int i = 0;
while (line[i] != '\n')
i++;
line[i] = '\0';
}

/**
*read_line - reading the line
*@line: char to read the read_line
*Return: void
*/

int read_line(char line[])
{
char *buffer = line;
size_t bufsize = 32;
size_t ret;
ret = getline(&buffer, &bufsize, stdin);
remove_end0fLine(line);
if (strcmp(line, "exit") == 0 || ret == 0)
exit(0);
else
return (ret);
}
