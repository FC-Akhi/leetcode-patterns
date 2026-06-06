# Range Sum Query - Immutable

## Improved Code

```text
range_sum_query_immutable_v2
```
---

## What am I solving?

I am solving the **Range Sum Query** problem.

Given an input vector, I need to find the sum of elements between two indices:

```text
left and right
```

Both indices are included.

Example:

```text
nums = [1, 2, 3, 4, 5]

sumRange(1, 3) = 2 + 3 + 4 = 9
```

---

## Why am I solving it?

I am solving this to understand how **prefix sum** can improve range sum queries.

In the previous brute-force version, every query looped from `left` to `right`.

That made each query slower for large inputs.

In this version, I use a prefix sum vector so that each range query can be answered in constant time. 🚀

---

## How does the solution work?

First, the program takes the input vector from the user.

Then it creates a prefix sum vector.

For example:

```text
nums = [1, 2, 3, 4]
```

The prefix sum vector is:

```text
prefixSum = [1, 3, 6, 10]
```

Each index stores the sum from index `0` to that index.

Then, for a range query:

```text
sumRange(left, right)
```

the program uses:

```text
prefixSum[right] - prefixSum[left - 1]
```

If `left == 0`, the answer is simply:

```text
prefixSum[right]
```

So range sum queries become fast.😃

---

## Improvements in This Version

This version improves the previous brute-force range query approach.

✅ A prefix sum vector is created.

✅ Each range sum query is answered in `O(1)` time.

✅ Debug mode is added to print the prefix sum vector when needed.

Important note:

The prefix sum construction is still brute-force in this version.

For each index, the code recalculates the sum from index `0` to that index.

So prefix sum creation is not fully optimized yet.

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
O(n^2)
```
because this version uses nested loops.

Each range sum query takes:

```text
O(1)
```

For `m` range queries, total query time is:

```text
O(m)
```

Overall time complexity:

```text
O(n + n + n² + m)
```

Simplified:

```text
O(n² + m)
```

If `m` is similar to `n`, then:

```text
O(n² + n) -> O(n²)
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

## Current Limitation

The main limitation is in prefix sum construction.

This version builds the prefix sum vector using a brute-force nested loop.

So prefix sum creation takes:

```text
O(n^2)
```
This can be improved.

---

## Summary

This version improves range sum queries using prefix sum.🤩

The query part is now faster because each query takes `O(1)` time.🌟

However, the prefix sum vector is still created using a brute-force method.😢

So lets see if we can optimize in next version 💪


