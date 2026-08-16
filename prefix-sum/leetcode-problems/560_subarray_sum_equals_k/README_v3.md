# Subarray Sum Equals K

## 2nd Optimized Code with using prefix sum and hashmap idea

```text
subarray_sum_equals_k_v3.cpp
```

---
## How does the solution work?

This solution solves **LeetCode 560: Subarray Sum Equals K** using a **prefix sum array** and a **hash map**.

The goal is to count how many contiguous subarrays have a sum equal to `k`.

The main idea is:

```text
currentPrefix - previousPrefix = k
```

So:

```text
previousPrefix = currentPrefix - k
```

That means for every current prefix sum, we need to check whether the required previous prefix sum appeared before.

---

### Step 1: Build the prefix sum array

The helper function `getPrefixSumArray()` creates a prefix sum array.

```cpp
std::vector<int> getPrefixSumArray(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> prefixSum(n);

    prefixSum[0] = nums[0];

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    return prefixSum;
}
```

For example:

```text
nums = [1, 2, 1, 2]
```

The prefix sum array becomes:

```text
prefixSum = [1, 3, 4, 6]
```

Meaning:

```text
prefixSum[0] = 1
prefixSum[1] = 1 + 2 = 3
prefixSum[2] = 1 + 2 + 1 = 4
prefixSum[3] = 1 + 2 + 1 + 2 = 6
```

Each prefix sum represents the total sum from the beginning of the array up to the current index.

---

### Step 2: Use a hash map to store previous prefix sums

The hash map stores how many times each prefix sum has appeared before.

```cpp
std::unordered_map<int, int> prefix_count;
```

The map stores:

```text
key   = prefix sum value
value = how many times this prefix sum appeared before
```

Example:

```text
prefix_count[3] = 2
```

means:

```text
Prefix sum 3 appeared two times before.
```

---

### Step 3: Add initial prefix sum 0

Before checking the prefix sum array, the code stores:

```cpp
prefix_count[0] = 1;
```

This means:

```text
Before reading any element, the prefix sum is 0.
```

This is needed to count subarrays that start from index `0`.

Example:

```text
nums = [1, 2]
k = 3
```

Prefix sum at index `1` is:

```text
1 + 2 = 3
```

To count this subarray, we need:

```text
currentPrefix - previousPrefix = k
3 - 0 = 3
```

So the previous prefix sum `0` must already exist in the hash map.

---

### Step 4: Traverse the prefix sum array

The code then loops through every prefix sum:

```cpp
for (int currentPrefix : prefixSum)
```

For each `currentPrefix`, it calculates:

```cpp
int needed = currentPrefix - k;
```

This means:

```text
What previous prefix sum do I need so that the subarray sum becomes k?
```

Because:

```text
currentPrefix - previousPrefix = k
```

So:

```text
previousPrefix = currentPrefix - k
```

---

### Step 5: Check whether the needed prefix sum exists

The code checks:

```cpp
if (prefix_count.find(needed) != prefix_count.end()) {
    count += prefix_count[needed];
}
```

This means:

```text
If the needed previous prefix sum appeared before,
then a valid subarray exists.
```

If the needed prefix sum appeared multiple times, then each occurrence creates a different valid subarray.

That is why the code uses:

```cpp
count += prefix_count[needed];
```

not just:

```cpp
count++;
```

---

### Step 6: Store the current prefix sum

After checking, the current prefix sum is stored in the hash map:

```cpp
prefix_count[currentPrefix]++;
```

This means:

```text
This current prefix sum can be used as a previous prefix sum for future subarrays.
```

---

### Example Dry Run

Given:

```text
nums = [1, 2, 1, 2]
k = 3
```

Prefix sum array:

```text
prefixSum = [1, 3, 4, 6]
```

Initial state:

```text
prefix_count = { 0: 1 }
count = 0
```

Now traverse `prefixSum`.

#### currentPrefix = 1

```text
needed = 1 - 3 = -2
```

`-2` is not in the map.

Store current prefix:

```text
prefix_count = { 0: 1, 1: 1 }
count = 0
```

#### currentPrefix = 3

```text
needed = 3 - 3 = 0
```

`0` exists in the map.

```text
count += prefix_count[0]
count = 1
```

This finds:

```text
[1, 2]
```

Store current prefix:

```text
prefix_count = { 0: 1, 1: 1, 3: 1 }
```

#### currentPrefix = 4

```text
needed = 4 - 3 = 1
```

`1` exists in the map.

```text
count += prefix_count[1]
count = 2
```

This finds:

```text
[2, 1]
```

Store current prefix:

```text
prefix_count = { 0: 1, 1: 1, 3: 1, 4: 1 }
```

#### currentPrefix = 6

```text
needed = 6 - 3 = 3
```

`3` exists in the map.

```text
count += prefix_count[3]
count = 3
```

This finds:

```text
[1, 2]
```

Final answer:

```text
3
```

---

### Core Understanding

The prefix sum array gives the sum from the beginning of the array to each index.

The hash map remembers previous prefix sums.

For every current prefix sum, the solution checks whether there is a previous prefix sum that can be removed to make the remaining subarray sum equal to `k`.

So instead of checking every possible subarray manually, the solution uses this relationship:

```text
currentPrefix - previousPrefix = k
```

This is why the solution is faster than brute force.



---

## Improvements in This Version

This version improves the previous brute-force approaches.

Earlier versions checked all possible subarrays directly.

The brute-force version recalculated each subarray sum from scratch, giving:

```text
O(n^3)
```

The improved running-sum version avoided recalculating from scratch, but still checked all possible subarrays, giving:

```text
O(n^2)
```

This version uses a hash map to remember previous prefix sums.

Main improvements:

```text
Uses running prefix sum
Uses hash map frequency counting
Does not check every possible subarray manually
Does not recalculate subarray sums from scratch
Reduces time complexity from O(n^2) to O(n) average
```

The important transformation is:

```text
Instead of asking:
"Try every starting index."

The algorithm asks:
"Have I already seen the prefix sum needed to make the current subarray sum equal to k?"
```

This is why the solution becomes much faster.

---

## Complexity Analysis

### Time Complexity

The code traverses the array once:

```cpp
for (int value : nums)
```

For each element, it does constant-time average operations:

```cpp
int needed = currentPrefix - k;
prefix_count.find(needed);
prefix_count[currentPrefix]++;
```

Since `unordered_map` lookup and insertion are average `O(1)`, each iteration takes average constant time.

Therefore, for `n` elements:

```text
Time Complexity: O(n) average
```

---

### Space Complexity

The hash map stores prefix sum frequencies.

In the worst case, every prefix sum can be different.

For an input array of size `n`, the hash map can store up to `n + 1` prefix sum values, including the initial prefix sum `0`.

So the extra space complexity is:

```text
O(n)
```

The input vector `nums` also takes `O(n)` space, but it is given as input and passed by reference, so the algorithm does not copy it.

Therefore:

```text
Auxiliary Space Complexity: O(n)
Total Space Complexity including input: O(n)
```

---

# Limitations of the Current Implementation

* It uses extra memory for the hash map.
* Space complexity is `O(n)`.
