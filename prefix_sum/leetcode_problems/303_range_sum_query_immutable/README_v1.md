# 303. Range Sum Query - Immutable

## Improved Code

```text
303_range_sum_query_immutable_v1
```

---

## What am I solving?

In this problem, I am solving the **range sum query** problem.

Given an integer array or vector, the task is to calculate the sum of elements between two indices:

```text
left and right
```

Both `left` and `right` are included in the sum.

Example:

```text
nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) = nums[0] + nums[1] + nums[2]
               = -2 + 0 + 3
               = 1
```

So the main goal is to answer queries like:

```text
What is the sum from index left to index right?
```

---

## Why am I solving it?

I am solving this problem to understand the basic idea of **range queries**.

This problem is also useful for learning the **prefix sum pattern**, because of the brute-force approach in currect version it helps me understand why an optimized prefix sum solution is needed later.

In this version, I am intentionally keeping the solution brute-force so that I can clearly understand:

```text
1. How range sum works
2. How multiple queries are handled
3. Why repeated summation can become expensive
4. Why prefix sum improves the solution
```

This version is part of my step-by-step learning process.

---

## How does the solution work?

The `NumArray` class stores the input vector inside the object.

The method:

```cpp
sumRange(left, right)
```

takes two indices as input.

Then it loops from `left` to `right` and adds each element one by one.

Example:

```text
nums = [-2, 0, 3, -5, 2, -1]

sumRange(2, 5)
= nums[2] + nums[3] + nums[4] + nums[5]
= 3 + (-5) + 2 + (-1)
= -1
```

So the solution directly calculates the sum for every query.

This is why it is a **brute-force solution**.

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

## Real-Life Use Cases

Range sum queries can appear in many real-life systems, such as:

```text
bank transaction summaries, monthly expense tracking, sales reports, website visitor analytics, inventory tracking, electricity usage calculation, student marks analysis, fitness progress tracking, stock price analysis, sensor data monitoring
```

For example, a banking app may need to answer:

```text
How much money did the user spend between day 5 and day 20?
```

A website analytics dashboard may need to answer:

```text
How many visitors came between Monday and Friday?
```

A sales system may need to answer:

```text
What was the total revenue between two selected dates?
```

---

## Real-Life Data Science Use Case / Implications

In Data Science, range sum queries are useful when working with ordered data or time-series data.

Examples include:

```text
daily sales data, stock prices, user activity logs, temperature readings, financial transactions, website traffic, sensor measurements
```

A data scientist may need to calculate:

```text
total sales over a date range
total website visits over a week
total rainfall between two months
total energy consumption during a time window
total number of events in a log range
```


The brute-force approach works for small data, but for large datasets and many queries, it can become slow. That is why this problem naturally leads to the optimized **prefix sum** approach.

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

## Current Limitation

This version is still brute-force.

For every query, it loops from `left` to `right` again.

So if there are many queries, the solution can become slow.

This limitation will be improved in the next version using the **prefix sum** approach.

---

## Summary

This version helps me understand the brute-force range sum query approach clearly.

It includes:

```text
1. Class-based implementation
2. User input for local testing
3. Constraint validation
4. Multiple range queries
5. Brute-force range sum calculation
6. A clear space-time trade-off decision
```

This version is mainly for learning and documentation before moving to the optimized prefix sum solution.