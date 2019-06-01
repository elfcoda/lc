/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.48%)
 * Total Accepted:    234.3K
 * Total Submissions: 767.3K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 *
 *
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> vvi;
        if (len < 4) return vvi;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; ++i)
        {
            // cut
            if (nums[i] > 0 && nums[i] > target) return vvi;
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len - 2; ++j)
            {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                int s = nums[i] + nums[j];
                // cut
                if (nums[j] > 0 && s > target) break;
                int t = target - s;
                int m = j + 1, n = len - 1;
                while (m < n)
                {
                    int iSum = nums[m] + nums[n];
                    if (iSum == t)
                    {
                        vvi.push_back({nums[i], nums[j], nums[m], nums[n]});
                        while (m < n && nums[m] == nums[m + 1]) ++m;
                        ++m;
                        while (m < n && nums[n] == nums[n - 1]) --n;
                        --n;
                    }
                    else if (iSum < t) ++m;
                    else --n;
                }
            }
        }

        return vvi;
    }
};
