
# LeetCode Patterns Practice Repository

This repository documents my structured practice of **15–16 important LeetCode coding patterns**.
For each pattern, I first implement the basic or brute-force version of the concept, then gradually solve related LeetCode problems using improved versions.

The goal of this repository is to build a clear understanding of each pattern from the foundation level to optimized problem-solving approaches.

---

## Repository Structure

Each pattern has its own folder. Inside each pattern folder, I first write the initial implementation of the pattern using the naming format:

```text
<pattern_name>_v_init.cpp
```

For example:

```text
prefix_sum_v_init.cpp
```

This initial version (shitty version) usually contains the basic implementation of the pattern.
Along with the code, I also write a detailed README file for that implementation:

```text
README_v_init.md
```

After understanding the basic idea of the pattern, I solve multiple LeetCode problems related to that pattern.
Each LeetCode problem has its own folder under:

```text
leetcode_problems/
```

For each LeetCode problem, I maintain multiple versions of the solution.
Each version represents a step-by-step improvement from a basic approach to a more optimized approach.

For example:

```text
range_sum_query_immutable_v0.cpp
range_sum_query_immutable_v1.cpp
range_sum_query_immutable_v2.cpp
```

Each code version also has its own detailed README file explaining the logic, approach, complexity, and improvements.

---

## Naming Convention

### Initial Pattern Implementation

```text
<pattern_name>_v_init.cpp
README_v_init.md
```

Example:

```text
prefix_sum_v_init.cpp
README_v_init.md
```

### LeetCode Problem Solutions

```text
<problem_name>_v0.cpp
README_v0.md

<problem_name>_v1.cpp
README_v1.md

<problem_name>_v2.cpp
README_v2.md
```

Here:

* `v0` usually represents the first improved or brute-force solution.
* `v1` represents an improved version.
* `v2` or later versions represent further optimized approaches.

---

## Example Directory Tree

```text
leetcode-patterns/
|
|--> prefix_sum/
|    |
|    |--> prefix_sum_v_init.cpp
|    |--> README_v_init.md
|    |
|    |--> leetcode_problems/
|         |
|         |--> 303_range_sum_query_immutable/
|         |    |
|         |    |--> range_sum_query_immutable_v0.cpp
|         |    |--> README_v0.md
|         |    |
|         |    |--> range_sum_query_immutable_v1.cpp
|         |    |--> README_v1.md
|         |    |
|         |    |--> range_sum_query_immutable_v2.cpp
|         |    |--> README_v2.md
|         |    |
|         |    |--> range_sum_query_immutable_v3.cpp
|         |    |--> README_v3.md

```

---

## Purpose of This Repository

The purpose of this repository is to:

* Learn each LeetCode pattern from the basic level.
* Start with brute-force or initial implementations.
* Improve each solution step by step.
* Keep detailed README files for every version.
* Compare different approaches clearly.
* Build strong coding interview preparation notes.
* Prepare for technical interviews by understanding patterns instead of memorizing solutions.

---

## Current Workflow

For each pattern, I follow this workflow:

```text
1. Understand the basic idea of the pattern.
2. Write the initial implementation: <pattern_name>_v_init.cpp
3. Write README_v_init.md explaining the initial implementation.
4. Solve related LeetCode problems.
5. For each problem, write multiple solution versions.
6. Write a detailed README for each version.
7. Compare brute-force, improved, and optimized approaches.
8. Record time and space complexity for each version.
```

---

## Example Workflow for Prefix Sum

```text
prefix_sum/
|
|--> prefix_sum_v_init.cpp
|--> README_v_init.md
|
|--> leetcode_problems/
     |
     |--> 303_range_sum_query_immutable/
          |
          |--> range_sum_query_immutable_v0.cpp
          |--> README_v0.md
          |
          |--> range_sum_query_immutable_v1.cpp
          |--> README_v1.md
```

In this example:

* `prefix_sum_v_init.cpp` contains my basic implementation of prefix sum which 
came first in my mind.
* `README_v_init.md` explains the core concept.
* `range_sum_query_immutable_v0.cpp` may contain the brute-force solution.
* `range_sum_query_immutable_v1.cpp` may contain the optimized prefix sum solution.
* Each README explains the reasoning, implementation, and complexity.

---

## Notes

This repository is not only for storing accepted LeetCode solutions.
It is also a learning journal where I document how my understanding improves from the initial version to optimized versions.

The main focus is:

```text
Understand pattern -> Write brute force -> Improve solution -> Compare time & space complexities -> Document clearly
```



### Maintained some fundamental rules in writing code

- A method should and must return something. Either a scalar value, or address, or reference.

- Never declare any method with void unless it is solely targetted to log something.

- Never assign more than one responsibility to any method.

- A method definition should not go more than 10 lines of statements. super maximum 12~13 lines. If you have to write more than that, then for sure you already messed up defining responsibility.

- A method must and must talk through interface. never directly take any global shit inside the method.

- Very carefully decide while defining arguments of a method, for reference type datatype, when you have to use pointer and when you have to use reference. This is also super fucking important. Find the answer from the compilation point of view.

- Use relevant smart pointers. Don’t just use blindly make_unique<> ptr. Shared pointer has some advantages too besides it's draw backs. Each of smart pointers comes with super powerful debugger properties. Use them as your weapon. Whenever you get the dangling error (i.e., segmentation fault) track and trace how the address is travelling and handed over. Even try to do this whenever there are no error at all. Try to see them in your head. these will be very helpful when you start graph and tree.

- Use formal documentation process at the beginning of the definition/declaration of a method.