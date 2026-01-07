# **C - Simple Shell**

## **Description**
This project is a simple simulation of a UNIX command line interpreter (a tiny shell). It was made in the software development program of [Holberton](https://www.holbertonschool.com/).

### **description of a shell**
A shell is a program that displays a prompt, reads user input, and runs commands by creating a child process (`fork`) and replacing it with a new program (`execve`). The parent process waits for the command to finish, then shows the prompt again.

This version supports **simple command lines**:
- one command only (one word)
- **no arguments**
- **no PATH search** (you must type the full executable path like `/bin/ls`)
- no pipes, redirections, separators, or built-ins

---

## **compilation**
we will compile the code using this command

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

---

## **Requirements**

### **Requirements for the project**

**1. Text Editor:** you are allowed to use vi, vim, nano and emacs to modify the code

**2. Operating System:** this project has to be done on Ubuntu 20.04

**3. Coding Style:** you must use the betty style coding and documentation

**4. authorized functions and macros :**
- write (man 2 write)
- getline (man 3 getline)
- malloc (man 3 malloc)
- free (man 3 free)
- fork (man 2 fork)
- execve (man 2 execve)
- wait / waitpid (man 2 wait)
- stat (man 2 stat)
- access (man 2 access) *(optional, depending on your implementation)*
- perror (man 3 perror)
- exit / _exit (man 3 exit)

**5. File Endings:** Ensure that all source code files (.c files) end with a newline character (\n).

**6. Header Inclusion:** Include the "simple_shell.h" header file in all .c files to access necessary declarations and definitions.


## **Flowchart**


## **Example Usage**

**Run the shell:**
```bash
./simple_shell
```

**Example session (no PATH, so use full paths):**
```bash
$ /bin/ls
AUTHORS  main.c  simple_shell.h
$ /bin/pwd
/home/tom/projects/simple_shell
$ /bin/echo
Command not found
$ ^D
```

---

## **BUGS**
- This shell only supports **one-word commands** (no arguments).
- This shell does **not** search in `PATH` (you must provide the full executable path).
- No built-ins (`cd`, `exit`, `env`, etc.).
- No pipes, redirections, semicolons, or special characters handling.

---

## **Authors**
- Thomas CHARIER LERAY  
- Arthur MOULARD
