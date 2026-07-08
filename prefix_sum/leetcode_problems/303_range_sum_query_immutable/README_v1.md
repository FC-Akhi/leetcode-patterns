# Range Sum Query - Immutable

## Optimized Bruteforce Code

```text
range_sum_query_immutable_v1
```

---



## Improvements in This Version

In this improved version, I focused on making the code better for local testing and learning.

### 1. Constraint validation added

The code validates the input size based on the given constraint:

```text
1 <= nums.length <= 10^4
```

It also validates each element based on the constraint:

```text
-10^5 <= nums[i] <= 10^5
```

The range input is also checked to make sure:

```text
0 <= left <= right < nums.length
```

---

### 2. User input added for local testing

This version takes user input for:

```text
1. Vector size
2. Vector elements
3. Number of range queries
4. left and right index for each query
```

This is not required by LeetCode, but it is useful for local testing and learning.

LeetCode automatically handles input internally, but this local version helps me understand how the class works with manual input.

---

### 3. Design decision about extra space

The code stores a copy of the input vector inside the `NumArray` object.

This requires extra space:

```text
O(n)
```

I intentionally kept this design because I want to keep the original input vector unchanged.

This is a trade-off.

Instead of modifying or replacing the original input vector, I keep a separate copy inside the object. This can be useful if the original vector is needed later for another purpose.

So the design choice is:

```text
Use extra O(n) space, but preserve the original input vector.
```

---

## Complexity Analysis

Let:

```text
n = size of the input vector
```

### Time Complexity

Creating the input vector takes:

```text
O(n)
```

Copying the vector into the object takes:

```text
O(n)
```

Each `sumRange(left, right)` call takes:

```text
O(n)
```
in the worst case.

For `m` queries, the total query time is:

```text
O(m * n)
```

Overall time complexity:

```text
O(n + n + (m * n))
```

Simplified:

```text
-> O(2n + (m * n))
-> O((m * n))
If number of ranges is also n, then:
m = n
-> O(n²)       // simplified final Big-O
```

The input validation loops depend on how many invalid attempts the user makes. Under normal valid input, they do not change the main algorithmic complexity.

---

### Space Complexity

The object stores a copy of the input vector.

So the extra space complexity is:

```text
O(n)
```

---

# Limitations of the Current Implementation

This version is still brute-force.

For every query, it loops from `left` to `right`.

So if there are many queries, the solution can become slow.

This limitation will be improved in the next version using the **prefix sum** approach.

---