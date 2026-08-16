# Understanding the Map Iteration Block

## Code Block

```cpp
for(const auto& pair : map_value_indices) { 
    
    // indices contains all positions where this prefix sum appeared 
    const std::vector<int>& indices = pair.second; 

    // First occurrence of this prefix sum 
    int first = indices.front(); 

    // Last occurrence of this prefix sum 
    int last = indices.back(); 

    // ...
}
```

---

## Purpose of This Block

This block checks each prefix sum value stored in the map.

The map stores data like this:

```text
prefix_sum_value -> list of prefix indices where this value appeared
```

Example:

```text
0  -> [0, 2, 4]
-1 -> [1, 3]
```

This means:

```text
prefix sum 0 appeared at prefix indices 0, 2, and 4
prefix sum -1 appeared at prefix indices 1 and 3
```

For each prefix sum value, we take the first and last prefix index where it appeared.

The distance between the first and last index gives the maximum balanced subarray length for that prefix sum value.

---

## Line-by-Line Explanation

### 1. Loop Through the Map

```cpp
for(const auto& pair : map_value_indices)
```

This means:

```text
Go through every key-value pair inside map_value_indices.
```

The map is declared as:

```cpp
std::map<int, std::vector<int>> map_value_indices;
```

So each item inside the map is one key-value pair:

```text
prefix_sum_value -> vector of prefix indices
```

Example:

```text
0  -> [0, 2, 4]
-1 -> [1, 3]
```

Each `pair` contains two parts:

```cpp
pair.first
pair.second
```

In this problem:

```text
pair.first  = prefix sum value
pair.second = vector of prefix indices
```

Example:

```text
pair.first  = 0
pair.second = [0, 2, 4]
```

Now break down this loop declaration:

```cpp
const auto& pair
```

### Meaning of `auto`

```cpp
auto
```

means C++ automatically figures out the type of `pair`.

In this case, each map entry has a type similar to:

```cpp
std::pair<const int, std::vector<int>>
```

So instead of writing the full long type manually, we write:

```cpp
auto
```

This makes the code shorter and cleaner.

### Meaning of `&`

```cpp
&
```

means reference.

So:

```cpp
auto& pair
```

means:

```text
Do not copy the map entry.
Use the original map entry directly.
```

This is useful because each map entry contains a vector, and copying a vector can be expensive.

### Meaning of `const`

```cpp
const
```

means read-only.

So:

```cpp
const auto& pair
```

means:

```text
Use the original map entry directly without copying it, but do not modify it.
```

This is the best choice here because this loop only reads from the map.

So the full line:

```cpp
for(const auto& pair : map_value_indices)
```

means:

```text
For each key-value pair in the map:
    read the original pair directly,
    do not copy it,
    and do not modify it.
```

---

### 2. Get the Vector of Indices

```cpp
const std::vector<int>& indices = pair.second;
```

This means:

```text
Take the vector stored in pair.second and call it indices.
```

Example:

```text
pair.second = [0, 2, 4]
```

So:

```text
indices = [0, 2, 4]
```

This vector contains all prefix indices where the current prefix sum value appeared.

---

### 3. Get the First Occurrence

```cpp
int first = indices.front();
```

This takes the first value from the vector.

Example:

```text
indices = [0, 2, 4]
```

So:

```text
first = 0
```

This is the first prefix index where this prefix sum appeared.

---

### 4. Get the Last Occurrence

```cpp
int last = indices.back();
```

This takes the last value from the vector.

Example:

```text
indices = [0, 2, 4]
```

So:

```text
last = 4
```

This is the last prefix index where this prefix sum appeared.

---

## Example Walkthrough

Suppose the map is:

```text
0  -> [0, 2, 4]
-1 -> [1, 3]
```

### For prefix sum value `0`

```text
indices = [0, 2, 4]
first = 0
last = 4
length = last - first = 4 - 0 = 4
```

### For prefix sum value `-1`

```text
indices = [1, 3]
first = 1
last = 3
length = last - first = 3 - 1 = 2
```

The maximum length is:

```text
4
```

---

## Why Take First and Last?

For one prefix sum value, the longest distance comes from the earliest and latest occurrence.

Example:

```text
0 -> [0, 2, 4]
```

Possible distances:

```text
2 - 0 = 2
4 - 2 = 2
4 - 0 = 4
```

The maximum distance is:

```text
last - first
```

So we only need:

```cpp
indices.front()
indices.back()
```

---

## Why Use Reference Instead of Copy?

This line uses reference:

```cpp
for(const auto& pair : map_value_indices)
```

And this line also uses reference:

```cpp
const std::vector<int>& indices = pair.second;
```

The reason is efficiency.

The map contains vectors. A vector can store many values.

Example:

```text
0 -> [0, 2, 4, 6, 8, 10]
```

If we copy the vector, C++ creates a new duplicate vector in memory.

That is unnecessary because we only need to read the vector.

---

## Copy vs Reference

### Copy

```cpp
std::vector<int> indices = pair.second;
```

This creates a new copy of the vector.

Example:

```text
original vector: [0, 2, 4, 6]
copied vector:   [0, 2, 4, 6]
```

This uses extra time and memory.

---

### Reference

```cpp
const std::vector<int>& indices = pair.second;
```

This does not create a new vector.

Instead, `indices` becomes another name for the original vector.

```text
indices refers to pair.second
```

This is faster and uses less memory.

---

## Why `const`?

The keyword `const` means:

```text
Read only. Do not modify this value.
```

So this:

```cpp
const auto& pair
```

means:

```text
Read each map entry directly without copying it, and do not modify it.
```

And this:

```cpp
const std::vector<int>& indices
```

means:

```text
Read the vector directly without copying it, and do not modify it.
```

This is useful because this block only needs to read values, not change them.

---

## Why `first` and `last` Are Normal Integers

These lines do not need references:

```cpp
int first = indices.front();
int last = indices.back();
```

Because `int` is small and cheap to copy.

Copying one integer is not expensive.

But copying a full vector can be expensive.

So this is a good choice:

```cpp
const std::vector<int>& indices = pair.second;
int first = indices.front();
int last = indices.back();
```

---

## Simple Summary

This block means:

```text
For each prefix sum value:
    Get all prefix indices where it appeared.
    Take the first prefix index.
    Take the last prefix index.
    Use last - first to calculate the longest balanced subarray length for that prefix sum.
```

Reference is used because:

```text
The code only needs to read the map and vectors.
Copying vectors is unnecessary and inefficient.
Using const reference avoids copying and keeps the data safe from modification.
```

