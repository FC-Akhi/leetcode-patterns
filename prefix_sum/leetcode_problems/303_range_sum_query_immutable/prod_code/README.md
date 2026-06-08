# Simple Production-Level Code Structure 🚀

This folder contains a simple production-level version of the **Range Sum Query - Immutable** problem.

The goal is to keep the code clean, separated, reusable, and easy to test.

---

## What is inside this folder?

```text
prod_code/
|
|-- build.sh
|-- num_array.hpp
|-- num_array.cpp
|-- range_sum_query_immutable_prod.cpp

```

---

## `num_array.hpp`

This is the **header file**.

It contains the class declaration for `NumArray`.

It tells what the class has, but not the full implementation details.

It usually contains:

```text
class name
private variables
public constructor
public methods
```

In this project, `num_array.hpp` declares:

```text
NumArray class
prefix_sum_ vector
NumArray constructor
sumRange() method
```

This file works like the public interface of the class.

---

## `num_array.cpp`

This is the **implementation file**.

It contains the actual logic of the `NumArray` class.

In this project, `num_array.cpp` contains:

```text
constructor implementation
prefix sum construction
sumRange() implementation
range validation
exception handling
```

The constructor builds the prefix sum vector once.

The `sumRange()` method answers each range query in `O(1)` time.

---

## `range_sum_query_immutable_prod.cpp`

This is the **main test runner file**.

It contains the `main()` function.

In this project, it runs different test functions, such as:

```text
basic LeetCode example test
single element test
all positive numbers test
all negative numbers test
invalid range test
empty input test
full flow test
```

This file checks whether the `NumArray` class works correctly.

It uses `assert()` for simple automated testing.

If all tests pass, it prints:

```text
All tests passed successfully.
```

---

## `build.sh` 🛠️

This is the build script.

It helps compile the code using `g++`.

Instead of writing the full `g++` command every time, we can run the script.

Example:

```bash
./build.sh -prod ./path/range_sum_query_immutable_prod.cpp
```

The script compiles:

```text
num_array.cpp
range_sum_query_immutable_prod.cpp
```

and creates an executable file.

It also uses useful compiler warning flags to catch possible issues early.

---

## Why separate the code like this? 🤔

This structure is cleaner than writing everything in one file.

It separates responsibilities:

```text
num_array.hpp                  -> class interface
num_array.cpp                  -> class implementation
range_sum_query_immutable_prod.cpp -> test runner and main function
build.sh                       -> build command
```

This makes the code easier to read, test, maintain, and reuse.

---

## Summary ✨

This is a simple production-level structure for the prefix sum solution.

The main idea is:

```text
Separate interface, implementation, testing, and build command.
```

This makes the project more organized and closer to real development practice.
