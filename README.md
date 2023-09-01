<div align="center">

<h1> C - Stacks, Queues - LIFO, FIFO </h1>

> This repository contains the C "Stacks, Queues - LIFO, FIFO" project for Holberton School Uruguay.

</div>

<div align="center">

![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png) ════════════════════ ![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png) ════════════════════ ![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png)

</div>

<br>

## Table of contents
* [Introduction](#introduction)
* [Tasks](#tasks)
* [Requirements](#requirements)
* [Files](#files)
* [Usage](#usage)
* [Authors](#authors)

## Introduction
The project its about construct our own monty interpreter to learn a get deeper into C lenguage. This objective is given us by Holberton School as a pair programming project.

<details>
<summary><h2>Tasks</h2></summary>

0. push, pall
Implement the push and pall opcodes.

The push opcode

The opcode push pushes an element to the stack.

Usage: push <int>
where <int> is an integer
if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number in the file
You won’t have to deal with overflows. Use the atoi function
The pall opcode

The opcode pall prints all the values on the stack, starting from the top of the stack.

Usage pall
Format: see example
If the stack is empty, don’t print anything
```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
```

1. pint
mandatory
Implement the pint opcode.

The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.

Usage: pint
If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE
```
julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
```

2. pop
mandatory
Implement the pop opcode.

The pop opcode

The opcode pop removes the top element of the stack.

Usage: pop
If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

```
julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
```

3. swap
mandatory
Implement the swap opcode.

The swap opcode

The opcode swap swaps the top two elements of the stack.

Usage: swap
If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

```
julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
```

4.add
Implement the add opcode.

The add opcode

The opcode add adds the top two elements of the stack.

Usage: add
If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter

```
julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
```

5. nop
mandatory
Implement the nop opcode.

The nop opcode

The opcode nop doesn’t do anything.
</details>

<details>
<summary><h2>Resources</h2></summary>>

* <a href="www.google.com/search" target="blank">Google</a>
* <a href="https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files" target="blank">How do I use extern to share variables between source files?</a>
</details>

<details><summary><h2>Requirements</h2></summary>
<h3>General Requirements</h3>
        
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You allowed to use a maximum of one global variable
No more than 5 functions per file
You are allowed to use the C standard library
The prototypes of all your functions should be included in your header file called monty.h
Don’t forget to push your header file
All your header files should be include guarded
You are expected to do the tasks in the order shown in the project
<h3></h3>


<h3>Compilation</h3>
* gcc -Wall -Werror -Wextra -pedantic *.c -o monty
</details>

<details>
<summary><h2>Files</h2></summary>
        
## Files
|Files|
|---|
|[monty.c](#monty.c)|
|[monty.h](#monty.h)|
|[operations.c](#operations.c)|
|[more_operations.c](#more_operations.c)|
|[utilities.c](#utilities.c)|
|[checks.c](#checks.c)|

<a name="monty.c"></a>
<h3><a href="https://github.com/FacundoV21/holbertonschool-monty/blob/main/monty.c">monty.c</a></h3>
Main code of the Stacks, Queues - LIFO, FIFO project.
<a name="monty.h"></a>
<h3><a href="https://github.com/FacundoV21/holbertonschool-monty/blob/main/monty.h">monty.h</a></h3>
Contains the libraries, prototypes and headers macros needed for the files.
<a name="operations.c"></a>
<h3><a href="https://github.com/FacundoV21/holbertonschool-monty/blob/main/operations.c">operations.c</a></h3>
Contains functions that imitates operations of the monty interpreter (push, pall, not found, pint and pop).
<a name="more_operations.c"></a>
<h3><a href="https://github.com/FacundoV21/holbertonschool-monty/blob/main/more_operations.c">more_operations.c</a></h3>
Contains more functions that imitates operations of the monty interpreter (swap, add and nop).
<a name="utilities.c"></a>
<h3><a href="https://github.com/FacundoV21/holbertonschool-monty/blob/main/utilities.c">utilities.c</a></h3>
Contains functions for memory issues and makes work the commands passed to interpreter (free_stack, free_arr, separate and get_code).
<a name="checks.c"></a>
<h3><a href="https://github.com/FacundoV21/holbertonschool-monty/blob/main/checks.c">checks.c</a></h3>
Contains functions that checks specific cases to avoid a failure, (specifically check_args, check_open, check_tokens and check_arr). 
</details>

<details>
<summary><h2>Usage</h2></summary>

Installation

- Clone this repository in your terminal: `git clone "https://github.com/FacundoV21/holbertonschool-monty"`
- Go into the repository: `cd holbertonschool-monty`
- Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

<h3>Example</h3>
For this example, you need to create a file named "test.m", here you whill write:

```
push 1
push 2
push 3
pall
```
So, in the terminal:
Input:
```
cat test.m
```
Output:
```
push 1
push 2
push 3
pall
```
Another example:

Input:
```
./monty test.m
```
Output:
```
3
2
1
```
</details>

<div align="center">

## Authors
  
&ensp;[<img src="https://img.shields.io/badge/Nitsu47-%23121011.svg?style=for-the-badge&logo=github&logoColor=white">](https://github.com/Nitsu47)
&ensp;[<img src="https://img.shields.io/badge/FacundoV21-%23121011.svg?style=for-the-badge&logo=github&logoColor=white">](https://github.com/FacundoV21)
<br>

![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png) ════════════════════ ![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png) ════════════════════ ![sea-horse](https://user-images.githubusercontent.com/110431271/229328604-b8c19c26-54e9-48d6-946f-91b0337deece.png)

<br>

Last updated: August 31, 2023
