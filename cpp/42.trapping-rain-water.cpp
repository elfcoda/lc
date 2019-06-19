/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (43.12%)
 * Total Accepted:    297.9K
 * Total Submissions: 687.3K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 *
 * Example:
 *
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, idx;
        int ans = 0, cur = 0;
        while (l < r) { // when height is []
            cur = 0;
            if (height[l] < height[r]) {
                idx = l + 1;
                while (height[idx] < height[l]) cur -= height[idx++];
                cur += height[l] * (idx - l - 1);
                ans += cur;
                l = idx;
            }
            else {
                idx = r - 1;
                while (height[idx] < height[r]) cur -= height[idx--];
                cur += height[r] * (r - idx - 1);
                ans += cur;
                r = idx;
            }
        }

        return ans;
    }
};
