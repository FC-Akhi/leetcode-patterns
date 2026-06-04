# How LeetCode Expects the Code
- For this problem, LeetCode expects only the `NumArray` class.
- We do not need to write the `main()` function.
- We do not need to take input using `cin` or `scanf`.
- We do not need to print output using `cout` or `printf`.

LeetCode will automatically create the object and call the methods.

---

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

The constructor receives the input array.

In C++, LeetCode usually gives the input as:

```cpp
vector<int>& nums
```

The constructor is used to initialize the object.

Example:

```cpp
NumArray(vector<int>& nums)
```

This means:

```text
Create a NumArray object using the given nums array.
```

### What is vector? 
### why use vector in comparison to the Static and dynamic array and Linked list?
```Check README_arr_ll_vec.md```

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

## What LeetCode Handles Automatically

LeetCode handles this part automatically:

```text
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
```

We do not need to parse this input manually.

LeetCode will internally do something like:

```cpp
NumArray numArray(nums);
// these are differnet queries!!!
numArray.sumRange(0, 2);
numArray.sumRange(2, 5);
numArray.sumRange(0, 5);
```

---

## Important Point

The constructor does not return anything.

That is why the first output is:

```text
null
```

The `sumRange()` method returns integer values.

That is why the final output is:

```text
[null, 1, -1, -3]
```
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

## Summary
For LeetCode, we only write:

```text
1. The NumArray class
2. The constructor
3. The sumRange method
```

We do not write:

```text
1. main function
2. input code
3. output code
4. manual test cases
```

---

# Time and Space Complexity of the code
## Time Complexity
- Constructor: O(n), because this->nums = nums copies the whole n size vector
- sumRange: O(right - left + 1), worst case O(n)
- If there m queries then for sumRange of O(n), time complexity will be O(n*m)

## Space Complexity
- Extra space: O(n), because the object stores a copy of input vector nums

---

# Limitations of the code
- This is a brute-force solution for range sum queries

- Not all constraints are covered
- No user input for input array or the range (limitation for local test code)
- Require O(n) copies from input vector to object vector
- Extra space of O(n) required to have copy of input vector inside object
- Each sumRange call takes O(n) time in the worst case. For m queries, 
the total worst-case time is O(n * m)
- The code does not use prefix sum preprocessing.


---

# Improved codes

```303_range_sum_query_immutable_v1```
- Not all constraints are covered
- No user input for input array or the range (limitation for local test code)

```303_range_sum_query_immutable_v2```
- Require O(n) copies from input vector to object vector
- Extra space of O(n) required to have copy of input vector inside object

```303_range_sum_query_immutable_v3```
- Each sumRange call takes O(n) time in the worst case. For m queries, 
the total worst-case time is O(n * m)
- The code does not use prefix sum preprocessing.

```303_range_sum_query_immutable_v4```
- Improve of prefix sum processing