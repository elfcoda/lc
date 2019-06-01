/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.78%)
 * Total Accepted:    347.6K
 * Total Submissions: 759.3K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 3) return 0;
        int iRet = nums[0] + nums[1] + nums[2];
        int iAbs = std::abs(iRet - target);
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; ++i)
        {
            int t = target - nums[i];
            int j = i + 1, k = len - 1;
            while (j < k)
            {
                int s = nums[j] + nums[k];
                int a = std::abs(s - t);
                if (!a) return target;
                else if (s < t) ++j;
                else --k;
                if (a < iAbs)
                {
                    iAbs = a;
                    iRet = nums[i] + s;
                }
            }
        }

        return iRet;
    }
};
