/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.29%)
 * Total Accepted:    690.4K
 * Total Submissions: 2.7M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 *
 */
class Solution {
public:
    int reverse(int x) {
        bool bNe = false;
        long xx = x;
        if (xx < 0)
        {
            bNe = true;
            xx = -xx;
        }

        long y = 0;
        while (xx != 0)
        {
            y = y * 10 + xx % 10;
            if ((bNe && y > 2147483648) || (!bNe && y > 2147483647)) return 0;
            xx /= 10;
        }

        return bNe ? -y : y;
    }
};
