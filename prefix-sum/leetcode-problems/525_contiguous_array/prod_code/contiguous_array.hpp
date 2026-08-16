#ifndef CONTIGUOUS_HPP
#define CONTIGUOUS_HPP

#include <vector>

class Solution {

public:

    std::vector<int> getBalanceArray(std::vector<int>& nums, int n);
    std::vector<int> getPrefixSum(std::vector<int> balanceArray, int n);
    int findMaxLength(std::vector<int>& nums);
};

#endif