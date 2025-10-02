# PUSH_SWAP

![ORGANIZING](https://media.giphy.com/media/rzufqXSfH7BVbtudEe/giphy.gif?cid=ecf05e47qmi7als8ut7279eg2jhvnjzduyuladdonpdw4h8w&ep=v1_gifs_search&rid=giphy.gif&ct=g)

## Overview

The **Push Swap** project is an algorithmic challenge that involves sorting a set of integers using two stacks and a specific set of instructions. The goal is to develop a C program called `push_swap` that calculates and displays the shortest sequence of instructions, in the Push Swap language, to sort the integers received as arguments.

## Objectives

- Write an efficient sorting algorithm
- Learn about algorithm complexity
- Practice C programming according to established norms
- Understand and implement stack operations

### Common Requirements

- The project must be written in C and follow the norms
- It must avoid unexpected failures (e.g., segmentation fault, bus error)
- All allocated memory must be properly freed
- A Makefile must be included that compiles the source files into the `push_swap` executable

## Project Structure

### Stacks

- You will have two stacks: `a` and `b`.
- Stack `a` must contain a random amount of integers (negative and/or positive) without duplicates
- Stack `b` must start emptyy.

### Instructions

You can use the following instructions to manipulate the stacks:

- **sa**: Swap the first two elements of stack `a`.
- **sb**: Swap the first two elements of stack `b`.
- **ss**: Execute `sa` and `sb` simultaneously.
- **pa**: Move the first element from stack `b` to the top of stack `a`.
- **pb**: Move the first element from stack `a` to the top of stack `b`.
- **ra**: Rotate stack `a` upward.
- **rb**: Rotate stack `b` upward.
- **rr**: Execute `ra` and `rb` simultaneously.
- **rra**: Rotate stack `a` downward.
- **rrb**: Rotate stack `b` downward.
- **rrr**: Execute `rra` and `rrb` simultaneously.

### Usage Example

To use the program, you must pass a list of integers as arguments. For example:

```bash
./push_swap 2 1 3 6 5 8
```

The program will display the sequence of instructions needed to sort the numbers.

## Compilation

The project includes a Makefile that allows easy compilation of the program. To compile, run the following command:

```
make
```

To clean up the generated object files, use:

```
make clean
```

To remove the executable and object files, use:

```
make fclean
```

To recompile, run:

```
make re
```

## Visualizer

To facilitate visualization of your program's operation, a demonstration video is available. This video shows how the algorithm sorts numbers in real time using the stack structure.

![](./push_swap_100.gif)

## Benchmark

For project validation, you must be able to sort 100 random numbers in less than 700 operations. For maximum validation, you must be able to sort 500 numbers in less than 5500 operations.

## Final Considerations

This project is an excellent opportunity to enhance your skills in algorithms and C programming, as well as being a good starting point for understanding complexity concepts that can be useful in job interviews.

