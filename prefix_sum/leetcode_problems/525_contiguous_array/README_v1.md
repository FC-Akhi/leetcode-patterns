# Contiguous Array

## Optimized Bruteforce Code

```text
contiguous_array_v1.cpp
```
---

## Improvements in This Version
In this improved version, I focused on making the code better for local testing and learning.

### 1. Constraint validation added
The code validates the input size based on the given constraint:

```text
1 <= nums.length <= 10^5
```

It also validates each element based on the constraint:

```text
0 <= nums[i] <= 1 Note: the nums is the int type vector
```

### 2. User input added for local testing
This version takes user input for:

```text
1. Vector size
2. Vector elements
```

This is not required by LeetCode, but it is useful for local testing and learning.

LeetCode automatically handles input internally, but this local version helps me understand how the class works with manual input.

### 3. Design decision about extra space
In the previous version, I used an extra vector in method `findMaxLength` to store the current subarray. And then used its size to calculate the length. In this version, I removed that extra vector and replaced it with constant-time expression `j - i + 1`.


### 4. Method getBalanceArray
Extract the balance array calculation from `findMaxLength` and make new method. Both `findMaxLength` and `getBalanceArray` is not having single responsibility. 

---

## Complexity Analysis
### Time Complexity
Let:

```text
n = size of the input vector
```
Still time complexity is 
O(n²)

### Space Complexity
- nums          -> O(n)
- balance_array -> O(n)

So the space complexity is:

```text
O(n)
```
---

# Limitations of the Current Implementation
- This version is still brute-force.
- Time complexity is O(n²)

This limitation will be improved in the next version using the **prefix sum** approach and hash map.