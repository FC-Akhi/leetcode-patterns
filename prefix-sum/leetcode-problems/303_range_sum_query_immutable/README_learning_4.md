## 🚀 4th Learning
🗓️ **Date:** 07 June, 2026

🧠 **Topic:** Explanation of differnet components of the ```range_sum_query_immutable_v4.cpp``` code. 
---


### Constructor
```cpp
explicit NumArray(const std::vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("Input vector cannot be empty");
    }

    prefixSum.resize(nums.size());

    prefixSum[0] = nums[0];

    for (int i = 1; i < static_cast<int>(nums.size()); i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
}
```

---

## 1. `explicit`

### What it does?

`explicit` stops C++ from creating a `NumArray` object automatically through implicit conversion.

```cpp
explicit NumArray(const std::vector<int>& nums)
```

This means a `NumArray` object must be created intentionally.

Allowed:

```cpp
NumArray obj(nums);
```

Avoided:

```cpp
NumArray obj = nums;
```

### Why it is needed?

The constructor takes one main input: a vector.

Without `explicit`, C++ may silently treat a `vector<int>` as a `NumArray` object in some cases.

That can make the code harder to read because object creation becomes hidden.

For this class, creating a `NumArray` is not just assigning data. It also builds internal prefix sum data. So object creation should be clear and intentional.

### Simple reasoning

`explicit` protects the design by saying:

```text
Do not create this object silently.
The programmer must clearly write NumArray object creation.
```

---

## 2. `throw std::invalid_argument(...)`

### What it does?

This line throws an exception when the input vector is empty.

```cpp
throw std::invalid_argument("Input vector cannot be empty");
```

It reports that the constructor received invalid input.

### Why it is needed?

The constructor later does this:

```cpp
prefixSum[0] = nums[0];
```

This line assumes that `nums[0]` exists.

If `nums` is empty, then `nums[0]` does not exist. Accessing it would be invalid and may cause undefined behavior.



### Simple reasoning

```text
Empty vector -> cannot build prefix sum -> throw error
```

This keeps the object in a valid state.

---

## 3. `prefixSum.resize(nums.size())`

### What it does?

This line changes the size of `prefixSum` to match the size of `nums`.

```cpp
prefixSum.resize(nums.size());
```

If `nums` has 6 elements, `prefixSum` will also have 6 elements.

Example:

```text
nums size      = 6
prefixSum size = 6
```

### Why it is needed?

Before this line, `prefixSum` is empty.

So this would be invalid:

```cpp
prefixSum[0] = nums[0];
```

because index `0` does not exist yet.

After `resize()`, the vector has enough positions, so index-based assignment becomes valid.

```cpp
prefixSum[0] = nums[0];
prefixSum[i] = prefixSum[i - 1] + nums[i];
```

### Simple reasoning

`resize()` prepares the prefix sum vector before filling it.


---

## 4. `static_cast<int>(nums.size())`

### What it does?

`nums.size()` returns a type called `size_t`.

`size_t` is unsigned, which means it cannot represent negative values.

But the loop variable is:

```cpp
int i
```

So this comparison mixes two different integer types:

```cpp
i < nums.size()
```

To make the comparison type-consistent, this code converts `nums.size()` to `int`:

```cpp
static_cast<int>(nums.size())
```

### Why it is needed?

It avoids signed vs unsigned comparison.

### Simple reasoning

The loop uses `int i`.

So the size is also converted to `int` before comparison.

```text
int compared with int
```

This makes the loop condition clearer and avoids type mismatch warnings.

---
