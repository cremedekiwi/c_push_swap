# push_swap

## Introduction
**Push_swap** is a program designed to sort a stack of integers using a limited set of predefined operations. This project emphasizes efficiency and optimization, leveraging the **Radix Sort Algorithm** to handle stacks of varying sizes.

## Goals
1. Implement and optimize a sorting algorithm for a stack using the **Radix Algorithm**.
2. Use only specific operations:
   - `sa`, `sb`, `ss` (swap)
   - `pa`, `pb` (push)
   - `ra`, `rb`, `rr` (rotate)
   - `rra`, `rrb`, `rrr` (reverse rotate)
3. Minimize the total number of operations.
4. Ensure robust performance for stacks containing 2 to 500 elements.

## How It Works
Push_swap operates on two stacks, **A** and **B**, using predefined operations to sort the integers in ascending order. Stack A begins unsorted, and the final result must have all integers in ascending order in Stack A, with Stack B empty.
This implementation uses the **Radix Algorithm**, which is particularly efficient for sorting integers based on their binary representation.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/push_swap.git push_swap
   ```
2. Navigate to the project directory:
   ```bash
   cd push_swap
   ```
3. Compile the program:
   ```bash
   make
   ```

## Usage
Run the program with a list of integers as arguments:

```bash
./push_swap 3 2 5 1 4
```

The program outputs the operations needed to sort the numbers:

```
pb
ra
pb
sa
pa
pa
```

To verify correctness, use a checker program. Example:

```bash
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker_OS $ARG
```

## Radix Algorithm Explanation
The **Radix Algorithm** sorts integers by processing their binary representation bit by bit. This method works efficiently for larger stacks, typically up to 500 elements.

### Steps:
1. **Normalize Values**:
   - Convert the input numbers into a range from 0 to `n-1` based on their relative size (e.g., smallest becomes 0, second smallest becomes 1, etc.).
   - This avoids large integer gaps and simplifies bit-level processing.

2. **Bitwise Processing**:
   - Starting with the least significant bit (LSB), partition the numbers into Stack A and Stack B based on whether the bit is 0 or 1.
   - Repeat this process for all bits of the largest number in binary.

3. **Rebuild Stack A**:
   - Push all elements back to Stack A in sorted order by completing all bit-level passes.

### Example:
Sorting `3 2 5 1 4`:
- Binary representations:  
  ```
  3 -> 011
  2 -> 010
  5 -> 101
  1 -> 001
  4 -> 100
  ```
- Iterate through each bit position, pushing and rotating to organize the stack.
- Final result is achieved after processing all bits.

## Performance

The **Radix Algorithm** provides consistent performance across varying input sizes:

- **For 5 elements**: Typically ~12-15 operations.
- **For 100 elements**: ~700-900 operations.
- **For 500 elements**: ~5500-7000 operations.

## Testing
Test the program with random integers:

```bash
ARG=$(shuf -i 1-500 -n 100); ./push_swap $ARG | ./checker $ARG
```
