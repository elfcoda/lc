/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (25.46%)
 * Total Accepted:    192K
 * Total Submissions: 751.5K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 *
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 *
 * Example 2:
 *
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 *
 *
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len < 2) return 0;
        char a[')' + 1] = {};
        a['('] = ')';
        a[')'] = '(';
        std::stack<std::pair<char, int>> sp;
        sp.push(make_pair(s[0], 0));
        std::vector<int> count(len + 1, 0);
        int cur = 0;
        for (int i = 1; i < len; ++i)
        {
            if (!sp.empty() && s[i] == ')' && sp.top().first == a[s[i]])
            {
                cur += 2;
                count[i] = count[sp.top().second] = cur;
                sp.pop();
            }
            else sp.push(make_pair(s[i], i));
        }

        // deal with vecter count
        int iMax = 0, lastCount = 0;
        for (int j = 1; j < len; ++j)
        {
            if (count[j] != 0 && count[j + 1] == 0)
            {
                iMax = std::max(iMax, count[j] - lastCount);
                lastCount = count[j];
            }
        }

        return iMax;
    }
};
