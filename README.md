# Push Swap

A sorting algorithm that implements efficient stack-based sorting using a limited set of operations.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Compilation](#compilation)
- [Usage](#usage)
- [Operations](#operations)
- [Algorithm](#algorithm)
- [Project Structure](#project-structure)
- [Examples](#examples)
- [Performance](#performance)

## Description

Push_swap is a project that challenges you to sort a stack of integers using the most efficient combination of predefined operations. The goal is to sort stack A in ascending order using the minimum number of moves.

The program takes a list of integers as arguments and outputs the sequence of operations needed to sort them.

## Features

- **Efficient Sorting**: Multiple algorithms optimized for different input sizes
- **Error Handling**: Comprehensive validation for invalid inputs
- **Memory Management**: Proper allocation and deallocation of resources
- **Optimized Operations**: Smart rotation decisions to minimize move count

## Compilation

```bash
make
```

This will compile the program and create the `push_swap` executable.

### Available Make Targets
- `make` or `make all` - Compile the program
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Recompile everything

## Usage

```bash
./push_swap [list of integers]
```

### Examples
```bash
# Sort three numbers
./push_swap 3 1 2
# Output: sa

# Sort with quoted arguments
./push_swap "3 1 2 4"
# Output: sa

# Sort larger sets
./push_swap 5 2 8 1 9 3 7 4 6
```

### Input Validation
The program will output "Error" and exit if:
- Non-integer arguments are provided
- Duplicate numbers are found
- Numbers exceed INT_MAX
- No arguments are provided

## Operations

The program uses the following operations to sort the stacks:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack A |
| `sb` | Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the first element of stack B to stack A |
| `pb` | Push the first element of stack A to stack B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## Algorithm

The program implements different sorting strategies based on input size:

### Small Sets (≤ 3 elements)
- **2 elements**: Simple comparison and swap if needed
- **3 elements**: Hardcoded optimal solutions for all 6 permutations

### Medium Sets (4-40 elements)
- Uses a hybrid approach that pushes the largest elements to stack B
- Sorts the remaining 3 elements in stack A
- Pushes elements back from B to A in sorted order

### Large Sets (≥ 42 elements)
- **Radix Sort**: Efficient bit-based sorting algorithm
- Sorts numbers by examining each bit position
- Optimal for large datasets with O(n×k) complexity where k is the number of bits

## Project Structure

```
push_swap/
├── Makefile
├── includes/
│   └── push_swap.h           # Header file with function prototypes
├── libft/                    # Custom C library
│   ├── Makefile
│   ├── includes/
│   │   ├── libft.h
│   │   └── ft_printf.h
│   └── srcs/                 # Library source files
└── srcs/
    ├── push_swap.c           # Main program
    ├── init.c                # Stack initialization and parsing
    ├── errors.c              # Error handling functions
    ├── free.c                # Memory management
    ├── operation.c           # Basic stack operations
    ├── push.c                # Push operations (pa, pb)
    ├── swap.c                # Swap operations (sa, sb, ss)
    ├── rotate.c              # Rotate operations (ra, rb)
    ├── rrotate.c             # Reverse rotate operations (rra, rrb, rrr)
    ├── sort.c                # Sorting algorithms for small/medium sets
    ├── radix.c               # Radix sort implementation
    └── utils.c               # Utility functions
```

## Examples

### Sorting 3 numbers
```bash
$ ./push_swap 2 1 3
sa
```

### Sorting 5 numbers
```bash
$ ./push_swap 5 4 3 2 1
pb
pb
ra
pa
pa
```

### Error cases
```bash
$ ./push_swap 1 2 2
Error

$ ./push_swap 1 abc 3
Error

$ ./push_swap
# No output (no arguments)
```

## Performance

The algorithm performance varies by input size:

- **2-3 elements**: 0-2 operations (optimal)
- **4-40 elements**: Typically under 12 operations for 5 elements
- **42+ elements**: Radix sort provides consistent O(n×log n) performance

### Optimization Features
- **Smart Rotation**: Chooses shortest path (rotate vs reverse rotate)
- **Bit Manipulation**: Efficient radix sort implementation
- **Memory Efficient**: Doubly-linked list implementation
- **Input Validation**: Early error detection prevents unnecessary processing

## Technical Details

### Data Structures
- **Doubly-linked lists** for both stacks A and B
- **Head and tail pointers** for O(1) operations at both ends
- **Custom stack structure** containing pointers to both stacks

### Memory Management
- All allocated memory is properly freed
- Error conditions trigger cleanup before exit
- No memory leaks in normal or error conditions

### Error Handling
- Comprehensive input validation
- Duplicate detection
- Integer overflow protection
- Graceful error reporting
