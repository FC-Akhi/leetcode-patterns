## 🚀 4th Learning
🗓️ **Date:** 07 June, 2026

🧠 **Topic:** Explanation of ```assert``` in C++


### Method with assert for unit testing
```cpp
void testLeetCodeExample() {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray numArray(nums);

    assert(numArray.sumRange(0, 2) == 1);
    assert(numArray.sumRange(2, 5) == -1);
    assert(numArray.sumRange(0, 5) == -3);
}
```

---

## 1. `assert`

### What it does?
```assert``` checks whether a condition is true during program execution.

Example:
```cpp
assert(numArray.sumRange(0, 2) == 1);
```
This means:

I expect sumRange(0, 2) to return 1.

If the condition is true, the program continues.

If the condition is false, the program stops and shows an assertion failure message.

Watch this video for better explanation 

**[Assert In C and Cpp](https://www.youtube.com/watch?v=iXIuOe1agH4)**

---


## Why use `assert`?

`assert` is useful for checking developer assumptions during testing.

For example:

```cpp
assert(numArray.sumRange(0, 2) == 1);
assert(numArray.sumRange(2, 5) == -1);
assert(numArray.sumRange(0, 5) == -3);
```

This helps verify that the code produces the expected output.

Instead of manually checking printed results, `assert` automatically checks them.

---

## Why use `assert` instead of `if`?

### Assert in Development vs Release Code

`assert` is active in development/debug builds.

It helps catch bugs early.

But `assert` can be disabled in release builds by defining:

```cpp
NDEBUG
```

Example compile command:

```bash
g++ -DNDEBUG main.cpp -o main
```

When `NDEBUG` is defined, `assert` checks are removed.

So:

```text
Debug build   -> assert is active
Release build -> assert is disabled
```

This is useful because development code can have extra checks, but release code can avoid the runtime cost of those checks.
if statments can't work this way. 

---


## Final Rule

Use `assert` for:

```text
unit-test-like checks
debugging
developer assumptions
conditions that should never fail if the code is correct
```

Do not use `assert` for:

```text
user input validation
API input validation
file input validation
important runtime error handling
```

Because `assert` can be disabled in release builds.
