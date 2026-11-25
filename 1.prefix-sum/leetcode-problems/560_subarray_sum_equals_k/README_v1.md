# Subarray Sum Equals K

## 1st Optimized Bruteforce Code

```text
subarray_sum_equals_k_v1.cpp
```
---

## Improvements in This Version
- Space Efficiency - Eliminates storage of all subarrays. Takes 
O(1) space (only constant extra variables)
- No Unnecessary Data Structure - Removes the `std::map` overhead
- On-the-Fly Calculation - Computes sum immediately instead of storing subarrays 
then checking
- Single Pass Logic - sum of subarrays Counts matches within the main loop
- Reduced Memory Allocations - No repeated push_back() operations
- Cleaner Code - Fewer variables and simpler logic

---

## Complexity Analysis
### Time Complexity
- Still O(n^3)

### Space Complexity
- O(n)


---

# Limitations of the Current Implementation

- No use of prefix sum array.
- No use of hash map to store previous prefix sums.
- Time complexity is `O(n^3)`.
- The code checks all possible contiguous subarrays.
- For each selected subarray, the code recalculates the sum from scratch.
