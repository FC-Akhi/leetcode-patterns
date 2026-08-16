#ifndef NUM_ARRAY_HPP
#define NUM_ARRAY_HPP

#include <vector>

class NumArray {
private:
    std::vector<int> prefix_sum_;

public:
    explicit NumArray(const std::vector<int>& nums);

    int sumRange(int left, int right) const;
};

#endif