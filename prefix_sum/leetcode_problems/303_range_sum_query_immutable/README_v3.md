# Range Sum Query - Immutable

## Improved Code

```text
range_sum_query_immutable_v3
```
---

## What am I solving?

I am solving the **Range Sum Query - Immutable** problem.

The goal is to find the sum of elements between two indices:

```text
left and right
```

Both `left` and `right` are included in the sum.

Example:

```text
nums = [1, 2, 3, 4, 5]

sumRange(1, 3) = 2 + 3 + 4 = 9
```

---

## Why am I solving it?

I am solving this problem to understand how **prefix sum** improves repeated range sum queries. 🚀

In the brute-force approach, every query needs a loop from `left` to `right`.

That becomes slow when there are many queries.

In this version, I first create a prefix sum vector.
Then each range query can be answered in constant time.

---

## How does the solution work?

First, the program takes an input vector from the user.

Example:

```text
nums = [1, 2, 3, 4, 5]
```

Then it creates a prefix sum vector:

```text
prefixSum = [1, 3, 6, 10, 15]
```

Each position stores the cumulative sum from index `0` to that index.

For range query:

```text
sumRange(left, right)
```

If `left == 0`, the answer is:

```text
prefixSum[right]
```

Otherwise, the answer is:

```text
prefixSum[right] - prefixSum[left - 1]
```

Example:

```text
sumRange(1, 3)
= prefixSum[3] - prefixSum[0]
= 10 - 1
= 9
```

So after prefix sum construction, range sum queries become fast. ⚡

---

## Improvements in This Version

✅ Prefix sum vector is created using an optimized approach.

And some improvements from previous 

The key improvement is in prefix sum construction:

```text
prefixSum[i] = prefixSum[i - 1] + nums[i]
```

This avoids recalculating the sum from the beginning every time.

---

## Complexity Analysis

Let:

```text
n = size of the input vector
```

---

### Time Complexity

Taking input vector values takes:

```text
O(n)
```

Copying the input vector into the class vector takes:

```text
O(n)
```

Creating the prefix sum vector takes:

```text
O(n)
```

Each `sumRange(left, right)` query takes:

```text
O(1)
```

For `m` queries, total query time is:

```text
O(m)
```

Overall time complexity:

```text
O(n + n + n + m)
```

Simplified:

```text
O(n + m)
```

---

### Space Complexity

The program stores:

```text
input vector in main       -> O(n)
copy inside NumArray       -> O(n)
prefix sum vector          -> O(n)
```

Total space:

```text
O(n + n + n)
```

Simplified:

```text
O(n)
```

---


## Summary

This version improves the previous solution by using an optimized prefix sum construction. ✨

Now:

```text
Prefix sum construction -> O(n)
Each range query        -> O(1)
Overall complexity      -> O(n)
```

This is a strong optimized version for learning the prefix sum pattern. 💪
