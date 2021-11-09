# Stacks, Queues - LIFO, FIFO

The goal of this project is to create an interpreter for Monty ByteCodes files. Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

### Objectives:

This project reviewed the concepts of LIFO and FIFO methods, stacks, queues, linked lists, and global variables in C programming.

#### Monty byte code files examples:

Files containing Monty byte codes usually have the `.m` extension.

```bash
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```bash
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```

#### The Monty Program:

Usage: `$ monty file`. Where file is the path to the file containing Monty byte code.

| Opcode       | What it does:                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| `push <int>` | Pushes an element to the stack.                                                                                                                 |
| `pall`       | Prints all the values on the stack, starting from top of the stack.                                                                             |
| `pint`       | Prints the value at the top of the stack, followed by a new line                                                                                |
| `pop`        | Removes the top element of the stack.                                                                                                           |
| `nop`        | Does nothing.                                                                                                                                   |
| `swap`       | Swaps the top two elements of the stack.                                                                                                        |
| `add`        | Adds the top two elements of the stack.                                                                                                         |
| `sub`        | Subtracts the top element of the stack from the second top element of the stack.                                                                |
| `mul`        | Multiplies the second top element of the stack with the top of stack.                                                                           |
| `div`        | Divides the second top element of the stack by the top of stack.                                                                                |
| `mod`        | Computes the rest of the division of the second top element of the stack by the top element of the stack.                                       |
| `pchar`      | Prints the char at the top of the stack, followed by a new line.                                                                                |
| `pstr`       | Prints the string starting at the TOS, followed by a new line.                                                                                  |
| `rotr`       | Rotates the stack to the bottom. The last element of the stack becomes the top element of the stack.                                            |
| `rotl`       | Rotates the stack to the top. The top element of the stack becomes the last one, and the second top element of the stack becomes the first one. |
| `stack`      | Sets the format of the data to a stack (LIFO). This is the default behavior of the program.                                                     |
| `queue`      | Sets the format of the data to a queue (FIFO).                                                                                                  |

### Resources:

- [How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)
- [Data Structures: Stacks & Queues](https://medium.com/@hitherejoe/data-structures-stacks-queues-a3b3591c8cb0)
- [CS50 2019 - Lecture 5 - Data Structures](https://www.youtube.com/watch?v=4IrUAqYKjIA)
- [Doubly Circular Linked List | Set 1 (Introduction and Insertion)](https://www.geeksforgeeks.org/doubly-circular-linked-list-set-1-introduction-and-insertion/)
- [C library function - atexit()](https://www.tutorialspoint.com/c_standard_library/c_function_atexit.htm)

### Compilation:

Code files must be compiled this way:

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

- Any output must be printed on `stdout`
- Any error message must be printed on `stderr`

### Author:

- Tatiana Orejuela Zapata | [Github](https://github.com/tatsOre)

##### Foundations - Low-level programming & Algorithm Data structures and Algorithms

##### May, 2020. Cali, Colombia.
