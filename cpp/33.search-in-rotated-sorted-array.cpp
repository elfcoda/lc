/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.88%)
 * Total Accepted:    419.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return -1;
        if (len == 1) return target == nums[0] ? 0 : -1;
        if (nums[0] > nums[len - 1]) {
            // exists pivot
            int pivot = -1;
            int l = 0, r = len - 1;
            while (true)
            {
                int mid = (l + r) / 2;
                if (mid != 0 && nums[mid] < nums[mid - 1])  // mid should not be 0, heap=buffer overflow can be detected
                {
                    pivot = mid;
                    break;
                }
                else if (nums[mid] >= nums[0]) l = mid + 1;
                else r = mid - 1;
            }
            if (target >= nums[0]) return bs(nums, target, 0, pivot - 1);
            else return bs(nums, target, pivot, len - 1);
        }
        return bs(nums, target, 0, len - 1);
    }

    int bs(const vector<int>& nums, int target, int l, int r)
    {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};
