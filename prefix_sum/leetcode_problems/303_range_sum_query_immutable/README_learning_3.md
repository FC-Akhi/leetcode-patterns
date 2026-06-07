## 🚀 3rd Learning
🗓️ **Date:** 07 June, 2026

🧠 **Topic:** Design Reasoning: Where Should Prefix Sum Be Built?
---

# 🧠 Design Reasoning: Where Should Prefix Sum Be Built?

## 📌 Context

This note explains the design decision for building the prefix sum vector in an industry-grade development version of the `NumArray` class.

The main question is:

```text
Should prefix sum be built outside the constructor as a separate method,
or should it be built inside the constructor?
```

There are multiple possible designs. Each design has different safety, usability, and maintainability implications.

---

## Option 1: Prefix Sum as a Separate Method Returning a Vector 🤔

One possible design is to create a separate method like:

```cpp
std::vector<int> getPrefixSum(const std::vector<int>& nums);
```

Then the user calls this method separately and receives the prefix sum vector.

Example idea:

```text
User creates NumArray object
User calls getPrefixSum()
User stores prefixSum outside the object
User passes prefixSum again to sumRange()
```

### ⚠️ Why this design is not ideal for industry-grade code

This design exposes an internal implementation detail to the user.

The user now has to manage two things:

```text
1. NumArray object
2. prefixSum vector
```

This makes the class harder to use.

It also creates more chances for mistakes.

For example, the user may:

```text
forget to call getPrefixSum()
pass the wrong input vector to work to construct the prefixSum
modify prefixSum accidentally
call sumRange() before prefixSum is ready
```

#### 🔐 Important: This breaks encapsulation.

The prefix sum vector is not just random data. It is the internal structure that makes `sumRange()` fast.

So it should usually be hidden inside the class. It is not just an optional operation here.

---

## ✅ Option 2: Build Prefix Sum Inside the Constructor

The cleanest design for this problem is to build the prefix sum vector inside the constructor.

Example idea:

```text
Create NumArray object
|
Constructor receives nums
|
Constructor builds prefixSum
|
Object is ready to answer sumRange() queries
```

### Why this design is good for industry-grade code

This design makes the object fully initialized after construction.

After this line:

```cpp
NumArray numArray(nums);
```

the object is immediately ready to use.

The user can directly call:

```cpp
numArray.sumRange(left, right);
```

The user does not need to remember to build prefix sum separately.

The prefix sum vector is hidden as private internal data.

This improves:

```text
encapsulation
safety
readability
maintainability
ease of use
```

The public interface becomes simple:

```cpp
NumArray(nums)
sumRange(left, right)
```

This matches the responsibility of the class.

The class is created for range sum queries, so prefix sum is an essential part of the object.

---

## Industry-Grade Design Reasoning

In industry-grade development, a class should usually maintain a valid internal state.

That means after construction, the object should be ready to perform its main responsibility.

For this problem, the main responsibility is:

```text
answer range sum queries efficiently
```

To do that, the object needs prefix sum.

So prefix sum should be built during construction.

This avoids partially initialized objects.

It also avoids forcing the user to know or manage internal implementation details.

---

## 🎯 Final Design Decision

For this `NumArray` class, the best design is:

```text
Build prefix sum inside the constructor.
Store prefix sum as a private class member.
Expose only sumRange(left, right) as the query interface.
```

This gives a cleaner and safer interface.

---

## Summary

There are two possible designs:

```text
1. Return prefix sum from a separate method
2. Build prefix sum inside the constructor
```

For industry-grade code, option 2 is usually best for this problem 🥰

Reason:

```text
prefix sum is not optional for this class
the object should be ready after construction
the user should not manage internal data
sumRange() should be simple to call
internal data should be protected
```

### Final conclusion:

```text
Constructor-based prefix sum construction gives the safest, cleanest, and most maintainable design for NumArray.
```

