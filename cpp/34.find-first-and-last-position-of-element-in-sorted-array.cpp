/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.54%)
 * Total Accepted:    304.6K
 * Total Submissions: 906.2K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        vector<int> ans{-1, -1};
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                ans[0] = findLeftIdx(nums, target, l, mid);
                ans[1] = findRightIdx(nums, target, mid, r);
                return ans;
            }
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }

        return ans;
    }

    int findLeftIdx(const vector<int>& nums, int target, int l, int r)
    {
        while (true)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) return mid;
            else if (nums[mid] == target) r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }

    int findRightIdx(const vector<int>& nums, int target, int l, int r)
    {
        while (true)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target && ((mid == nums.size() - 1) || nums[mid + 1] != target)) return mid;
            else if (nums[mid] == target) l = mid + 1;
            else r = mid - 1;
        }
        return 0;
    }
};
