*This project has been created as part of the 42 curriculum by `<aabufarw>`, `<reabdall>`.*

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
```

### Execution

Run `./push_swap` followed by a list of integers (either as separate arguments or as a single quoted string):

```bash
# Default execution (adaptive strategy)
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"

# Force a specific sorting strategy or enable benchmark mode
./push_swap --simple 5 4 3 2 1
./push_swap --medium 42 12 89 3 17
./push_swap --complex 100 50 25 75 10
./push_swap --adaptive --bench 4 67 3 87 23
```

### Available Flags

| Flag | Behavior |
| :--- | :--- |
| `--simple` | Forces the $O(n^2)$ **Insertion Sort** strategy. |
| `--medium` | Forces the $O(n\sqrt{n})$ **Chunk Sort** strategy. |
| `--complex` | Forces the $O(n \log n)$ **Radix Sort** strategy. |
| `--adaptive` | *(Default)* Computes the input disorder ratio and selects the optimal strategy automatically. |
| `--bench` | Outputs diagnostic metrics (disorder percentage, selected strategy, total operations, and per-operation counts) to `stderr` while keeping standard instructions on `stdout`. |

### Testing & Verification

```bash
# Count the number of operations on 100 random numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Verify sorting correctness with the provided 42 checker binary
ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```

---

## Technical Choices & Algorithms

### Data Structure & Coordinate Compression (Indexing)
* **Stacks:** Both `stack_a` and `stack_b` are implemented as linked lists supporting $O(1)$ top insertions/removals and efficient rotations.
* **Value Normalization:** Before sorting, raw integer inputs (including negative numbers and full `INT_MIN` to `INT_MAX` values) are mapped to zero-based rank indices ($0$ to $n - 1$) based on their sorted order. This allows bitwise operations in Radix Sort and clean range boundaries in Chunk Sort.

### Disorder Metric & Adaptive Selection
Before executing any moves, the program computes the **disorder ratio** by comparing the number of inverted pairs ($i < j$ where $a[i] > a[j]$) against the total number of possible pairs $\frac{n(n - 1)}{2}$:

$$\text{Disorder} = \frac{\text{Inverted Pairs}}{\text{Total Pairs}} \in [0.0, 1.0]$$

* **Low Disorder ($\text{disorder} < 0.2$) or Small Inputs ($n \le 5$):** Uses **Insertion Sort** (with dedicated minimal-move routines for $2$ to $5$ elements).
* **Medium Disorder ($0.2 \le \text{disorder} < 0.5$):** Uses **Chunk Sort**.
* **High Disorder ($\text{disorder} \ge 0.5$):** Uses **Radix Sort**.

### Sorting Strategies

1. **Simple Strategy — Insertion Sort ($O(n^2)$):**
   * Repeatedly locates the smallest element (or insertion target) in `stack_a`, rotates it to the top via the shortest path (`ra` or `rra`), and pushes it to `stack_b` (`pb`) until `stack_a` holds $\le 3$ elements.
   * Sorts the remaining $3$ elements directly in `stack_a`, then pushes everything back from `stack_b` (`pa`) in sorted order.
   * **Justification:** Minimal overhead and optimal move counts for very small stacks or nearly sorted sequences.

2. **Medium Strategy — Chunk Sort ($O(n\sqrt{n})$):**
   * Partitions the normalized indices into contiguous value ranges (chunks) sized proportionally to $\sqrt{n}$.
   * Scans `stack_a` and pushes elements belonging to the active chunk to `stack_b` (`pb`), rotating smaller elements within the chunk (`rb`) to pre-order `stack_b` into a rough distribution shape.
   * Once `stack_a` is empty, repeatedly finds the maximum index in `stack_b`, rotates it to the top via the shortest direction (`rb` or `rrb`), and pushes it back to `stack_a` (`pa`).
   * **Justification:** Significantly reduces rotation costs compared to pure $O(n^2)$ insertion while maintaining low operation counts on medium-sized datasets.

3. **Complex Strategy — Binary Radix Sort ($O(n \log n)$):**
   * Operates bitwise on the normalized non-negative indices from the Least Significant Bit (LSB) to the Most Significant Bit (MSB).
   * For each bit position, iterates through `stack_a`: elements with a `0` bit are pushed to `stack_b` (`pb`), while elements with a `1` bit stay in `stack_a` via `ra`. After scanning all elements, everything in `stack_b` is pushed back to `stack_a` (`pa`).
   * **Justification:** Guarantees predictable $O(n \log n)$ scaling without worst-case quadratic degradation on large, heavily disordered inputs.

---

## Contributions & Team Collaboration

This project was developed collaboratively by both partners using pair programming and shared design reviews across every stage of development:

* **`<aabufarw>` & `<reabdall>`:**
  * Jointly designed the stack data structure, input parser, error validation (`INT_MIN`/`INT_MAX` bounds, duplicates, non-numeric inputs), and index normalization.
  * Co-implemented and benchmarked all three sorting algorithms (**Insertion Sort**, **Chunk Sort**, and **Radix Sort**) as well as the adaptive disorder calculation and `--bench` reporting.
  * Collaborated on memory leak verification, edge-case testing, and Norminette compliance.

---

## Resources

### References & Documentation
* **42 `push_swap` Subject PDF** — Official specification for allowed stack operations, error handling, complexity benchmarks, and flag requirements.
* **Sorting Algorithms & Complexity:**
  * *Insertion Sort & Small-Stack Optimization* — [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
  * *Radix Sort on Two Stacks* — [Push_swap Radix Sort Tutorial](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
  * *Chunk Partitioning Strategies* — [42 Push_swap Optimization Guide](https://medium.com/@kilfenbaridon/how-to-over-optimize-an-algorithm-push-swap-42-school-project-d01a50e5fd78)
* **Testing & Visualization Tools:**
  * [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer) — Graphical visualization of stack rotations and algorithm behavior.
  * `valgrind` — Memory leak and invalid memory access verification.

### AI Usage Disclosure
* **Scope of Use:** AI tools were used strictly as a learning and documentation aid—specifically to clarify Big-O time/space complexity trade-offs between chunk sizing and bitwise radix passes, brainstorm edge cases for input parsing.
* **Verification:** All C source code, stack operations, and sorting logic were written, traced, and peer-reviewed manually by both team members.
