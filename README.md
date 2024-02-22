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

## Performance Guarantees
- The program guarantees specific maximum numbers of moves for sorting different sizes of lists:
  - Lists of 3 numbers are sorted in maximum 3 moves.
  - Lists of 5 numbers are sorted in maximum 12 moves.
  - Sorting 100 numbers requires a maximum of 700 moves.
  - Lists of 500 numbers are sorted in maximum 5500 moves.

# Checker

## Description
Checker is a program designed to validate a sequence of instructions applied to a list of integers. The program takes a list of integers as an argument and then reads instructions from the shell. It applies these instructions to the given list and validates whether the list is sorted after execution.

## Features
- **Input Validation:** Checker validates the list of numbers and instructions to ensure they meet specified criteria. It checks for integers, duplicates, and valid instructions from the specified set.
- **Sorting Verification:** After executing the instructions, Checker verifies whether the list is sorted and the stack b is empty. If so, it outputs "OK"; otherwise, it outputs "KO".
- **Error Handling:** The program displays appropriate error messages for various error conditions, such as invalid input arguments, non-existent instructions, or incorrectly formatted instructions.

## Learning Objectives
- **Memory Management:** Checker carefully manages memory usage and frees all allocated memory when the program finishes execution.
- **Input Handling:** Implementing input validation and error handling enhances proficiency in handling user input and ensuring program reliability.
- **C Programming:** Checker is implemented in C, focusing on writing clean, efficient, and error-free code, adhering to project requirements and constraints.

## Usage
- Provide a list of integers as an argument to the `checker` program.
- Enter instructions on the standard input, each followed by a newline.
- Upon completion, the program outputs "OK" if the list is sorted, or "KO" otherwise.

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
pa

$> ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK

$> ./checker 3 2 1 0
sa
rra
pb
KO
$> ./checker 3 2 one 0
Error

$> ./checker "" 1
Error




