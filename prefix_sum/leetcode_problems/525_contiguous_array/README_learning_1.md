# Understanding `std::map<int, std::vector<int>>`

## Code Section

```cpp
std::map<int, std::vector<int>> map_value_indices;

for(int i = 0; i < n + 1; i++) {
    map_value_indices[prefix_sum[i]].push_back(i);
}
```

This part of the code stores all indices where each prefix sum value appears.

It is used in the **Contiguous Array** problem to find the longest subarray with an equal number of `0`s and `1`s.

---

## What Does This Line Mean?

```cpp
std::map<int, std::vector<int>> map_value_indices;
```

This line creates a map named:

```cpp
map_value_indices
```

The map stores data in key-value form.

The general structure of a map is:

```cpp
std::map<key_type, value_type> map_name;
```

In this code:

```cpp
std::map<int, std::vector<int>> map_value_indices;
```

means:

* The key type is `int`.
* The value type is `std::vector<int>`.
* The map name is `map_value_indices`.

So the structure is:

```text
int -> vector<int>
```

In this problem, it means:

```text
prefix_sum_value -> list of indices where this prefix_sum_value appeared
```

---

## Meaning in This Problem

The map stores:

```text
key   = prefix sum value
value = all indices where that prefix sum value appears
```

Example:

```text
-1 -> [1, 3]
 0 -> [0, 2, 4]
```

This means:

* Prefix sum `-1` appeared at indices `1` and `3`.
* Prefix sum `0` appeared at indices `0`, `2`, and `4`.

---

## Empty Map at the Beginning

At first, after this line:

```cpp
std::map<int, std::vector<int>> map_value_indices;
```

the map is empty.

```text
map_value_indices = { }
```

There are no keys and no vectors yet.

---

## What Does This Line Do?

```cpp
map_value_indices[prefix_sum[i]].push_back(i);
```

This line stores the current index `i` under the current prefix sum value.

It can be read as:

```text
Use prefix_sum[i] as the key.
Find the vector stored for that key.
Push the current index i into that vector.
```

So this line groups indices by prefix sum value.

---

## Breaking the Line into Two Parts

The line is:

```cpp
map_value_indices[prefix_sum[i]].push_back(i);
```

### Part 1

```cpp
map_value_indices[prefix_sum[i]]
```

This means:

```text
Go to the map and access the vector for the key prefix_sum[i].
```

Here, `prefix_sum[i]` is used as the key.

### Part 2

```cpp
.push_back(i)
```

This means:

```text
Add the current index i to that vector.
```

So the complete meaning is:

```text
For the current prefix sum value, store the current index in its list of indices.
```

---

## Important Behavior of `map[key]`

When we write:

```cpp
map_value_indices[prefix_sum[i]]
```

C++ checks whether this key already exists in the map.

### Case 1: Key already exists

If the key already exists, C++ uses the existing vector.

Example:

```text
0 -> [0, 2]
```

If we run:

```cpp
map_value_indices[0].push_back(4);
```

then the vector becomes:

```text
0 -> [0, 2, 4]
```

### Case 2: Key does not exist

If the key does not exist, C++ automatically creates a new empty vector for that key.

Example:

```cpp
map_value_indices[-1].push_back(1);
```

If key `-1` does not exist yet, C++ first creates:

```text
-1 -> [ ]
```

Then it pushes `1` into the vector:

```text
-1 -> [1]
```

---

## Example Prefix Sum Array

Suppose the prefix sum array is:

```cpp
prefix_sum = {0, -1, 0, -1, 0};
```

Index positions:

```text
index:       0   1   2   3   4
prefix_sum:  0  -1   0  -1   0
```

Now the loop runs:

```cpp
for(int i = 0; i < n + 1; i++) {
    map_value_indices[prefix_sum[i]].push_back(i);
}
```

The loop stores each index under its prefix sum value.

---

## Step-by-Step Visualization

### Before the Loop

```text
map_value_indices = { }
```

The map is empty.

---

### Step 1

```text
i = 0
prefix_sum[i] = prefix_sum[0] = 0
```

The line becomes:

```cpp
map_value_indices[0].push_back(0);
```

Key `0` does not exist yet.

So C++ creates a new empty vector for key `0`:

```text
0 -> [ ]
```

Then it pushes index `0`:

```text
0 -> [0]
```

Map now:

```text
{
  0 -> [0]
}
```

---

### Step 2

```text
i = 1
prefix_sum[i] = prefix_sum[1] = -1
```

The line becomes:

```cpp
map_value_indices[-1].push_back(1);
```

Key `-1` does not exist yet.

So C++ creates a new empty vector for key `-1`:

```text
-1 -> [ ]
```

Then it pushes index `1`:

```text
-1 -> [1]
```

Map now:

```text
{
 -1 -> [1]
  0 -> [0]
}
```

Because `std::map` keeps keys sorted, key `-1` appears before key `0`.

---

### Step 3

```text
i = 2
prefix_sum[i] = prefix_sum[2] = 0
```

The line becomes:

```cpp
map_value_indices[0].push_back(2);
```

Key `0` already exists.

Current value for key `0`:

```text
0 -> [0]
```

Now index `2` is pushed into that vector:

```text
0 -> [0, 2]
```

Map now:

```text
{
 -1 -> [1]
  0 -> [0, 2]
}
```

---

### Step 4

```text
i = 3
prefix_sum[i] = prefix_sum[3] = -1
```

The line becomes:

```cpp
map_value_indices[-1].push_back(3);
```

Key `-1` already exists.

Current value for key `-1`:

```text
-1 -> [1]
```

Now index `3` is pushed into that vector:

```text
-1 -> [1, 3]
```

Map now:

```text
{
 -1 -> [1, 3]
  0 -> [0, 2]
}
```

---

### Step 5

```text
i = 4
prefix_sum[i] = prefix_sum[4] = 0
```

The line becomes:

```cpp
map_value_indices[0].push_back(4);
```

Key `0` already exists.

Current value for key `0`:

```text
0 -> [0, 2]
```

Now index `4` is pushed into that vector:

```text
0 -> [0, 2, 4]
```

Final map:

```text
{
 -1 -> [1, 3]
  0 -> [0, 2, 4]
}
```

---

## Final Map Visualization

Given:

```cpp
prefix_sum = {0, -1, 0, -1, 0};
```

The final map becomes:

```text
map_value_indices:

key -1  --->  [1, 3]

key  0  --->  [0, 2, 4]
```

This means:

```text
prefix sum -1 appeared at index 1 and index 3
prefix sum 0 appeared at index 0, index 2, and index 4
```

---

## Trace Table

| Loop index `i` | `prefix_sum[i]` | Code effect                  | Map after operation              |
| -------------: | --------------: | ---------------------------- | -------------------------------- |
|              0 |               0 | Add index `0` under key `0`  | `0 -> [0]`                       |
|              1 |              -1 | Add index `1` under key `-1` | `-1 -> [1]`, `0 -> [0]`          |
|              2 |               0 | Add index `2` under key `0`  | `-1 -> [1]`, `0 -> [0, 2]`       |
|              3 |              -1 | Add index `3` under key `-1` | `-1 -> [1, 3]`, `0 -> [0, 2]`    |
|              4 |               0 | Add index `4` under key `0`  | `-1 -> [1, 3]`, `0 -> [0, 2, 4]` |

---

## Why This Is Useful

This map helps us find repeated prefix sum values.

If the same prefix sum appears at two different indices, then the subarray between those two indices has sum `0`.

In this problem:

```text
0 is converted to -1
1 is converted to +1
```

So a subarray sum of `0` means:

```text
number of 0s == number of 1s
```

That means the subarray is balanced.

---

## Example Using the Final Map

Final map:

```text
-1 -> [1, 3]
 0 -> [0, 2, 4]
```

For key `0`:

```text
first index = 0
last index  = 4
```

Length:

```text
4 - 0 = 4
```

So there is a balanced subarray of length `4`.

For key `-1`:

```text
first index = 1
last index  = 3
```

Length:

```text
3 - 1 = 2
```

So there is a balanced subarray of length `2`.

The maximum length is:

```text
4
```

---

## One-Line Summary

This line:

```cpp
map_value_indices[prefix_sum[i]].push_back(i);
```

means:

```text
Take the current prefix sum value, use it as a key in the map, and store the current index i inside that key's vector.
```

So the map groups all prefix sum indices together.

---

## Key Concept to Remember

```cpp
std::map<int, std::vector<int>>
```

means:

```text
One integer key can store multiple integer values.
```

In this problem:

```text
One prefix sum value can appear at multiple indices.
```

That is why the value type is:

```cpp
std::vector<int>
```

instead of just:

```cpp
int
```

---

## Relation to the Contiguous Array Problem

The full logic is:

```text
When the same prefix sum appears at two prefix indices, it means the balance values added between those two prefix boundaries sum to 0. Since 0 is represented as -1 and 1 is represented as +1, that corresponding range in the original nums array contains an equal number of 0s and 1s.
```
For a detailed index-by-index explanation of how prefix positions map back to nums indices, see: 
[Detailed Prefix Sum Boundary Explanation](README_v0.md)

