*This project has been created as part of the 42 curriculum by khzernou*

# Push_swap

## Description
**Push_swap** is an algorithmic C project focused on data sorting. The goal of the project is to sort a random stack of integers using a secondary stack and a strictly limited set of manipulation instructions (pushes, swaps, and rotations), all while aiming for the most efficient possible number of moves.

My implementation utilizes a mechanical, cost-based sorting strategy (often referred to as the **Turk Algorithm** in the 42 network). Rather than relying on rigid chunks or radix logic, the program dynamically calculates the exact "push cost" for every single node at every step. It continuously identifies the cheapest number to move, utilizes simultaneous rotations (`rr`, `rrr`) to save operations.

Name of Rule
`sa` (swap a)	Swap first 2 elements at top of stack A. - Do nothing if there is only one element or none.
`sb` (swap b)	Swap first 2 elements at top of stack B. - Do nothing if there is only one element or none.
`ss` 	both sa & sb at same time	

`pa` (Push A)	Take the first element at the top of b and put it at the top of a. - Do nothing if b is empty.
`pb` (Push B)	Take the first element at the top of a and put it at the top of B. - Do nothing if a is empty.

`ra` (Rotate A)	Shift up all elements of stack A by 1. - The first element becomes the last one.
`rb` (Rotate B)	Shift up all elements of stack B by 1. - The first element becomes the last one.
`rr` 	Both `ra` & `rb` at same time	

`rra` (Reverse Rotate A)	Shift down all elements of stack A by 1. - The last element becomes the first one.
`rrb` (Reverse Rotate B)	Shift down all elements of stack B by 1. - The last element becomes the first one.
`rrr` 	`rra`, `rrb` at same time	

## Instructions

### Compilation
The project includes a `Makefile` that handles the compilation of the `push_swap` executable and its `libft` dependency.
We have three more make rules, fclean - cleans all made files. clean - cleans obj files. re - remakes.
To compile the project, run:
```bash
make
# Individual arguments
./push_swap 4 67 3 87 23
# Single string argument
./push_swap "4 67 3 87 23"
```
### Testing & Verification

Generate 100 random numbers and count the moves (Target: < 700)
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

Generate 500 random numbers and count the moves (Target: < 5500)
ARG=$(shuf -i 1-2000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l

Verify the sort with the 42 checker
ARG=$(shuf -i 1-2000 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG

## Resources

[PushSwap Algorithmic Reaserch](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

[Turk Algorithim](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

[Youtube Video Showing and Explaning implementation of Push_Swap](https://www.youtube.com/watch?v=wRvipSG4Mmk&t=1626s)

[Push_Swap: An Easy and Efficient Sorting Algorithm](https://medium.com/@julien-ctx/push-swap-an-easy-and-efficient-algorithm-to-sort-numbers-4b7049c2639a)

Ai Usage:
AI (Google Gemini) was utilized as an interactive tutor and debugging assistant throughout the development of this project. Specifically, AI was used for:
Algorithmic Comprehension.
Norminette Compliance Reminders.
Memory Management: Identifying the source of memory leaks during early development (specifically regarding ft_split matrix freeing and error handling) and advising on safe free() implementations for doubly linked lists.
Documentation: Generating formatted study materials (Notion notes) and assisting with the structuring of this README file.