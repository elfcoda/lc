/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.14%)
 * Total Accepted:    554.5K
 * Total Submissions: 2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */
class Solution {
    public:
        string longestPalindrome(string s)
        {
            if (s.length() < 2) return s;
            int iMax = 0, iIdx = 0;
            for (int i = 0; i < s.length(); i++)
            {
                int start = i, end = i;
                while ((end+1) < s.length() && s[end+1] == s[i]) end ++;
                i = end;
                while ((start-1) >= 0 && (end+1) < s.length() && s[start-1] == s[end+1])
                {
                    start --;
                    end ++;
                }
                int iCurMax = end - start + 1;
                if (iCurMax > iMax)
                {
                    iMax = iCurMax;
                    iIdx = start;
                }
            }

            return s.substr(iIdx, iMax);
        }
};
