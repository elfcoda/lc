/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.98%)
 * Total Accepted:    549.5K
 * Total Submissions: 2.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vvi;

        std::sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 2; ++i)
        {
            if (nums[i] > 0 ) break;
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = len - 1, target = 0 - nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] == target)
                {
                    vvi.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) ++j;
                    while (j < k && nums[k] == nums[k - 1]) --k;
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > target) --k;
                else ++j;
            }
        }

        return vvi;
    }
};
