## 🚀 4th Learning
🗓️ **Date:** 07 June, 2026

🧠 **Topic:** Explanation of Constant member function in C++


### Method with constant member
```cpp
int sumRange(int left, int right) const {
    if (left < 0 || left > right || right >= static_cast<int>(prefixSum.size())) {
        throw std::out_of_range("Invalid range index");
    }

    if (left == 0) {
        return prefixSum[right];
    }

    return prefixSum[right] - prefixSum[left - 1];
}
```

---

## 1. `const`

### What it does?
It helps to restrict modification of data members inside function or method

Watch this video for better explanation 

**[Const Member Function In C++](https://www.youtube.com/watch?v=MR37gqFEmFA)**




