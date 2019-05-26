/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.28%)
 * Total Accepted:    900.7K
 * Total Submissions: 3.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int iMax = 0, iCurMax = 0;
        int iStrLen = s.length();
        std::unordered_set<char> c;
        std::queue<char> q;
        for (int i = 0; i < iStrLen; i++)
        {
            if (c.find(s[i]) == c.end())
            {
                q.push(s[i]);
                c.insert(s[i]);
                iCurMax ++;
                iMax = iCurMax > iMax ? iCurMax : iMax;
            }
            else
            {
                char p;
                while ((p = q.front()) != s[i])
                {
                    q.pop();
                    c.erase(p);
                    iCurMax --;
                }
                q.pop();
                q.push(s[i]);
            }
        }

        return iMax;
    }
};
