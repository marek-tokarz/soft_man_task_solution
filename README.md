# Repository Description

This repository consists of a two versions of solutions in C++ for a task:

### TASK:

Write a function that receives two sequences: **A** and **B** of integers and returns one sequence **C**. Sequence **C** should contain all elements from sequence **A** (maintaining the order) except those that are present in sequence **B** \( p \) times, where \( p \) is a prime number.

Example:  
**A** = [2, 3, 9, 2, 5, 1, 3, 7, 10]  
**B** = [2, 1, 3, 4, 3, 10, 6, 6, 1, 7, 10, 10, 10]  
**C** = [2, 9, 2, 5, 7, 10]

### Notes:

1. The time complexity is important – try to write an algorithm with good time complexity and specify it in your answer.  
2. You can choose any reasonable type present in your chosen language to represent the sequence.  
3. Make sure the function signature is correct.  
4. Write your own code to test primality.

---

The problem requires an efficient algorithm to minimize time complexity, and multiple approaches were considered. The initial algorithm was inefficient due to multiple checks, leading to a more optimized second algorithm using an `unordered_map` for counting occurrences in **B** and checking for prime numbers. The time complexity of the second algorithm is significantly improved. Both solutions were compared, and the final implementation was tested with multiple test cases. Another version of solution was implemented - a version with manual tests with generated test cases with expected results.
