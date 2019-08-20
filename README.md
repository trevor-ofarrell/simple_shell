0x16. C - Simple Shell

## Foundations - Low-level programming & Algorithm ― Linux and Unix system 
programming 

## Learning Objectives

## At the end of this project, you are expected to be able to explain to anyone, without the help of Google:
General

## Foundations - Low-level programming & Algorithm ― Linux and Unix system
programming

## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General

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

## Compilation

Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

## List of allowed functions and system calls to use in the making of this shell

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)
