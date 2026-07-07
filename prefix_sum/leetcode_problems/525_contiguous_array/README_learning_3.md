# How to Calculate `log n` Time Complexity

## Code Block

```cpp
for(int i = 0; i < n + 1; i++) {

    map_value_indices[prefix_sum[i]].push_back(i);

}
```

---

## Purpose of This Block

This block stores each prefix sum value inside a map.

The map structure is:

```cpp
std::map<int, std::vector<int>> map_value_indices;
```

It stores data like this:

```text
prefix_sum_value -> list of prefix indices
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

---

## Step 1: Count the Loop

The loop is:

```cpp
for(int i = 0; i < n + 1; i++)
```

It starts from:

```text
i = 0
```

and continues until:

```text
i < n + 1
```

So the loop runs:

```text
n + 1 times
```

In Big-O notation:

```text
O(n)
```

Because constants are ignored, `n + 1` becomes `n`.

---

## Step 2: Analyze the Inside Line

Inside the loop, we have:

```cpp
map_value_indices[prefix_sum[i]].push_back(i);
```

This line has two main parts:

```cpp
map_value_indices[prefix_sum[i]]
```

and:

```cpp
.push_back(i)
```

---

## Step 3: Cost of `map_value_indices[prefix_sum[i]]`

The map is declared as:

```cpp
std::map<int, std::vector<int>> map_value_indices;
```

`std::map` keeps keys in sorted order.

Internally, `std::map` is usually implemented using a balanced binary search tree.

So when we write:

```cpp
map_value_indices[prefix_sum[i]]
```

C++ searches for the key:

```cpp
prefix_sum[i]
```

inside the tree.

If the key already exists, C++ finds it and returns its vector.

If the key does not exist, C++ finds the correct sorted position and creates a new empty vector for that key.

Both searching and inserting in `std::map` cost:

```text
O(log n)
```

---

## Why Tree Search Costs `log n`

A balanced binary search tree does not check every key one by one.

Instead, it moves left or right at each level.

Example idea:

```text
Is the key smaller or larger?
Go left or right.
Repeat until the key is found or the insert position is found.
```

Each step removes about half of the remaining search area.

That is why the cost is:

```text
O(log n)
```

So this part:

```cpp
map_value_indices[prefix_sum[i]]
```

costs:

```text
O(log n)
```

---

## Step 4: Cost of `.push_back(i)`

After the map gives us the vector, this part runs:

```cpp
.push_back(i)
```

This adds the current index `i` to the end of the vector.

For `std::vector`, `push_back()` is usually:

```text
O(1) amortized
```

---

## What Does Amortized Mean?

Amortized means:

```text
One operation may sometimes be expensive, but over many operations, the average cost is small.
```

For `vector.push_back()`:

* Most of the time, adding one element to the end is `O(1)`.
* Sometimes, the vector becomes full and needs to resize.
* During resizing, C++ creates a bigger memory block and moves old elements.
* That one resize operation can be expensive.
* But resizing does not happen every time.

So over many `push_back()` operations, the average cost is still:

```text
O(1)
```

That is why we say:

```text
push_back() = O(1) amortized
```

---

## Step 5: Cost of One Loop Iteration

Inside one iteration:

```cpp
map_value_indices[prefix_sum[i]].push_back(i);
```

The map access costs:

```text
O(log n)
```

The vector push costs:

```text
O(1) amortized
```

So one full iteration costs:

```text
O(log n) + O(1)
```

The bigger term is:

```text
O(log n)
```

So each loop iteration costs:

```text
O(log n)
```

---

## Step 6: Total Time Complexity

The loop runs:

```text
O(n)
```

Each iteration costs:

```text
O(log n)
```

So total time complexity is:

```text
O(n) * O(log n)
```

Therefore:

```text
O(n log n)
```

---

## Final Time Complexity

For this block:

```cpp
for(int i = 0; i < n + 1; i++) {

    map_value_indices[prefix_sum[i]].push_back(i);

}
```

the time complexity is:

```text
O(n log n)
```

because:

```text
n iterations × log n map access = O(n log n)
```

---

## Space Complexity

This block stores every prefix index in the map.

There are `n + 1` prefix indices.

So the space complexity is:

```text
O(n)
```

---

## Simple Summary

```text
The loop runs n times.
Each time, std::map searches or inserts a key in a tree.
Tree search costs log n.
push_back costs O(1) amortized.
So the total time complexity is O(n log n).
```

---

## Important Note

If we used:

```cpp
std::unordered_map<int, std::vector<int>>
```

instead of:

```cpp
std::map<int, std::vector<int>>
```

then average map access would be:

```text
O(1)
```

So the same block would become average:

```text
O(n)
```

But with the current `std::map` implementation, the time complexity is:

```text
O(n log n)
```
** Will discuss this later in [Map vs unordered_map](README_learning_3.md)


1. Averages
2. Sums and totals
3. Data interpretation tables
4. Net change problems
5. Arithmetic sequences
6. Word problems involving running totals