# Valid Palindrome 🧹🔁

## Problem Tried

This project is my step-by-step solution practice for **LeetCode 125: Valid Palindrome**.

---

## Problem Statement

A phrase is a palindrome if, 
- after converting all uppercase letters into lowercase letters and 
- removing all non-alphanumeric characters, 
- it reads the same forward and backward. 

**Alphanumeric characters include letters and numbers.**

Alphanumeric characters include:

```text
a-z, A-Z, 0-9
```

Return:

```text
true  -> if the cleaned string is a palindrome
false -> otherwise
```

---

## Example

```text
Input:
s = "A man, a plan, a canal: Panama"


Output:
true
```

Another example:

```text
Input:
s = "race a car"

Output:
false
```

---

## Constraints

```text
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
```

---

# My Step-by-Step Improvement Journey 🚀

I solved this problem in multiple versions.
The main goal was not only to get accepted, but also to improve the code step by step.

My initial idea was:

```text
Original string
        ↓
Remove non-alphanumeric characters
        ↓
Convert uppercase letters to lowercase
        ↓
Check palindrome using two pointers
```

---

# Version 1: First Working Approach

## Idea

In the first version, I followed a direct approach.

Steps:

1. Count all non-alphanumeric characters.
2. Calculate the exact size needed for the cleaned string.
3. Create a temporary character array.
4. Copy only alphanumeric characters into the temporary array.
5. Convert uppercase letters to lowercase.
6. Use two pointers to check whether the cleaned string is a palindrome.

---

## How Version 1 Works

First, I counted the characters that should be ignored:

```text
spaces, punctuation, symbols, etc.
```

Then I calculated:

```text
temp_size = original_length - non_alphanumeric_count
```

After that, I created a temporary string:

```text
temp[temp_size + 1]
```

The `+1` is needed because C strings must end with:

```c
'\0'
```

Then I filled `temp` with only valid characters.

For uppercase letters, I converted them to lowercase manually using a condition:

```text
If character is between 'A' and 'Z', convert it to lowercase.
Otherwise, insert it directly.
```

Finally, I used two pointers:

```text
left  -> starts from beginning
right -> starts from end
```

and compared characters one by one.

---

## Complexity

```text
Time Complexity: O(n)
Space Complexity: O(n)
```

---

## Limitations of Version 1

Version 1 worked, but it had some unnecessary complexity.

Problems:

```text
- It used a separate function just to count non-alphanumeric characters.
- It scanned the string once for counting.
- It scanned the string again to build the cleaned string.
- It used an extra manual uppercase check.
- It called isalnum() more than needed.
- The code was longer than necessary.
```

The uppercase checking part was not needed because:

```c
tolower()
```

already handles uppercase letters and leaves lowercase letters and digits unchanged.

So the next improvement was to simplify the cleaning logic.

---

# Version 2: Simplified Cleaning Logic ✨

## Improvement

In version 2, I removed the manual uppercase condition.

Instead of writing:

```text
If uppercase, convert.
Else, insert directly.
```

I used:

```text
If alphanumeric, apply tolower() and insert.
```

This works because:

```text
'A' -> 'a'
'a' -> 'a'
'7' -> '7'
```

So `tolower()` is safe for this purpose.

---

## How Version 2 Works

The main cleaning logic became simpler:

```text
For each character:
    if it is alphanumeric:
        convert it to lowercase
        insert it into temp
```

This reduced nested conditions and made the code easier to read.

---

## Complexity

```text
Time Complexity: O(n)
Space Complexity: O(n)
```

The Big-O complexity did not change, but the code became cleaner.

---

## What Improved from Version 1?

```text
- Removed unnecessary uppercase checking.
- Reduced nested if-else logic.
- Made the cleaning step easier to understand.
- Used tolower() more effectively.
```

---

## Limitations of Version 2

Version 2 was cleaner than version 1, but it still had some limitations.

```text
- It still counted non-alphanumeric characters first.
- It still made multiple passes over the string.
- It still used strlen(temp) later to find the cleaned string length.
- The cleaning logic was still inside isPalindrome(), making the function longer.
```

So the next improvement was to separate the cleaning logic into its own helper function.

---

# Version 3: Separated Helper Function 🧩

## Improvement

In version 3, I moved the cleaning logic into a separate function:

```c
getCleanAlphaNeumericString()
```

The purpose of this function was:

```text
Take the original string.
Build a cleaned lowercase string.
Store it inside temp.
```

---

## Why This Is Cleaner

This made `isPalindrome()` more focused.

Now the responsibilities were separated:

```text
countNonAlphaNeu()              -> counts ignored characters
getCleanAlphaNeumericString()   -> builds cleaned string
isPalindrome()                  -> checks palindrome
```

This is better code organization.

---

## How Version 3 Works

The helper function receives:

```c
char *temp
const char *s
```

In C, when we pass `temp`, the whole array is not copied.

Instead, C passes the address of the first character.

So this function modifies the original `temp` array directly.

That means this is efficient:

```text
No full array copy happens.
```

---

## Complexity

```text
Time Complexity: O(n)
Space Complexity: O(n)
```

The algorithmic complexity stayed the same.

---

## What Improved from Version 2?

```text
- Cleaner structure.
- Better separation of responsibility.
- isPalindrome() became easier to read.
- The cleaning process became reusable.
```

---

## Limitations of Version 3

Version 3 was more organized, but it still had some inefficiencies.

```text
- It still used countNonAlphaNeu().
- It still scanned the original string once just to calculate temp size.
- It still used strlen(temp) after building temp.
- The helper function built the cleaned string but did not return its length.
```

The helper function already knew how many characters it inserted using its internal index.

So instead of calling `strlen(temp)` later, the helper function could return the cleaned length directly.

That led to version 4.

---

# Version 4: Helper Returns Cleaned Length ✅

## Improvement

In version 4, I improved the helper function so that it returns the length of the cleaned string.

The function now does two jobs:

```text
1. Build the cleaned string.
2. Return the cleaned string length.
```

This is useful because the helper already tracks the insertion index.

So instead of doing this later:

```c
strlen(temp)
```

I can directly use the returned length.

---

## Another Improvement

In this version, I removed the need for:

```c
countNonAlphaNeu()
```

Instead of calculating the exact cleaned string size, I used the maximum possible size:

```text
original length + 1
```

Why?

Because the cleaned string can never be longer than the original string.

So this is safe:

```text
temp size = original length + 1
```

The `+1` is for the null terminator.

---

## How Version 4 Works

Steps:

```text
1. Get original string length.
2. Create temp array of size length + 1.
3. Build cleaned lowercase string.
4. Return cleaned string length from helper.
5. Use two pointers from 0 to cleaned_length - 1.
6. Compare characters from both ends.
```

---

## Complexity

```text
Time Complexity: O(n)
Space Complexity: O(n)
```

The Big-O time complexity is still `O(n)`, but this version is practically better because it removes extra scans.

---

## What Improved from Version 3?

```text
- Removed countNonAlphaNeu().
- Removed one unnecessary full scan of the string.
- Avoided calling strlen(temp).
- Helper function became more useful.
- Palindrome checking became simpler because cleaned length is already known.
```

---

## Why Version 4 Is the Best Among These Four

Version 4 is the cleanest version among my temporary-string approaches.

It has:

```text
- Cleaner structure
- Fewer passes over the string
- No separate counting function
- No need to calculate exact temp size
- No need to call strlen(temp)
- Simple two-pointer checking
```

So version 4 is the best version in this progression.

---

# Final Complexity Comparison 📊

| Version   | Main Idea                                           | Time Complexity | Space Complexity | Main Limitation               |
| --------- | --------------------------------------------------- | --------------: | ---------------: | ----------------------------- |
| Version 1 | Count, clean, manually handle uppercase, then check |            O(n) |             O(n) | Too many conditions           |
| Version 2 | Use `tolower()` directly for all valid characters   |            O(n) |             O(n) | Still counts first            |
| Version 3 | Move cleaning logic to helper function              |            O(n) |             O(n) | Helper does not return length |
| Version 4 | Helper builds string and returns cleaned length     |            O(n) |             O(n) | Still uses extra temp array   |

---

# What Can Be Improved Further? 🔥

Version 4 is good, but it still uses extra memory because it creates a temporary cleaned string.

The next possible improvement is to avoid `temp` completely.

Instead, I can use two pointers directly on the original string

---

# Learning Summary 🧠

From these four versions, I learned:

```text
- How C strings work with '\0'
- Why temp arrays need extra space for null terminator
- How to clean a string manually in C
- How to use isalnum()
- How to use tolower()
- How to pass character arrays to functions
- How helper functions can make code cleaner
- How to improve code step by step
- How two pointers can check palindrome efficiently
```

---

# Final Verdict

Version 4 is the best version among these four.

It is clean, understandable, and efficient enough for the temporary-string approach.

Current best version:

```text
Version 4
```

Future optimized version:

```text
Direct two-pointer approach with O(1) extra space
```
