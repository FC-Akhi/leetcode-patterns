## 🚀 1st Learning

🗓️ **Date:** 04 June, 2026  
🧠 **Topic:** Static Array, Dynamic Array, Linked List, and Vector in C++


# Static Array, Dynamic Array, Linked List, and Vector in C++
## Overview

In C++, there are different ways to store multiple values of the same type.
Some common options are:

```text
1. Static array
2. Dynamic array
3. Linked list
4. Vector
```

Each one has its own advantages and limitations.
For modern C++ and coding interviews, `vector` is usually the most common and practical choice.

---

# 1. Static Array

A static array is an array with a fixed size.

## Declaration

```cpp
int arr[5];
```

## Declaration with initialization

```cpp
int arr[5] = {10, 20, 30, 40, 50};
```

## Accessing elements

```cpp
cout << arr[0];  // prints 10
cout << arr[2];  // prints 30
```

## Updating elements

```cpp
arr[1] = 100;
```

Now the array becomes:

```text
[10, 100, 30, 40, 50]
```

## Advantages of Static Array

* Simple to declare and use.
* Fast element access using index.
* Memory is automatically managed.
* Good when the size is known before compilation.

Example:

```cpp
int arr[3] = {1, 2, 3};

cout << arr[0] << endl;
cout << arr[1] << endl;
cout << arr[2] << endl;
```

## Limitations of Static Array

* Size is fixed.
* Cannot easily increase or decrease the size.
* When passed to a function, it loses size information and behaves like a pointer.
* Not flexible for problems where input size changes.

Example limitation:

```cpp
int arr[3] = {1, 2, 3};

// Cannot safely add a 4th element
```

---

# 2. Dynamic Array

A dynamic array is created during runtime using pointers.

## Declaration

```cpp
int* arr = new int[5];
```

## Assigning values

```cpp
arr[0] = 10;
arr[1] = 20;
arr[2] = 30;
arr[3] = 40;
arr[4] = 50;
```

## Accessing elements

```cpp
cout << arr[0];  // prints 10
cout << arr[3];  // prints 40
```

## Releasing memory

```cpp
delete[] arr;
```

## Complete example

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 5;

    int* arr = new int[n];

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    cout << arr[2] << endl;

    delete[] arr;

    return 0;
}
```

## Advantages of Dynamic Array

* Size can be decided during runtime.
* Fast element access using index.
* Useful when the array size is not known at compile time.

Example:

```cpp
int n;
cin >> n;

int* arr = new int[n];
```

## Limitations of Dynamic Array

* Memory must be manually managed.
* If `delete[]` is forgotten, memory leak can happen.
* Resizing is difficult.


Example problem:

```cpp
int* arr = new int[5];

// If we need 10 elements later,
// we must manually create a new bigger array,
// copy old values, and delete the old array.
```

---

# 3. Linked List

A linked list stores data in nodes.
Each node contains a value and a pointer to the next node.

## Node declaration

```cpp
struct Node {
    int data;
    Node* next;
};
```

## Creating nodes

```cpp
Node* first = new Node();
Node* second = new Node();
Node* third = new Node();

first->data = 10;
second->data = 20;
third->data = 30;

first->next = second;
second->next = third;
third->next = nullptr;
```

## Accessing linked list elements

Linked list elements are accessed by traversal.

```cpp
Node* current = first;

while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
}
```

Output:

```text
10 20 30
```

## Advantages of Linked List

* Size can grow or shrink dynamically.
* Insertion and deletion can be efficient if the node position is already known.
* Does not require continuous memory like arrays.

## Limitations of Linked List

* No direct index access.
* To access an element, we must traverse from the head.
* Extra memory is needed for pointers.

Example limitation:

```cpp
// Cannot directly access the 3rd element like this:
list[2];  // Not valid for a raw linked list
```

Instead, we must move node by node.

---

# 4. Vector

A `vector` is a dynamic array provided by the C++ Standard Template Library, also known as STL.

It is declared using:

```cpp
#include <vector>
```

A vector behaves like an array, but it can grow and shrink automatically.

## Declaration

```cpp
vector<int> nums;
```

## Declaration with initialization

```cpp
vector<int> nums = {10, 20, 30, 40, 50};
```

## Accessing elements

```cpp
cout << nums[0];  // prints 10
cout << nums[2];  // prints 30
```

## Updating elements

```cpp
nums[1] = 100;
```

Now the vector becomes:

```text
[10, 100, 30, 40, 50]
```

## Adding elements

```cpp
nums.push_back(60);
```

Now the vector becomes:

```text
[10, 100, 30, 40, 50, 60]
```

## Removing the last element

```cpp
nums.pop_back();
```

## Getting the size

```cpp
cout << nums.size();
```

## Complete example

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {10, 20, 30};

    nums.push_back(40);
    nums.push_back(50);

    cout << nums[0] << endl;
    cout << nums[3] << endl;

    nums[1] = 100;

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
```

Output:

```text
10
40
10 100 30 40 50
```

---

# 5. What is a Vector?

A vector is a dynamic array in C++.

It gives array-like access:

```cpp
nums[i]
```

But unlike a static array, it can grow:

```cpp
nums.push_back(10);
nums.push_back(20);
nums.push_back(30);
```

So vector gives both:

```text
1. Fast index access like an array
2. Dynamic size like a dynamic array
```

---

# 6. How Vector is Related to Template Class

`vector` is a template class in C++.

Its general form is:

```cpp
vector<T>
```

Here, `T` means the data type.

For example:

```cpp
vector<int> numbers;
vector<double> prices;
vector<char> letters;
vector<string> names;
```

The same vector class or template class can work with different data types.

## Why is it called a Template Class?

It is called a template class because the data type is not fixed.

The compiler creates the required version based on the type we provide.

For example:

```cpp
vector<int> nums;
```

means:

```text
Create a vector that stores integers.
```

Another example:

```cpp
vector<string> names;
```

means:

```text
Create a vector that stores strings.
```

So `vector` is reusable for many data types.

---

# 7. Advantages of Vector

## 1. Dynamic Size

Vector can grow automatically.

```cpp
vector<int> nums;

nums.push_back(10);
nums.push_back(20);
nums.push_back(30);
```


## 1.1 Capacity Growth Behavior

A vector has two important concepts:

```cpp
size()
capacity()
```

`size()` means the number of elements currently stored in the vector.

`capacity()` means the amount of memory currently allocated for the vector.

Example:

```cpp
vector<int> nums;

cout << nums.size() << endl;      // number of elements
cout << nums.capacity() << endl;  // allocated space
```

When we keep adding elements using `push_back()`, the vector grows automatically.

```cpp
vector<int> nums;

nums.push_back(10);
nums.push_back(20);
nums.push_back(30);
```

If the current capacity is full and we add another element, the vector usually allocates a bigger memory block. Then it copies or moves the old elements into the new memory block.

Many implementations increase the capacity by a larger amount, often around 1.5x or 2x, instead of increasing by only 1 each time. This helps make repeated `push_back()` operations efficient.

Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;

    for (int i = 0; i < 10; i++) {
        nums.push_back(i);

        cout << "Size: " << nums.size()
             << ", Capacity: " << nums.capacity()
             << endl;
    }

    return 0;
}
```

Possible output:

```text
Size: 1, Capacity: 1
Size: 2, Capacity: 2
Size: 3, Capacity: 4
Size: 4, Capacity: 4
Size: 5, Capacity: 8
Size: 6, Capacity: 8
Size: 7, Capacity: 8
Size: 8, Capacity: 8
Size: 9, Capacity: 16
Size: 10, Capacity: 16
```

The exact capacity growth can be different depending on the compiler and C++ standard library implementation.

Important point:

```text
size <= capacity
```

So vector may allocate more memory than the current number of elements to avoid reallocating memory every time a new element is added.

**Note: Videos you can watch
- [How Vector Works Internally In C++? STL In C++](https://www.youtube.com/watch?v=OdPiF_K2miw)
- [Why vector Was Introduced In C++?](https://www.youtube.com/watch?v=-llMJFZZxH4)


## 2. Fast Index Access

Like an array, vector allows direct index access.

```cpp
cout << nums[0];
cout << nums[1];
```

Index access takes constant time:

```text
O(1)
```

## 3. Automatically Manages Memory

Unlike dynamic arrays, we do not need to manually use:

```cpp
new
delete
```

The vector manages memory internally.

## 4. Knows Its Own Size

Vector has a built-in function:

```cpp
nums.size();
```

Raw arrays do not have this inside functions.

## 5. Easy to Pass to Functions

Read-only function:

```cpp
void printVector(const vector<int>& nums) {
    for (int x : nums) {
        cout << x << " ";
    }
}
```

Modifying function:

```cpp
void updateVector(vector<int>& nums) {
    nums[0] = 100;
}
```

## 6. Common in Coding Interviews

Most LeetCode C++ problems use:

```cpp
vector<int>& nums
```

instead of raw arrays.

---

# 8. Limitations of Vector

Although vector is very useful, it also has some limitations.

## 1. Insertion in the Middle Can Be Slow

Adding an element in the middle may require shifting elements.

```cpp
nums.insert(nums.begin() + 1, 99);
```

This can take:

```text
O(n)
```

## 2. Deletion from the Middle Can Be Slow

Removing from the middle also requires shifting elements.

```cpp
nums.erase(nums.begin() + 1);
```

This can take:

```text
O(n)
```

## 3. Resizing May Require Copying

When vector grows beyond its current capacity, it may allocate a bigger memory block and copy old elements.

This does not happen every time, but it can happen sometimes.

## 4. Continuous Memory Requirement

Vector stores elements in continuous memory.
If a very large vector is needed, it requires a large continuous memory block.

---

# 9. Comparison Table

| Data Structure | Size         | Index Access | Insert/Delete         | Memory Management            | Common Use                   |
| -------------- | ------------ | ------------ | --------------------- | ---------------------------- | ---------------------------- |
| Static Array   | Fixed        | Fast, O(1)   | Difficult             | Automatic                    | Fixed-size data              |
| Dynamic Array  | Runtime size | Fast, O(1)   | Difficult             | Manual                       | Low-level dynamic data       |
| Linked List    | Dynamic      | Slow, O(n)   | Fast if node is known | Manual in raw implementation | Frequent insertion/deletion  |
| Vector         | Dynamic      | Fast, O(1)   | Slow in middle, O(n)  | Automatic                    | Most C++ array-like problems |

---

# 10. Simple Rule

Use static array when:

```text
The size is fixed and known.
```

Use dynamic array when:

```text
You are learning low-level memory management.
```

Use linked list when:

```text
You need frequent insertion or deletion and do not need fast index access.
```

Use vector when:

```text
You need a dynamic array with fast index access and automatic memory management.
```

For most modern C++ and LeetCode-style problems, `vector` is the best default choice.

---
---
---
