### TASK:

Write a function that receives two sequences: **A** and **B** of integers and returns one sequence **C**. Sequence **C** should contain all elements from sequence **A** (maintaining the order) except those that are present in sequence **B** \( p \) times, where \( p \) is a prime number.

Example:  
\( A=[2,3,9,2,5,1,3,7,10] \)  

\( B=[2,1,3,4,3,10,6,6,1,7,10,10,10] \)  

\( C=[2,9,2,5,7,10] \)  

**Notes:**  

1. The time complexity is important – try to write an algorithm with good time complexity and specify it in your answer.  
2. You can choose any reasonable type present in your chosen language to represent the sequence.  
3. Make sure the function signature is correct.  
4. Write your own code to test primality.  

---

### 1. FINDING THE FIRST ALGORITHM

At first, I came up with the idea of the following algorithm:

1. The function receives sequence **A**.  
2. The function receives sequence **B**.  
3. Check if element number *i* from sequence **A** is present in sequence **B**.  
4. If element *i* is not present in sequence **B**, insert it into sequence **C**.  
5. If the element is present in sequence **B**, check how many times it appears in sequence **B**.  
6. Check if the number of occurrences of the element in sequence **B** is a prime number. If it is, do not insert it into sequence **C** and remove the elements from sequence **B** that were checked.  
7. If element *i* is present in sequence **B** a number of times that is not a prime number, insert it into sequence **C** and remove all the checked elements, as their indices have been recorded.  
8. Continue checking until the last element in sequence **A**.  

However, after roughly estimating and checking its time complexity (without implementation), it turned out to be an inefficient solution.  

---

### 2. FINDING THE SECOND ALGORITHM

Then, with some help from AI, I found a better algorithm to solve the problem. The difference in time complexity was significant.

#### Algorithm Steps:

1. **Receiving input sequences**:  
   - The function takes two input sequences: **A** and **B**, which are vectors of integers.

2. **Counting occurrences in sequence B**:  
   - An `unordered_map` is used to count how many times each element from sequence **B** occurs.  
   - The key represents a number, and the value is its count in sequence **B**. 

3. **Iterating through sequence A**:  
   - Each element of sequence **A** is checked for its presence in the map of occurrences from **B**.

4. **Checking the presence of an element in B**:  
   - If an element from **A** is found in the map:  
     a) The number of occurrences in **B** is retrieved.  
     b) It is checked whether the number of occurrences is a prime number.  
        - If **true**, the element is rejected and added to the `rejected` map with its count.  
        - If **false**, the element is added to the output sequence **C**.

5. **Adding elements not present in B to C**:  
   - If an element from **A** is not found in the map (and thus not in **B**), it is directly added to the output sequence **C**.

6. **Returning the output sequence**:  
   - After processing all elements of **A**, the sequence **C** is returned, meeting all specified constraints.

7. **Handling rejected elements**:  
   - The `rejected` map is filled with information about the elements that were rejected (occurrence count in **B** was a prime number).  

8. **Static and random tests**:  
   - The algorithm is tested with both hardcoded input data and randomly generated test cases. The results include:
     - Input sequences **A** and **B**.  
     - Output sequence **C**.  
     - Rejected elements and their occurrence counts in **B**.

---

### 3. COMPARISON OF TWO ALGORITHMS

- **Elements in A (size \( n \)).**  
- **Elements in B (size \( m \)).**  

**Algorithm 1:**  
**\( O(n \cdot m + n \cdot m + n \cdot \sqrt{k} + n + n \cdot m) \approx O(n \cdot m) \)**  
- Multiple iterations over sequence **B** make this algorithm less efficient.  

**Algorithm 2:**  
**\( O(m + n + n \cdot \sqrt{k} + n + n) \approx O(m + n) \)**  
- Optimized by using an `unordered_map` for efficient counting and lookups, reducing redundant operations.  

Using an `unordered_map` in Algorithm 2 optimizes the search and counting processes, reducing redundant operations.

---

### 4. IMPLEMENTATION AND TESTS

I have provided code to test in the same file as the solution of the task for simplicity.

There are 6 test cases: one directly from the example and 5 randomly generated.

---

### 5. SUMMARY

I found two solutions; only the second one was implemented because it had a **significant advantage** in time complexity. This algorithm was implemented and tested. Test output includes prime numbers for reference, so each rejected number's occurrence can be checked within this set of prime numbers.  
Implementation, all the functions, and testing are in one file for simplicity of compiling, executing, and analyzing the test cases.
