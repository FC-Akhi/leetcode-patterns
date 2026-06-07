#include "num_array.hpp"

#include <stdexcept>

NumArray::NumArray(const std::vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("Input vector cannot be empty");
    }

    prefix_sum_.resize(nums.size());
    prefix_sum_[0] = nums[0];

    for (int i = 1; i < static_cast<int>(nums.size()); i++) {
        prefix_sum_[i] = prefix_sum_[i - 1] + nums[i];
    }
}

int NumArray::sumRange(int left, int right) const {
    if (left < 0 || left > right || right >= static_cast<int>(prefix_sum_.size())) {
        throw std::out_of_range("Invalid range index");
    }

    if (left == 0) {
        return prefix_sum_[right];
    }

    return prefix_sum_[right] - prefix_sum_[left - 1];
}