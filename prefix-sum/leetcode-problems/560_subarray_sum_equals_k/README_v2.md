# Subarray Sum Equals K

## 1st Optimized Bruteforce Code

```text
subarray_sum_equals_k_v2.cpp
```
---
## How does the solution work?

This version solves **LeetCode 560: Subarray Sum Equals K** using an improved brute-force approach.

The goal is to count how many contiguous subarrays have a sum equal to `k`.

The solution works by selecting every possible starting index of a subarray and then extending the subarray one element at a time.

For each starting index `m`, the variable `sum` stores the running sum of the current subarray.

Example:

```text
nums = [1, 2, 3]
k = 3
```

When `m = 0`:

```text
sum = nums[0] = 1       -> [1]
sum = sum + nums[1] = 3 -> [1, 2]  valid
sum = sum + nums[2] = 6 -> [1, 2, 3]
```

When `m = 1`:

```text
sum = nums[1] = 2       -> [2]
sum = sum + nums[2] = 5 -> [2, 3]
```

When `m = 2`:

```text
sum = nums[2] = 3       -> [3] valid
```

So the valid subarrays are:

```text
[1, 2]
[3]
```

Therefore, the answer is:

```text
2
```

---

## Improvements in This Version

This version improves the earlier brute-force implementation.

In the previous brute-force version, the code used three nested loops:

```text
start index
end index
calculate sum from scratch
```

That caused repeated summation of the same elements.

In this version, the code avoids recalculating the sum from scratch.

Instead, it keeps a running sum:

```cpp
sum = sum + nums[i];
```

So once the sum of a subarray is calculated, the next subarray sum is created by adding only the next element.

This removes the third nested loop.

Main improvements:

```text
No third loop for recalculating subarray sum
No extra vector needed
Uses one running sum variable
Improves time complexity from O(n^3) to O(n^2)
Improves extra space usage to O(n)
```

---

## Complexity Analysis

### Time Complexity

The outer loop selects the starting index:

```cpp
for (int m = 0; m < n; m++)
```

The inner loop extends the subarray from that starting index:

```cpp
for (i = m + 1; i < n; i++)
```

For each starting index, the inner loop may run up to `n` times.

So the total number of operations is approximately:

```text
n + (n - 1) + (n - 2) + ... + 1
```

This becomes:

```text
n(n + 1) / 2
```

Therefore, the time complexity is:

```text
O(n^2)
```

---

### Space Complexity

This version only uses a few integer variables:

```cpp
int count;
int sum;
int i;
int n;
std::vector<int>& nums
```

It does not create a prefix sum array, hash map, or extra vector.

Therefore, the extra space complexity is:

```text
O(n)
```

---

# Limitations of the Current Implementation

* This solution still checks all possible contiguous subarrays.
* Time complexity is still `O(n^2)`.
* It does not use the optimized prefix sum + hash map technique.
* It may become slow for very large input arrays.
* It does not remember previous prefix sums.
* It cannot reach the optimized `O(n)` average time complexity.

