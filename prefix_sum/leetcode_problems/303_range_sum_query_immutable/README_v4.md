# Range Sum Query - Immutable

## Improved Code - Industry Grade Dev code

```text
range_sum_query_immutable_v4
```

---

## How does the solution work?

The `NumArray` constructor builds a prefix sum vector.

Example:

```text
nums      = [-2, 0, 3, -5, 2, -1]
prefixSum = [-2, -2, 1, -4, -2, -3]
```

Each value in `prefixSum` stores the sum from index `0` to the current index.

For a query:

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

This makes every range query run in constant time.

---

## Improvements in This Version

This version is closer to an industry-style development version.

Main improvements:

* Prefix sum is built inside the constructor.
* Prefix sum is stored privately inside the class.
* `sumRange()` no longer needs an external prefix sum vector.
* Invalid input vector is handled using exception.
* Invalid range query is handled using exception.
* Manual input is removed.
* Automated test cases are added using `assert`.
* Unit tests and integration-style testing are included.

This makes the code cleaner, more reusable, and easier to test.

---

## Complexity Analysis

Let:

```text
n = size of the input vector
m = number of range queries
```

---

### Time Complexity

Building the prefix sum vector in the constructor takes:

```text
O(n)
```

Each `sumRange(left, right)` call takes:

```text
O(1)
```

For `m` range queries, total query time is:

```text
O(m)
```

Overall time complexity:

```text
O(n + m)
```

---

### Space Complexity

The class stores one prefix sum vector of size `n`.

So the space complexity is:

```text
O(n)
```

---

## Summary

This version uses the optimized prefix sum approach.

The object prepares the prefix sum once during construction. After that, each range sum query is answered in constant time.

This version also improves code quality by using private data, exception handling, and automated tests.

Final complexity:

```text
Time Complexity: O(n + m)
Space Complexity: O(n)
```

This is a clean industry grade dev code version for learning the prefix sum pattern.

