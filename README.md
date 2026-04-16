<!-- omit in toc -->  
# holbertonschool-simple_shell

<p align="center">
<img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language">
  <img src="https://img.shields.io/badge/Tested%20on-Ubuntu%2022.04%20-orange?style=for-the-badge" alt="Tested for">
</p>

## Contents

- [Contents](#contents)
- [Requirements](#requirements)
- [Resources](#resources)
- [Compilation](#compilation)
- [Usage](#usage)
- [Usage Example](#usage-example)
- [Authors](#authors)


## Requirements
```
Allowed editors: vi, vim, emacs

All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

All your files should end with a new line

A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

Your shell should not have any memory leaks

No more than 5 functions per file

All your header files should be include guarded

Use system calls only when you need to (why?)
```

## Resources

[Unix shell](https://en.wikipedia.org/wiki/Unix_shell)

[Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)

[Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)

Everything you need to know to start coding your own shell concept page (Holberton Intranet)

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage
- Clone the repository and enter it
  ```bash
  git clone https://github.com/Thomas-lab17/holbertonschool-simple_shell && cd holbertonschool-simple_shell
  ```
 - Compile it with [Compilation](#compilation)
 - run the executable
  ```bash
.hsh
  ```

## Usage Example

```bash
$ ./hsh
$ ls
lorem ipsum lorem ipsum place/type files here
$ pwd
/home/user/holbertonschool-simple_shell
$ echo Hello World
Hello World
$ env
USER=user
HOME=/home/user
PATH=/usr/local/bin:/usr/bin:/bin
...
$ exit
```


## Authors
View the AUTHORS file in the repository
```
Madi Madi Anli

Thomas Charierleray

Alexander Durant
```