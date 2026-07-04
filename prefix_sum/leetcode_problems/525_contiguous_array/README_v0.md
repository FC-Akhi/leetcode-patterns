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

* Original `0` becomes balance value `-1`.
* Original `1` becomes balance value `+1`.
* A subarray with equal number of `0`s and `1`s will have balance sum `0`.

So the problem becomes:

```text
Find the longest subarray whose balance sum is 0.
```

To do this, we use prefix sum.

---

# Important Index Idea

For prefix sum, we imagine one virtual position before the original array starts.

This virtual position is index `-1` in the original `nums` array.

Example:

```cpp
nums = {0, 1, 0, 1}
```

Original nums indices:

```text
nums index:      -1    0    1    2    3
nums value:            0    1    0    1
```

Here, index `-1` means:

```text
Before the array starts
```

This is why the prefix sum array starts with `0`.

---

# Step 1: Convert nums into Balance Array

Original array:

```text
nums index:       0    1    2    3
nums value:       0    1    0    1
```

Convert:

```text
0 -> -1
1 -> +1
```

Balance array:

```text
balance index:    0    1    2    3
balance value:   -1   +1   -1   +1
```

The balance array has the same normal indices as `nums`.

So:

```text
nums[0] = 0  -> balance[0] = -1
nums[1] = 1  -> balance[1] = +1
nums[2] = 0  -> balance[2] = -1
nums[3] = 1  -> balance[3] = +1
```

---

# Step 2: Build Prefix Sum Array

The prefix sum array stores the running balance.

```text
prefix index:     0    1    2    3    4
prefix_sum:       0   -1    0   -1    0
```

The first value is:

```text
prefix_sum[0] = 0
```

This means:

```text
Before processing any element, the balance is 0.
```

Then we calculate prefix sum over the balance array:

```text
prefix_sum[1] = balance[0] = -1

prefix_sum[2] = balance[0] + balance[1]
              = -1 + 1
              = 0

prefix_sum[3] = balance[0] + balance[1] + balance[2]
              = -1 + 1 - 1
              = -1

prefix_sum[4] = balance[0] + balance[1] + balance[2] + balance[3]
              = -1 + 1 - 1 + 1
              = 0
```

So the full prefix sum array is:

```text
prefix_sum = {0, -1, 0, -1, 0}
```

---

# Step 3: Prefix Index and nums Index Relationship

The prefix index represents how many elements have already been processed.

```text
prefix index 0 means before nums starts        -> virtual nums index -1
prefix index 1 means after processing nums[0]  -> nums index 0
prefix index 2 means after processing nums[1]  -> nums index 1
prefix index 3 means after processing nums[2]  -> nums index 2
prefix index 4 means after processing nums[3]  -> nums index 3
```

So:

```text
prefix index k represents the position after nums index k - 1
```

This is the main reason why prefix index difference gives the subarray length.

---

# Step 4: Store Prefix Sum Indices in a Map

Now we store each prefix sum value and all prefix indices where it appears.

Prefix sum array:

```text
prefix index:     0    1    2    3    4
prefix_sum:       0   -1    0   -1    0
```

Map:

```text
prefix sum value 0  -> [0, 2, 4]
prefix sum value -1 -> [1, 3]
```

This means:

```text
prefix sum 0 appeared at prefix indices 0, 2, and 4
prefix sum -1 appeared at prefix indices 1 and 3
```

---

# Step 5: Why Repeated Prefix Sum Gives a Balanced Subarray

When the same prefix sum appears again, it means the running balance has returned to a previous value.

That means the balance values added between those two prefix positions cancel out to `0`.

Since:

```text
0 -> -1
1 -> +1
```

a balance sum of `0` means the corresponding range in `nums` has equal number of `0`s and `1`s.

---

# Step 6: Calculate Length Using Prefix Indices

For prefix sum value `0`:

```text
0 -> [0, 2, 4]
```

First prefix index:

```text
0
```

Last prefix index:

```text
4
```

Length:

```text
4 - 0 = 4
```

Using the nums index idea:

```text
prefix index 0 maps to virtual nums index -1
prefix index 4 maps to nums index 3
```

So this is like:

```text
3 - (-1) = 4
```

The actual subarray is:

```text
nums[0..3] = {0, 1, 0, 1}
```

This contains:

```text
two 0s
two 1s
```

So the balanced length is:

```text
4
```

---

For prefix sum value `-1`:

```text
-1 -> [1, 3]
```

First prefix index:

```text
1
```

Last prefix index:

```text
3
```

Length:

```text
3 - 1 = 2
```

Using the nums index idea:

```text
prefix index 1 maps to nums index 0
prefix index 3 maps to nums index 2
```

So the distance is like:

```text
2 - 0 = 2
```

But the actual balanced subarray starts after nums index `0`.

So the actual subarray is:

```text
nums[1..2] = {1, 0}
```

This contains:

```text
one 1
one 0
```

So the balanced length is:

```text
2
```

---


# Summary

The prefix sum index is not the same as the normal nums index.

A prefix index represents a boundary position:

```text
prefix index 0 means before nums starts
prefix index 1 means after nums[0]
prefix index 2 means after nums[1]
prefix index 3 means after nums[2]
prefix index 4 means after nums[3]
```

So when we subtract two prefix indices, we get the length of the subarray between those two prefix boundaries.

Repeated prefix sum means the running balance returned to a previous value. Therefore, the balance values between those two prefix positions sum to `0`, and the corresponding subarray in `nums` contains equal numbers of `0`s and `1`s.

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
