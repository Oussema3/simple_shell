#include "shell.h"

/**
 *process_line - split the command
 *@temp: character
 *@line: line to be procced
 *Return: integer
 */

int process_line(char *temp[], char line[])
{
  int i = 0;

  temp[i] = strtok(line, " ");
  while (temp[i] != NULL)
    {
      i++;
      temp[i] = strtok(NULL, " ");
    }
  return (1);
}
