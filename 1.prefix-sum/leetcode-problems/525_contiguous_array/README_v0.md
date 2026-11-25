# Contiguous Array

## Bruteforce Code

```text
contiguous_array_v0.cpp
```
---

## What am I solving?

In this problem, I am solving the **contiguous array** problem.

Given a binary array or vector containing only `0`s and `1`s, the task is to find the maximum length of a contiguous subarray that contains an equal number of `0`s and `1`s.

A contiguous subarray means the elements must be taken continuously without skipping any index.

Example:

```text
nums = [0, 0, 1, 0, 1, 1]
```

One valid contiguous subarray is:

```text
[0, 0, 1, 0, 1, 1]
```

This subarray contains:

```text
number of 0s = 3
number of 1s = 3
```

So this subarray has an equal number of `0`s and `1`s.

The length of this subarray is:

```text
6
```

So the main goal is to answer:

```text
What is the maximum length of a contiguous subarray where the number of 0s and 1s are equal?
```
---
## Why am I solving it?

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
# Code Structure
## Expected Class

LeetCode expects a class named:

```cpp
Solution
```

---

## Method

The method name must be:

```cpp
findMaxLength
```

It receives one input:

```cpp
std::vector<int>& nums
```

Example:

```cpp
int findMaxLength(std::vector<int>& nums)
```

This method must return the maximum length of a contiguous subarray that contains an equal number of `0`s and `1`s.

Example:

```text
nums = [0, 0, 1, 0, 1, 1]
```

The whole array contains:

```text
number of 0s = 3
number of 1s = 3
```

So the method should return:

```text
6
```

---

## Given Constraints

* `1 <= nums.length <= 10^5`

This means the input array will have at least `1` element and at most `100,000` elements.

* `nums[i]` is either `0` or `1`

This means every value inside the array is binary. Each element can only be `0` or `1`.

---
## How does the solution work?

The goal of the problem is to find the maximum length of a contiguous subarray that contains an equal number of `0`s and `1`s.

---

## Main Idea

Counting `0`s and `1`s separately for every subarray can become confusing. So this solution first converts the original binary array into a **balance array**.

The conversion rule is:

```text
0 becomes -1
1 becomes +1
```

For example:

```text
nums = [0, 0, 1, 0, 1, 1]
```

After conversion:

```text
balance_array = [-1, -1, +1, -1, +1, +1]
```

Now the problem becomes easier:

```text
If the sum of a subarray in balance_array is 0,
then that subarray has an equal number of 0s and 1s in the original array.
```

Why?

Because every `0` contributes `-1`, and every `1` contributes `+1`.

So when the total sum becomes `0`, it means the `-1`s and `+1`s cancelled each other.

That means:

```text
number of 0s == number of 1s
```

---

## Step-by-Step Explanation
### Step 1: Create the balance array

```cpp
std::vector<int> balance_array(n);
```

This vector stores the converted values.

Each `0` from `nums` becomes `-1`.

Each `1` from `nums` becomes `+1`.

```cpp
for(int i = 0; i < n; i++) {
    if (nums[i] == 0) 
        balance_array[i] = -1;
    else
        balance_array[i] = 1;
}
```

Example:

```text
nums          = [0, 0, 1, 0, 1, 1]
balance_array = [-1, -1, 1, -1, 1, 1]
```

---

### Step 2: Declare helper variables

```cpp
int sum = 0;
int length = 0;
int max_length = 0;
std::vector<int> numbers;
```

Here:

```text
sum        = stores the running sum of the current subarray
length     = stores the length of the current balanced subarray
max_length = stores the maximum balanced subarray length found so far
numbers    = stores the current subarray values from the balance array
```

---

### Step 3: Try every possible starting index

```cpp
for (int i = 0; i < n - 1; i++) {
```

This outer loop selects the starting index of a subarray.

For each starting index `i`, the program starts a new subarray.

```cpp
sum = balance_array[i];
numbers.push_back(balance_array[i]);
```

This means the current subarray starts with `balance_array[i]`.

---

### Step 4: Expand the subarray one element at a time

```cpp
for (int j = i+1; j < n; j++) {
```

This inner loop expands the subarray from index `i` to index `j`.

Each time a new element is added:

```cpp
sum = sum + balance_array[j];
numbers.push_back(balance_array[j]);
```

The running sum is updated, and the current element is added to the `numbers` vector.

---

### Step 5: Check if the current subarray is balanced

```cpp
if(sum == 0) {
```

If `sum` becomes `0`, it means the current subarray contains an equal number of `0`s and `1`s.

Then the length of the current subarray is calculated:

```cpp
length = numbers.size();
```

If this length is greater than the previous maximum length, update `max_length`.

```cpp
if (max_length < length)
    max_length = length;
```

---

### Step 6: Clear the current subarray before the next start index

```cpp
numbers.clear();
```

After checking all subarrays starting from index `i`, the `numbers` vector is cleared.

Then the outer loop moves to the next starting index.

---

## Example Dry Run

Given:

```text
nums = [0, 0, 1, 0, 1, 1]
```

Convert it into balance values:

```text
balance_array = [-1, -1, +1, -1, +1, +1]
```

Now check subarrays.

One possible subarray is the whole array:

```text
[-1, -1, +1, -1, +1, +1]
```

Its sum is:

```text
-1 + -1 + 1 + -1 + 1 + 1 = 0
```

Because the sum is `0`, the original subarray has equal number of `0`s and `1`s.

Original subarray:

```text
[0, 0, 1, 0, 1, 1]
```

Count:

```text
number of 0s = 3
number of 1s = 3
```

So this is a valid balanced subarray.

Its length is:

```text
6
```

Therefore, the answer is:

```text
6
```

---

## Why This Is a Brute-Force Solution

This solution is brute force because it checks many possible contiguous subarrays.

The outer loop chooses the starting index.

The inner loop expands the subarray until the end of the array.

So the program tries subarrays like:

```text
start at index 0 -> check subarrays ending at 1, 2, 3, ...
start at index 1 -> check subarrays ending at 2, 3, 4, ...
start at index 2 -> check subarrays ending at 3, 4, 5, ...
```

For each subarray, it checks whether the running sum is `0`.

---

## Time Complexity

The balance array creation takes `O(n)` time.

After that, the solution uses nested loops to check possible contiguous subarrays.

The outer loop runs almost `n` times.

For each starting index `i`, the inner loop checks the possible ending indices `j`.

The inner loop runs like this:

```text
when i = 0, inner loop runs (n - 1) times
when i = 1, inner loop runs (n - 2) times
when i = 2, inner loop runs (n - 3) times
...
when i = n - 2, inner loop runs 1 time
```

So the total number of inner loop executions is:

```text
(n - 1) + (n - 2) + (n - 3) + ... + 1
```

This is approximately:

```text
n(n - 1) / 2
```

For Big-O notation, we ignore constants and smaller terms.

So the time complexity is:

```text
O(n²)
```


---

## Space Complexity

This solution uses:

```text
nums          -> O(n)
balance_array -> O(n)
numbers       -> O(n)
```

So the space complexity is:

```text
O(n)
```

---
# Limitations of the Current Implementation
- This is a brute-force solution

- Not all constraints are covered
- No user input for input array (static input code)
- Extra space of O(n) for `numbers` required to save the sub-arrays
- The code does not use prefix sum preprocessing.
- Each findMaxLength call takes O(n²) time in the worst case.


---

# Next possible Optimized code

```contiguous_array_v1``` -- Optimized Bruteforce Code
- All constraints are covered
- Take user input for input array(limited for local test code)
- Reduce extra space consumption
- Write separate method for task which are seperable from main method `findMaxLength`

```contiguous_array_v2``` -- Optimized Code 
- The code use prefix sum preprocessing.
- Use Hash map

```contiguous_array_v3``` -- Further Optimized Code 
- Improve of prefix sum preprocessing further 
- Improve std::map
- Set unit tester

```contiguous_array_v4``` -- Production Grade Code
- Write production grade code with header, library and shell code.