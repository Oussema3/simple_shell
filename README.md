The Simple Shell
    "The end of trimester project"

Welcome to the gates of Shell

Learning Objectives:

    Who designed and implemented the original Unix operating system
    Who wrote the first version of the UNIX shell
    Who invented the B programming language (the direct predecessor to the C programming language)
    Who is Ken Thompson
    How does a shell work
    What is a pid and a ppid
    How to manipulate the environment of the current process
    What is the difference between a function and a system call
    How to create processes
    What are the three prototypes of main
    How does the shell use the PATH to find the programs
    How to execute another program with the execve system call
    How to suspend the execution of a process until one of its children terminates
    What is EOF / “end-of-file”?

Compilation and Testing

1) Clone repo to your local directory
    https://github.com/Oussema3/simple_shell.git

2) Start up simple_shell, compile using
    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

3) Start the shell
   ./hsh

4) Example Output
    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

Authors
    Mohamed Chedly
    Oussama Ajmi
    
    ![687474703a2f2f7777772e686f6c626572746f6e7363686f6f6c2e636f6d2f686f6c626572746f6e2d6c6f676f2e706e67](https://user-images.githubusercontent.com/70922643/99154368-8d7f6200-26af-11eb-89ca-a808a392b733.png)

