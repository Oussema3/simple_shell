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

//plz get added now FFS
//adding comments to check commiting


void remove_end0fLine(char line[])
{
  int i = 0;
  while(line[i] != '\n')
    i++;

	    line[i] = '\0';
}





void read_line(char line[])
{

  char* ret = fgets(line,MAX_CHAR,stdin);
  remove_end0fLine(line);

  if( strcmp(line,"exit")== 0 || ret == NULL)
    exit(0);

}





int process_line(char* args[], char line[])
{

  int i= 0;
  args[i] = strtok(line, " ");

  if(args[i] == NULL)
    {

      printf("NO COMMAND\n");
      return 1;

    }


  while(args[i] != NULL)
    {

      i++;
      args[i]= strtok(NULL," ");

    }

  return 1;

}





int read_parse_line(char* args[], char line[])
{

 int i = 0;
  read_line(line);
  process_line(args,line);
  return 1;

 }
int main ()
{

  char* args[MAX_WORD];
  char line[MAX_CHAR];

  while(read_parse_line(args,line))
    {


      int pid = fork();

      if (pid == 0)
	{

	  execvp(args[0],args);

	}
      else
	{

	  waitpid(pid,0,0);

	}
    }

  return 0;





}
