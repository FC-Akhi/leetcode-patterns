# Range Sum Query - Immutable

## Bruteforce Code

```text
range_sum_query_immutable_v0
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

I am solving **Range Sum Query - Immutable** because it represents a very common real-life problem

A real-life example is a **sales report dashboard**.

Suppose a shop stores its daily sales like this:

```text
sales = [500, 700, 300, 900, 1000]
```

The sales data is fixed for that report, but people may ask many questions:

```text
Total sales from day 1 to day 3?
Total sales from day 0 to day 4?
Total sales from day 2 to day 4?
```

This is the same idea as the problem.

In the LeetCode problem, we are given an array and many range queries. Each query asks for the sum between two indexes. In real life, those indexes can represent days, hours, months, transaction positions, or log entries.

So by solving this problem, I am practicing how to build a system that can answer repeated range-total questions quickly from fixed data.


# Code Structure
## Expected Class

LeetCode expects a class named:

```cpp
NumArray
```

Inside this class, we need two things:

```text
1. Constructor
2. sumRange method
```

---

## Constructor

The constructor receives the input array as a vector.

```cpp
std::vector<int> nums;
```

The constructor is used to initialize the object.

Example on how to initialize objection:

```cpp
NumArray numArray(nums);
```

This means:

```text
Create a NumArray object using the given nums array.
```

### What is vector? 
### why use vector in comparison to the Static and dynamic array and Linked list?
```README_learning_1.md```

---

## Method

The method name must be:

```cpp
sumRange
```

It receives two inputs:

```cpp
int left
int right
```

Example:

```cpp
int sumRange(int left, int right)
```

This method must return the sum from index `left` to index `right`.

Both `left` and `right` are included.


---

## Given Constraints
- left and right index inclusive; 
This means the given range for example ```numArray.sumRange(0, 2)``` here index
0 and 2 are inclusive. 

- 1 <= nums.length <= 10^4;
This means the input array will have at least 1 element and at most 10,000 elements.

- -10^5 <= nums[i] <= 10^5;
This means each value inside the array can be from -100,000 to 100,000.

- 0 <= left <= right < nums.length
This means: 
    - left and right are valid indexes.
    - left is always less than or equal to right.
    - right is always smaller than the array length.

- At most 10^4 calls will be made to sumRange;
This means LeetCode may call sumRange() up to 10,000 times.



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















# Time and Space Complexity of the code
## Time Complexity
- Constructor: O(n), because this->nums = nums copies the whole n size vector
- sumRange: O(right - left + 1), worst case O(n)
- If there m queries then for sumRange of O(n), time complexity will be O(n*m)

## Space Complexity
- Extra space: O(n), because the object stores a copy of input vector nums

---

# Limitations of the Current Implementation
- This is a brute-force solution for range sum queries

- Not all constraints are covered
- No user input for input array or the range (static input code)
- Extra space of O(n) required to have copy of input vector inside object
- The code does not use prefix sum preprocessing.
- Each sumRange call takes O(n) time in the worst case. For m queries, 
the total worst-case time is O(n * m)


---

# Next possible Optimized code

```range_sum_query_immutable_v1``` -- Optimized Bruteforce Code
- All constraints are covered
- Take user input for input array and the range (limited for local test code)

```range_sum_query_immutable_v2``` -- Optimized Code 
- The code use prefix sum preprocessing.
- Each sumRange call takes O(1) time complexity

```range_sum_query_immutable_v3``` -- Further Optimized Code 
- Improve of prefix sum preprocessing further 

```range_sum_query_immutable_v4``` -- Production Grade Code
- Write production grade code with header, library and shell code.