# Push Swap

## Description
Push Swap is a project that focuses on sorting a set of integers using two stacks and a limited set of instructions. The goal is to implement a program called `push_swap` in C, which calculates and displays the smallest sequence of instructions necessary to sort the integers in ascending order.

## Features
- **Stack Manipulation:** Two stacks named 'a' and 'b' are used, along with a set of instructions to manipulate them. These instructions include swapping elements, pushing elements between stacks, and rotating elements within a stack.
- **Optimization:** The challenge lies in finding the most efficient sequence of instructions to achieve the sorting with the fewest possible actions.
- **Error Handling:** The program must handle errors such as invalid input arguments (non-integers, duplicates, etc.) and display appropriate error messages.

## Learning Objectives
- **Algorithm Complexity:** This project introduces developers to the concept of algorithm complexity and the importance of selecting efficient sorting algorithms.
- **Data Structures:** Implementing the project requires understanding and utilizing data structures such as double circular lists for stack manipulation.
- **C Programming:** The project encourages proficiency in C programming, including writing clean and efficient code, implementing error handling, and adhering to project requirements.

## Requirements
- The project must include a Makefile for compiling the source files.
- Global variables are not allowed.
- Proper error handling must be implemented, including validation of input arguments.

## Usage
- To use the `push_swap` program, provide a list of integers as arguments.
- The program will then output the smallest sequence of instructions required to sort the integers in ascending order.

## Example
```bash
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa```

