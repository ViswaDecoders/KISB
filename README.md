# KISB
It is shell for Linux Based OS.It supports command line editing, history, Tab-completion, piping, I/O redirection and User Customization. KISB is written in C Language.Commands supported include executable file located in the PATH system environment variable.It also provides commandline arithmetic expression evaluation with basic operations.It has a linkedlist based history implementation.The cd operation is written as well, it supports `~` and `/` symbols to change to approriate directories as well.Either piping or I/O redirection alone is supported to maintain the simplicity of the shell.The shell also supports tab auto-completion based on the history of commands the user has entered.The parsing of the shell is rigid on the white space(delimiter) between symbols in the commands.

# Developers
 - Sairam
 - Viswanth
 - Pranav

# Source code
 - myshell.c --> heart of shell, Contains the `main()`and function declarations of parsing, error handling, command execution, etc.
 - eval.c --> Contains the function declarations of arithmetic expression evaluation using data structures(stacks).
 - myshell_history.c --> Contains the function declarations for implementing command history using linked list and tab-completion of commands.
 - cust.c --> Contains the functions declaration to change the prompt colors.

# Installation 
GCC compiler is required to run the shell and install neccesary header files.
