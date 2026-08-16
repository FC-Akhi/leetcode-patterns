# Contiguous Array

## 2nd Optimized Code

```text
contiguous_array_v3.cpp
```

---

## Improvements in This Version
1. Unit testing has been incorporated
2. Prefix sum has been improved from O(n^2) to O(n)
3. `std::map` is replaced by `std::unordered_map`. Thus complexity improved.

---

## Complexity Analysis
### Time Complexity

The solution goes through the input array a few times.

First, it creates the balance array.

```text
0 becomes -1
1 becomes +1
```

This takes:

```text
O(n)
```

Then it creates the prefix sum array.

This also takes:

```text
O(n)
```

After that, it stores each prefix sum value and its index in an `unordered_map`.

This takes:

```text
O(n)
```

Finally, it checks the stored prefix sum values to calculate the maximum balanced subarray length.

This also takes:

```text
O(n)
```

So the total time complexity is:

```text
O(n) + O(n) + O(n) + O(n)
```

Which becomes:

```text
O(n)
```

So the final time complexity is:

```text
Average Time Complexity: O(n)
```

The word **average** is used because `unordered_map` usually gives constant-time access, but in rare worst cases it can be slower.

---

### Space Complexity

The solution uses extra space for:

```text
balance_array
prefix_sum array
unordered_map
```

The `balance_array` stores `n` values.

The `prefix_sum` array stores `n + 1` values.

The `unordered_map` stores prefix sum values and their indices.

So the total extra space grows with the input size.

Therefore, the space complexity is:

```text
O(n)
```
---

# Limitations of the Current Implementation
- Hash map could be improved. Because we use the last and first indices of the values vector. Numbers in between are not in use (An element for thinking...)