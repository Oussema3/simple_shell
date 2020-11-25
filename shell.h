#ifndef SHELL_H
#define SHELL_H



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

int input_redirection_flag ;
int output_redirection_flag ;
int piping_flag;


void remove_end0fLine(char line[]);
int read_line(char line[]);
int process_line(char *temp[], char line[]);
int pipe_ad_redirection_checking(char *temp[]);
void check_line(char *temp[]);
int read_parse_line(char *args[], char line[], char *piping_args[]);

#endif
