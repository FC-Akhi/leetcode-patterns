# LeetCode 525: Contiguous Array

# Overview

This solution solves the **Contiguous Array** problem from LeetCode.

The goal is to find the maximum length of a contiguous subarray that contains an equal number of `0`s and `1`s.

This code is **not a brute force solution**. Instead, it uses the **prefix sum + hashmap** technique.

A brute force version would check every possible subarray directly. That approach will be written separately in:

```cpp
contiguous_array_v1.cpp 
```

This implementation is designed as a LeetCode-submittable. But, started bruteforce will be found in `contiguous_array_v1.cpp `


---

# How LeetCode Expects the Code

LeetCode does not require a full local program structure.

For submission, LeetCode expects:

* No `main()` function.
* A class named `Solution`.
* The required method inside the `Solution` class.
* The method should be declared as `public`.
* The method name `findMaxLength` must match the problem requirement.
* The method should receive the input `nums` as a function parameter.
* The method should return the final answer maximum length directly.

For this problem, LeetCode expects the following structure:

```cpp
class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        // solution logic here
    }
};
```

---

## Expected Class Name

The expected class name is:

```cpp
Solution
```

So the code should be written inside:

```cpp
class Solution {
public:
    // required method
};
```

---

## Required Method

The required method name is:

```cpp
findMaxLength
```

The method receives:

```cpp
std::vector<int>& nums
```

The method returns:

```cpp
int
```

Full method signature:

```cpp
int findMaxLength(std::vector<int>& nums)
```

---

## What the Method Receives

The method receives a vector named `nums`.

```cpp
std::vector<int>& nums
```

The vector contains only binary values:

* `0`
* `1`

Example:

```cpp
nums = {0, 1, 1, 0, 1, 0}
```

---

## Given Constraints

The common constraints for this problem are:

* `1 <= nums.length <= 10^5`
* `nums[i]` is either `0` or `1`

Because the input size can be large, a brute force solution is not preferred for final LeetCode submission.

---

# Main Idea

We convert the binary input array like this:

```cpp
0 -> -1
1 -> +1
```

After conversion:

* A subarray with equal number of `0`s and `1`s will have sum `0`.
* If the same prefix sum appears at two different indices, then the subarray between those indices has sum `0`.
* A sum of `0` means the subarray has equal number of `0`s and `1`s.

---

# Approach

The current implementation follows these steps:

* Get the size of the input vector.
* Create a `balance_array`.
* Convert every `0` into `-1`.
* Convert every `1` into `+1`.
* Create a `prefix_sum` array of size `n + 1`.
* Storing 0 at the first index of prefix_sum. 
* Store the running prefix sum of the balance array in to the rest of indices.
* Use a map to store all indices where each prefix sum appears.
* For each prefix sum value:

  * Take the first index where it appears.
  * Take the last index where it appears.
  * Calculate the distance between them.
  * Update the maximum length.
* Return the maximum balanced subarray length.

---

## Example

Input:

```cpp
nums = {0, 1, 1, 1, 1, 1, 0, 0, 0}
```

Converted balance array:

```cpp
{-1, +1, +1, +1, +1, +1, -1, -1, -1}
```

The algorithm finds the longest subarray where the number of `-1`s and `+1`s are equal.

Output:

```cpp
6
```

---
# Time and Space Complexity of the code
## Time Complexity

Current implementation:

```cpp
O(n log n)
```

Reason:

* Creating the balance array takes `O(n)`.
* Creating the prefix sum array takes `O(n)`.
* Inserting prefix sum values into `std::map` takes `O(log n)` per insertion.
* There are `n + 1` prefix sum values.

So the total time complexity is:

```cpp
O(n log n)
```

---

## Space Complexity

Current implementation:

```cpp
O(n)
```

Reason:

* `balance_array` stores `n` values.
* `prefix_sum` stores `n + 1` values.
* The map stores prefix sum values and their indices.

So the total extra space is:

```cpp
O(n)
```

---

# Limitations of the Current Implementation

The current solution is correct, but it has some limitations:

* It uses `std::map`, so the time complexity is `O(n log n)` instead of average `O(n)`.
* It stores a separate `balance_array`, which is not strictly necessary.
* It stores a separate `prefix_sum` array, which is also not strictly necessary.
* It stores all indices for each prefix sum value, but only the first index is needed for an optimized solution.
* It uses more memory than required.
* The implementation is useful for learning and understanding the prefix sum idea, but it can be optimized further.

---

# Possible Optimized code

---

# Summary

This solution uses the prefix sum pattern to solve the Contiguous Array problem.

The key idea is:

```cpp
0 -> -1
1 -> +1
```

Then, if the same prefix sum appears more than once, the subarray between those two positions has an equal number of `0`s and `1`s.

This implementation is not brute force. It avoids checking every possible subarray directly.
```
