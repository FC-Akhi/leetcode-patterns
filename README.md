# 🚀 LeetCode Patterns Practice Repository

This repository documents my structured practice of **15–16 important LeetCode coding patterns**.  
For each pattern, I will solve related LeetCode problems by starting with a **brute-force approach** first, then gradually improving the solutions step by step.

The goal of this repository is to build a clear understanding of each pattern from the **brute-force level** to **optimized approaches**. And also I am using this as initiation before I dive deep in to DSA. 

---

## Why do people still need practice DSA while AI can solve programming problems?

AI can generate code, but developers still need DSA knowledge to understand, verify, debug, and improve that code.

DSA practice helps build problem-solving ability. It also helps us understand time complexity, space complexity, edge cases, and design trade-offs.

AI can assist, but a developer must still know whether the solution is correct, efficient, and safe.


---

## Repository Structure

Each pattern has its own folder. Inside each pattern folder, I also wrote a simple README file including Youtube link on that pattern:

```text
README_init.md
```

After that, I solve multiple LeetCode problems related to that pattern.
Each LeetCode problem has its own folder under:

```text
leetcode_problems/
```

For each LeetCode problem, I maintain multiple versions of the solution.
Each version represents a step-by-step improvement from a brute-force (leetcode version only) approach to a more optimized approach.

For example:

```text
range_sum_query_immutable_v0.cpp ---> Bruteforce approach and only leetcode submitable
range_sum_query_immutable_v1.cpp ---> Optimized prefix sum solution with local testing and industry-style development structure (except 303 problem set)
range_sum_query_immutable_v2.cpp ---> More optimized and can also run and test in local system
...
```


Each code version also has its own detailed README file explaining the logic, approach, complexity, and limitations.

Additionally, I maintain separate README files to document the key learnings I gather throughout this journey.

For examnple:

```text
README_learning_1.md
...
```
---

## Naming Convention

### LeetCode Problem Solutions

```text
<problem_name>_v0.cpp
README_v0.md

<problem_name>_v1.cpp
README_v1.md

<problem_name>_v2.cpp
README_v2.md

...
```

Here:

* `v0` usually represents the brute-force solution and only leetcode submitable.
* `v1` represents an improved version.
* `v2` or later versions represent further optimized approaches.
...
---

## Directory Tree

```text
leetcode-patterns/
|
|--> prefix_sum/
|    |
|    |--> README_init.md
|    |--> prefix_sum.png
|    |--> leetcode_problems/
|         |
|         |--> 303_range_sum_query_immutable/
|         |    |
|         |    |--> range_sum_query_immutable_v0.cpp
|         |    |--> range_sum_query_immutable_v1.cpp
|         |    |--> range_sum_query_immutable_v2.cpp
|         |    |--> range_sum_query_immutable_v3.cpp
|         |    |--> README_v0.md
|         |    |--> README_v1.md
|         |    |--> README_v2.md
|         |    |--> README_v3.md
|         |    |--> README_learning_1.md
|         |    |--> README_learning_2.md
...
```
---
---

## Purpose of This Repository

The purpose of this repository is to:

* Learn each LeetCode pattern (17 approx) from the basic level.
* Start with the brute-force.
* Improve each solution step by step.
* Keep detailed README files for every version.
* Compare different approaches clearly.
* Prepare for technical interviews by understanding patterns instead of memorizing solutions.
* Log the leanrings in differnet README's

---

## Current Workflow

For each pattern, I follow this workflow:

```text
1. Understand the basic idea of the pattern.
2. Solve related LeetCode problems first in bruteforce way.
3. Write the README.md of the first version (bruteforce)
5. For each problem, write multiple updated versions.
6. Write a detailed README for each solution version, explaining the logic, approach, complexity, improvements, and limitations.
7. Also maintain separate learning README files where I log new concepts, observations, and lessons learned throughout the journey.
8. Compare brute-force, improved, and optimized approaches.
9. Record time and space complexity for each version.
```

---

## Notes

This repository is not only for storing accepted LeetCode solutions.
It is also a learning journal where I document how my understanding improves from the initial version to optimized versions.

The main focus is:

```text
Understand pattern -> Write brute force -> Improve solution -> Compare time & space complexities -> Document clearly
```



### Maintained some fundamental rules in writing code

- main() should be clean. whatever things you do, main should be calling them.

- A method should and must return something. Either a scalar value, or address, or reference.

- Never declare any method with void unless it is solely targetted to log something.

- Never assign more than one responsibility to any method.

- A method definition should not go more than 10 lines of statements. super maximum 12~13 lines. If you have to write more than that, then for sure you already messed up defining responsibility.

- A method must and must talk through interface. never directly take any global shit inside the method.

- Very carefully decide while defining arguments of a method, for reference type datatype, when you have to use pointer and when you have to use reference. This is also super fucking important. Find the answer from the compilation point of view.

- Use relevant smart pointers. Don’t just use blindly make_unique<> ptr. Shared pointer has some advantages too besides it's draw backs. Each of smart pointers comes with super powerful debugger properties. Use them as your weapon. Whenever you get the dangling error (i.e., segmentation fault) track and trace how the address is travelling and handed over. Even try to do this whenever there are no error at all. Try to see them in your head. these will be very helpful when you start graph and tree.

- Use formal documentation process at the beginning of the definition/declaration of a method.