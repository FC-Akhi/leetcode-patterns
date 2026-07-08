# Contiguous Array

## 1st Optimized Code

```text
contiguous_array_v2.cpp
```
---
## How does the solution work?

This version solves **LeetCode 525: Contiguous Array** using a balance array, prefix sum, and a map.

The main idea is to convert the binary array into a balance array.

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

Now the problem becomes a sum problem.

If a subarray has sum `0`, then it means the number of `-1`s and `+1`s are equal. So the original subarray contains an equal number of `0`s and `1`s.

After creating the balance array, this solution builds a prefix sum array.

Example:

```text
balance_array = [-1, -1, +1, -1, +1, +1]

prefix_sum = [0, -1, -2, -1, -2, -1, 0]
```

The first value of `prefix_sum` is `0` because before taking any element, the total balance is `0`. It is a part of algorithm i am using

The important observation is:

```text
If the same prefix sum appears at two different indices,
then the subarray between those two prefix positions has sum 0.
```

That means the corresponding subarray has an equal number of `0`s and `1`s.

To use this idea, the solution stores each prefix sum value and all the indices where that value appears.

Example:

```text
prefix sum value -> indices

0  -> [0, 6]
-1 -> [1, 3, 5]
-2 -> [2, 4]
```

For each prefix sum value, the solution takes:

```text
first index
last index
```

Then it calculates:

```text
length = last index - first index
```

This gives the longest balanced subarray for that prefix sum value.

Finally, the solution returns the maximum length found.

---

## Improvements in This Version

Compared to the previous brute-force version, this version improves the idea by using prefix sum and storing repeated prefix sum values.

Main improvements:

* The code builds a prefix sum array from the balance array.
* The code stores prefix sum values with their corresponding indices.
* The code uses repeated prefix sum values to detect balanced subarrays.
* The code avoids directly checking every possible subarray using the previous nested subarray-expansion logic.

Important note:

This version uses `std::map`, not a hash map.

```cpp
std::map<int, std::vector<int>> map_value_indices;
```

`std::map` is an ordered map. It usually uses a balanced binary search tree internally.

So the map operation costs:

```text
O(log n)
```

If I want to use a real hash map, I should use:

```cpp
std::unordered_map
```

So for this current version, the correct wording is:

```text
This version uses prefix sum and std::map.
```

---

## Complexity Analysis
### Time Complexity

Creating the balance array takes:

```text
O(n)
```

The current `getPrefixSum()` function builds the prefix sum using nested loops.

For each index `i`, it again loops from the beginning up to `i`.

So the total work is:

```text
1 + 2 + 3 + ... + n
```

This becomes:

```text
O(n²)
```

After that, the code stores prefix sum values in a `std::map`.

There are `n + 1` prefix sum values.

Each insertion/access in `std::map` takes:

```text
O(log n)
```

So the map-building part takes:

```text
O(n log n)
```

Then the code iterates over the map to find the first and last index for each prefix sum value.

In the worst case, this takes:

```text
O(n)
```

So the total time complexity is:

```text
O(n²) + O(n log n) + O(n)
```

The largest term is `O(n²)`.

Therefore, the final time complexity of this current implementation is:

```text
O(n²)
```

---

### Space Complexity

This solution uses extra space for:

```text
balance_array
prefix_sum
map_value_indices
```

The `balance_array` stores `n` values.

So it takes:

```text
O(n)
```

The `prefix_sum` array stores `n + 1` values.

So it also takes:

```text
O(n)
```

The map stores prefix sum values and their indices.

In the worst case, it can store up to `n + 1` indices.

So it takes:

```text
O(n)
```

Therefore, the total space complexity is:

```text
O(n)
```

---

# Limitations of the Current Implementation

- The prefix sum construction is not fully optimized yet. The current `getPrefixSum()` function uses nested loops, so it takes `O(n²)` time.
- The code uses `std::map`, not `std::unordered_map`. Because of that, each map access takes `O(log n)` time.
- This version stores all indices for each prefix sum value. However, to find the maximum length, we only need to remember the first occurrence of each prefix sum value. So the memory usage can be improved.
