/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (26.16%)
 * Total Accepted:    433.4K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 *
 * Example 2:
 *
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) return 0;
        int l1 = nums1.size(), l2 = nums2.size();
        int iTargetIdx = (l1 + l2) / 2;
        int iCurIdx = -1;
        int i1 = 0, i2 = 0;
        int iRet = 0;
        std::vector<int> v;
        v.reserve(iTargetIdx+5);
        while (iCurIdx != iTargetIdx)
        {
            if (i1 < l1 && i2 < l2)
            {
                if (nums1[i1] < nums2[i2])
                {
                    v.push_back(nums1[i1++]);
                }
                else
                {
                    v.push_back(nums2[i2++]);
                }
                iCurIdx ++;
            }
            else if (i1 > l1 - 1)
            {
                // move i2
                while (iCurIdx != iTargetIdx)
                {
                    v.push_back(nums2[i2++]);
                    iCurIdx ++;
                }
            }
            else if (i2 > l2 - 1)
            {
                // move i1
                while (iCurIdx != iTargetIdx)
                {
                    v.push_back(nums1[i1++]);
                    iCurIdx ++;
                }
            }
        }

        int iVSize = v.size();
        if ((l1 + l2) % 2 == 1)
        {
            return v[iVSize-1];
        }

        double d = 2.0f;
        return (v[iVSize-1] + v[iVSize-2]) / d;
    }
};
