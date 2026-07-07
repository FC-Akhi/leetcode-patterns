# Contiguous Array
## Bruteforce Code

```text
contiguous_array_v1.cpp
```
---


## What Am I Solving?

This code solves **LeetCode 525: Contiguous Array**.

The problem asks:

```text
Given a binary array nums, find the maximum length of a contiguous subarray
that contains an equal number of 0s and 1s.
```

Example:

```cpp
nums = {0, 0, 1, 0, 1, 1}
```

One valid longest balanced subarray is:

```text
{0, 0, 1, 0, 1, 1}
```

It contains:

```text
three 0s
three 1s
```

So the answer is:

```text
6
```

---

## Why Am I Solving It?

I am solving **LeetCode 525: Contiguous Array** to understand how a real-world balanced-condition problem can be converted into a programming problem.

This problem is not only about finding equal numbers of `0`s and `1`s in an array. The deeper idea is learning how to handle two opposite categories and find the longest continuous range where both categories are balanced.

A real-life example is **load balancer request log analysis**.

Suppose a system has two backend servers:

```text
0 = request sent to Server A
1 = request sent to Server B
```

A request log may look like this:

```text
requests = [0, 0, 1, 0, 1, 1]
```

The engineering question can be:

```text
During what longest continuous period was the traffic perfectly balanced between the two servers?
```

This is the same structure as LeetCode 525.

In LeetCode terms:

```text
0 = one category
1 = another category
```

In the load-balancer example:

```text
0 = Server A
1 = Server B
```

So the task becomes:

```text
Find the longest contiguous request window where:
number of Server A requests == number of Server B requests
```

To solve this efficiently, we can convert the two categories into balance values:

```text
Server A -> -1
Server B -> +1
```

Then a window with total balance `0` means both servers received the same number of requests.


This same idea can be used in many other areas, such as system logs, A/B testing logs, success/failure events, profit/loss records, and other binary event streams.

---

## Complexity Analysis

### Time Complexity

The solution uses two nested loops:

```cpp
for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
        ...
    }
}
```

The outer loop chooses the starting index.

The inner loop expands the ending index.

So the solution checks many possible subarrays.

The number of checked subarrays is approximately:

```text
n + (n - 1) + (n - 2) + ... + 1
```

This becomes:

```text
O(n^2)
```

So the time complexity is:

```text
O(n^2)
```

---

### Space Complexity

The code creates:

```cpp
std::vector<int> balance_array(n);
```

This takes:

```text
O(n)
```

The code also creates:

```cpp
std::vector<int> numbers;
```

In the worst case, this can store up to `n` values.

So it also takes:

```text
O(n)
```

Total space complexity:

```text
O(n)
```

---

## Current Version Summary

```text
Problem: LeetCode 525 - Contiguous Array
Approach: Brute-force style solution
Main technique: Convert 0 to -1 and 1 to +1
Balanced condition: subarray sum == 0
Time Complexity: O(n^2)
Space Complexity: O(n)
```
---

## Future Improvement

This brute-force version is useful for understanding the problem.

Later, this solution can be improved using:

```text
prefix sum + map/hash map
```

The optimized idea is:

```text
If the same prefix sum appears again, the elements between those two prefix positions have total balance 0.
```

That optimized approach can reduce the time complexity from:

```text
O(n^2)
```

to:

```text
O(n)
```

when using `unordered_map`, or:

```text
O(n log n)
```

when using `std::map`.
