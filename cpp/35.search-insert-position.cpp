/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.82%)
 * Total Accepted:    406.1K
 * Total Submissions: 993.3K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5,6], 5
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [1,3,5,6], 2
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: [1,3,5,6], 7
 * Output: 4
 *
 *
 * Example 4:
 *
 *
 * Input: [1,3,5,6], 0
 * Output: 0
 *
 *
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int l = 0, r = nums.size() - 1, mid;
       while (l <= r)
       {
           mid = (l + r) / 2;
           if (nums[mid] == target) return mid;
           else if (nums[mid] > target) r = mid - 1;
           else l = mid + 1;
       }

       // mid is the idx of last compare element, target is must be near with mid.
       return nums[mid] > target ? mid : mid + 1;
    }
};
