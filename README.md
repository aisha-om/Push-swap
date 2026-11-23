*This project has been created as part of the 42 curriculum by <aabufarw>,<reab>.*

# push_swap

## Description

**push_swap** is a collaborative algorithmic project in C from the 42 curriculum. The goal is to sort a stack of unique integers (`stack_a`) in ascending order using an auxiliary stack (`stack_b`) and a restricted set of stack manipulation instructions, while minimizing the total number of operations.

Because different input sizes and levels of disorder benefit from different sorting approaches, this implementation combines three distinct strategies—**Insertion Sort**, **Chunk Sort**, and **Radix Sort**—alongside an adaptive mode that selects the most suitable algorithm based on the input's initial disorder ratio.

### Allowed Operations

| Instruction | Description |
| :--- | :--- |
| `sa` | Swap the first 2 elements at the top of `stack_a`. |
| `sb` | Swap the first 2 elements at the top of `stack_b`. |
| `ss` | `sa` and `sb` at the same time. |
| `pa` | Take the first element at the top of `stack_b` and put it at the top of `stack_a`. |
| `pb` | Take the first element at the top of `stack_a` and put it at the top of `stack_b`. |
| `ra` | Shift up all elements of `stack_a` by 1 (first element becomes last). |
| `rb` | Shift up all elements of `stack_b` by 1 (first element becomes last). |
| `rr` | `ra` and `rb` at the same time. |
| `rra` | Shift down all elements of `stack_a` by 1 (last element becomes first). |
| `rrb` | Shift down all elements of `stack_b` by 1 (last element becomes first). |
| `rrr` | `rra` and `rrb` at the same time. |

---

## Instructions

### Compilation

Clone the repository and build the project using the provided `Makefile`:

```bash
make        # Compiles the push_swap executable
make clean  # Removes object files
make fclean # Removes object files and the executable
make re     # Recompiles the project from scratch
