/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.27%)
 * Total Accepted:    303.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 *
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 * Example 4:
 *
 *
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
*
*
* Example 5:
*
*
* Input:
* s = "mississippi"
* p = "mis*is*p*."
* Output: false
*
*
*/
class Solution {
    public:
        int sLen;
        int pLen;
        string s;
        string p;
        bool isMatch(string s, string p) {
            this->s = s;
            this->p = p;
            sLen = s.length();
            pLen = p.length();

            // init vector for memorizing
            vector<vector<bool>> vv(sLen+1, vector<bool>(pLen+1, false));
            vv[sLen][pLen] = true;
            for (int i = pLen - 1; i >= 0; i -= 2)
            {
                if (p[i] == '*') vv[sLen][i-1] = true;
                else break;
            }

            return isMat(vv);
        }

        inline bool isRepeat(int idx)
        {
            if (idx + 1 < pLen && p[idx + 1] == '*') return true;
            return false;
        }

        bool isMat(vector<vector<bool>>& vv)
        {
            int sIdx = sLen - 1, pIdx = pLen - 1;
            for (int sIdx = sLen - 1; sIdx >= 0; sIdx --)
            {
                for (int pIdx = pLen - 1; pIdx >= 0; pIdx--)
                {
                    if (p[pIdx] == '*') continue;
                    else if (p[pIdx] == '.' && !isRepeat(pIdx))
                    {
                        vv[sIdx][pIdx] = vv[sIdx + 1][pIdx + 1];
                    }
                    else if (p[pIdx] >= 'a' && p[pIdx] <= 'z' && !isRepeat(pIdx))
                    {
                        if (s[sIdx] == p[pIdx]) vv[sIdx][pIdx] = vv[sIdx + 1][pIdx + 1];
                        else vv[sIdx][pIdx] = false;
                    }
                    else if (p[pIdx] == '.' && isRepeat(pIdx))
                    {
                        // no match || match one
                        vv[sIdx][pIdx] = vv[sIdx][pIdx + 2] || vv[sIdx + 1][pIdx];
                    }
                    else if (p[pIdx] >= 'a' && p[pIdx] <= 'z' && isRepeat(pIdx))
                    {
                        // last situation
                        if (s[sIdx] != p[pIdx]) vv[sIdx][pIdx] = vv[sIdx][pIdx + 2];
                        else vv[sIdx][pIdx] = vv[sIdx][pIdx + 2] || vv[sIdx + 1][pIdx];
                    }
                }
            }

            return vv[0][0];
        }
};
