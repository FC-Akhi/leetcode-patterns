![Alt text](./prefix_sum.png)

---

# [1. Prefix Sum youtube link](https://youtu.be/DjYZk8nrXVY?t=34)


## Directory Tree

```text
prefix_sum/
|
|--> README_init.md
|--> prefix_sum.png
|--> leetcode_problems/
|
|--> 303_range_sum_query_immutable/
|    |--> prod_code
|    |    |--> build.sh
|    |    |--> num_array.cpp
|    |    |--> num_array.hpp
|    |    |--> range_sum_query_immutable_prod.cpp
|    | 
|    |--> problem_statement.png
|    |--> range_sum_query_immutable_v0.cpp
|    |--> range_sum_query_immutable_v1.cpp
|    |--> range_sum_query_immutable_v2.cpp
|    |--> range_sum_query_immutable_v3.cpp
|    |--> range_sum_query_immutable_v4.cpp
|    |--> README_learning_1.md
|    |--> README_learning_2.md
|    |--> README_learning_3.md
|    |--> README_learning_4.md
|    |--> README_learning_5.md
|    |--> README_learning_6.md
|    |--> README_v0.md
|    |--> README_v1.md
|    |--> README_v2.md
|    |--> README_v3.md
|    |--> README_v4.md
```

# Prefix Sum
## What is Prefix Sum?

Prefix sum is a technique where we store the cumulative sum of an array.

It means each index stores the sum of all elements from the beginning of the array up to that index.

Example:

```text
nums = [2, 4, 1, 7, 3]
```

The prefix sum array will be:

```text
prefix_sum = [2, 6, 7, 14, 17]
```

Explanation:

```text
prefix_sum[0] = 2
prefix_sum[1] = 2 + 4 = 6
prefix_sum[2] = 2 + 4 + 1 = 7
prefix_sum[3] = 2 + 4 + 1 + 7 = 14
prefix_sum[4] = 2 + 4 + 1 + 7 + 3 = 17
```

So, the prefix sum array stores the running total.

---

## Why Use Prefix Sum?

Prefix sum is useful when we need to answer multiple range sum queries.

A range sum query means:

```text
Find the sum of elements from index left to index right.
```

Without prefix sum, we need to loop from `left` to `right` every time.

Example:

```text
nums = [2, 4, 1, 7, 3]

sumRange(1, 3) = 4 + 1 + 7 = 12
```

If there are many queries, doing this repeatedly becomes slow.

With prefix sum, we can answer each range sum query faster using this formula:

```text
sumRange(left, right) = prefix_sum[right] - prefix_sum[left - 1]
```

If `left == 0`, then:

```text
sumRange(0, right) = prefix_sum[right]
```

Example:

```text
nums = [2, 4, 1, 7, 3]
prefix_sum = [2, 6, 7, 14, 17]

sumRange(1, 3) = prefix_sum[3] - prefix_sum[0]
               = 14 - 2
               = 12
```

So, prefix sum helps reduce repeated work.

---

## What is the Real-Life Use Case of Prefix Sum?

Prefix sum is useful in real life when we need to calculate totals over a range.

Examples:

```text
monthly salary reports, bank transaction summaries, sales reports, website visitor analytics, electricity usage tracking, student marks analysis, inventory reports, employee payroll analysis
```

---

## Example: Employee Salary Analysis

Suppose a company stores monthly salaries of an employee.

```text
Month:   Jan   Feb   Mar   Apr   May
Salary: 1000  1200  1100  1300  1500
```

If we want to calculate the total salary from February to April:

```text
Feb + Mar + Apr = 1200 + 1100 + 1300 = 3600
```

Using prefix sum:

```text
prefix_sum = [1000, 2200, 3300, 4600, 6100]
```

Now:

```text
sumRange(Feb, Apr) = prefix_sum[Apr] - prefix_sum[Jan]
                   = 4600 - 1000
                   = 3600
```

This helps calculate salary totals quickly for any range of months.

---

## Real-Life Data Science Use Case

In Data Science, prefix sum is useful for time-series and cumulative analysis.

Examples:

```text
total sales in the last 7 days, total website visits in a month, cumulative revenue, rolling user activity, total energy usage, total rainfall over a time period, cumulative salary expense
```

For example, in employee data analysis, prefix sum can help answer:

```text
How much salary has been paid to each employee so far?
What is the total salary expense from January to June?
Which department has the highest cumulative salary cost?
How does monthly salary expense grow over time?
```

This is useful for dashboards, reports, payroll analytics, financial forecasting, and business intelligence.

---

## Summary

Prefix sum is a simple but powerful technique.

It stores cumulative totals so that range sum queries can be answered quickly.

The main idea is:

```text
Do some preprocessing once, then answer many range queries faster.
```

Prefix sum is useful in programming, databases, analytics, finance, payroll systems, and data science.


