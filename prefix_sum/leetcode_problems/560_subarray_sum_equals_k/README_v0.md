# Subarray Sum Equals K

## Bruteforce Code

```text
subarray_sum_equals_k_v0.cpp
```
---

## What am I solving?

In this problem, I am solving **LeetCode 560: Subarray Sum Equals K**.

Given an integer array `nums` and an integer `k`, the goal is to count how many contiguous subarrays have a sum equal to `k`.

A contiguous subarray means the elements must be selected continuously without skipping any index.

Example:

```text
nums = [1, 2, 3]
k = 3
```

The valid subarrays are:

```text
[1, 2] = 3
[3] = 3
```

So the total number of subarrays whose sum equals `k` is:

```text
2
```

Therefore, the main goal is to answer:

```text
How many continuous parts of the array add up exactly to k?
```

---
## Why Am I Solving LeetCode 560?

I am solving **LeetCode 560: Subarray Sum Equals K** because it represents a real data-analysis problem:

```text
How many continuous periods of activity reached a specific target value?
```

A real-life use case is **e-commerce traffic and promotion analysis**.

E-commerce platforms track user behavior, purchases, promotions, and revenue. Google Analytics ecommerce tracking, for example, is used to collect shopping behavior data and understand how promotions and product placement influence revenue.

Suppose an online store records visitor counts every 30 minutes:

```text
visitors = [40, 60, 30, 70, 100, 20, 80]
k = 100
```

Here, `k = 100` is not random. It can represent a business threshold found from past data, such as:

```text
When a 30-minute traffic window reaches 100 visitors,
running a flash-sale banner becomes profitable.
```

Now the business question becomes:

```text
How many continuous time windows had exactly 100 visitors?
```

This is the same structure as LeetCode 560:

```text
Given an array nums and a target k,
count how many contiguous subarrays have sum equal to k.
```

Example valid windows:

```text
[40, 60] = 100
[30, 70] = 100
[100] = 100
[20, 80] = 100
```

So the answer is:

```text
4
```

Business meaning:

```text
There are 4 continuous traffic windows where the store reached
the campaign-trigger traffic level.
```

This answer can help the business decide:

```text
When to show flash-sale banners
When to increase ad spending
When to prepare customer support
When to activate promotional offers
```

This kind of promotion analysis is not imaginary. Large e-commerce systems really analyze traffic, promotion behavior, and conversion patterns.

So I am solving this problem because it teaches how to count continuous segments of data that hit an important business target.

The real-world value is not the number alone. The value comes from understanding how often an important threshold appears in continuous data, so a business can make better timing decisions for promotions, ads, support, or operations.



---
# Code Structure

## Expected Class

LeetCode expects a class named:

```cpp
Solution
```

Inside this class, we need one main method:

```text
subarraySum method
```

The local code also has a `main()` function for testing on my own machine, but LeetCode only needs the `Solution` class.

---

## Method

The method name must be:

```cpp
subarraySum
```

It receives two inputs:

```cpp
std::vector<int>& nums
int k
```

Example:

```cpp
int subarraySum(std::vector<int>& nums, int k)
```

This method must return the total number of contiguous subarrays whose sum equals `k`.

Example:

```text
nums = [1, 2, 3]
k = 3
```

Valid subarrays:

```text
[1, 2] = 3
[3] = 3
```

So the method returns:

```text
2
```

---

## Given Constraints

* `1 <= nums.length <= 2 * 10^4`

This means the input array will have at least `1` element and at most `20,000` elements.

* `-1000 <= nums[i] <= 1000`

This means each value inside the array can be from `-1000` to `1000`.

* `-10^7 <= k <= 10^7`

This means the target sum `k` can be a large negative or positive number.

* The subarray must be contiguous and non-empty.

This means the elements must be selected continuously without skipping any index.

For example:

```text
nums = [1, 2, 3]
```

Valid contiguous subarrays are:

```text
[1]
[1, 2]
[1, 2, 3]
[2]
[2, 3]
[3]
```

But this is not a valid subarray:

```text
[1, 3]
```

because index `2` is skipped.

---

## Step-by-Step Explanation

This version uses a brute-force style approach.

The main idea is:

```text
Generate every possible contiguous subarray.
Store each subarray in a map.
Then calculate the sum of each stored subarray.
If the sum equals k, increase the count.
```

### Step 1: Get the size of the input array

```cpp
int n = nums.size();
```

This stores the number of elements in the input vector.

---

### Step 2: Create a unique key for each subarray

```cpp
int l = 0;
```

Here, `l` is used as a unique key for each generated subarray.

Each time a new subarray is generated, `l` is increased by `1`.

---

### Step 3: Create a map to store all subarrays

```cpp
std::map<int, std::vector<int>> hash_map;
```

In this code:

```text
key   = unique subarray number
value = vector containing the elements of that subarray
```

Example:

```text
0 -> [1]
1 -> [1, 2]
2 -> [1, 2, 3]
3 -> [2]
4 -> [2, 3]
5 -> [3]
```

Important note: this is named `hash_map` in the code, but the actual C++ container is `std::map`, not a hash map.

---

### Step 4: Generate all contiguous subarrays

The code uses three nested loops:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        for (int k = i; k <= j; k++) {
            hash_map[l].push_back(nums[k]);
        }
        l += 1;
    }
}
```

The outer loop chooses the starting index of a subarray.

```cpp
for (int i = 0; i < n; i++)
```

The middle loop chooses the ending index of a subarray.

```cpp
for (int j = i; j < n; j++)
```

The inner loop copies the elements from index `i` to index `j` and stores them in the map.

```cpp
for (int k = i; k <= j; k++)
```

Then this line stores the current element inside the current subarray:

```cpp
hash_map[l].push_back(nums[k]);
```

After one subarray is complete, this line moves to the next map key:

```cpp
l += 1;
```

---

### Step 5: Calculate the sum of each stored subarray

```cpp
int sum = 0;
int count = 0;
```

Here:

```text
sum   = stores the sum of the current subarray
count = stores how many subarrays have sum equal to k
```

The code then loops through every subarray stored in the map:

```cpp
for (const auto& pair : hash_map)
```

For each subarray, it adds all values:

```cpp
for (int value : pair.second)
    sum = sum + value;
```

If the sum equals the target `k`, the count is increased:

```cpp
if (sum == k)
    count += 1;
```

Then `sum` is reset before checking the next subarray:

```cpp
sum = 0;
```

---

### Step 6: Return the final count

```cpp
return count;
```

This returns the total number of contiguous subarrays whose sum equals `k`.

---

## Example Dry Run

Given:

```text
nums = [1, 2, 3]
k = 3
```

The code generates all contiguous subarrays:

```text
key 0 -> [1]
key 1 -> [1, 2]
key 2 -> [1, 2, 3]
key 3 -> [2]
key 4 -> [2, 3]
key 5 -> [3]
```

Now it calculates the sum of each subarray:

```text
[1]       sum = 1
[1, 2]    sum = 3
[1, 2, 3] sum = 6
[2]       sum = 2
[2, 3]    sum = 5
[3]       sum = 3
```

The subarrays whose sum equals `k = 3` are:

```text
[1, 2]
[3]
```

So the total count is:

```text
2
```

Therefore, the output is:

```text
2
```


---

## Why This Is a Brute-Force Solution


---

## Time Complexity
O(n³ log n)


---


## Space Complexity
O(n³)


---
# Limitations of the Current Implementation
- This is a brute-force solution
- Not all constraints are covered
- No user input for input array (static input code)
- The code does not use prefix sum preprocessing.
- Each `subarraySum` call takes Time complexity O(n^3 log n)
- Space complexity O(n^3)
---

# Next possible Optimized code

```subarray_sum_equals_k_v1``` -- Optimized Bruteforce Code
- All constraints are covered
- Take user input for input array(limited for local test code)
- Reduce extra space consumption
- Improve time complexity.
- Write separate method for task which are seperable from main method `subarraySum`

```subarray_sum_equals_k_v2``` -- Optimized Code 


```subarray_sum_equals_k_v3``` -- Further Optimized Code 


```subarray_sum_equals_k_v4``` -- Production Grade Code
