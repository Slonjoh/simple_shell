# Simple Shell

The Simple Shell implementation of a Unix shell an alx project, providing a command line interface for users to interact with their operating system.

## Description

The Simple Shell provides a straightforward interface for running commands and scripting
Simple Shell is a user-friendly command-line interface for Unix-like operating systems.
It provides a simplified and intuitive way to interact with your computer, allowing you to perform common tasks and run commands with ease.

## Installation and Usage

1. Clone this repository to your local machine using Git:

   shell
   git clone https://github.com/Slonjoh/simple_shell.git



2. Your shell will be compiled this way:
00
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Using Simple Shell is straightforward. Just open a terminal and start typing commands.

Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

Also in non-interactive like this

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$

$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

## Files
