/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.45%)
 * Total Accepted:    239.8K
 * Total Submissions: 786K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return;
        for (int i = len - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                int m = i + 1, n = len - 1;
                while (m < n) std::swap(nums[m++], nums[n--]);
                m = i + 1;
                while (nums[m] <= nums[i]) ++m; // as easier as possible.
                std::swap(nums[i], nums[m]);
                return;
            }
        }
        // reverse
        std::reverse(nums.begin(), nums.end());
    }
};
