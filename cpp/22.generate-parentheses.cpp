/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (54.84%)
 * Total Accepted:    340K
 * Total Submissions: 618.6K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(ans, n, n, "");

        return ans;
    }

    // add l valid '('s and r valid ')'s.
    void gen(vector<string>& vo, int l, int r, string s)
    {
        if (r == 0)
        {
            vo.push_back(s);
            return;
        }

        // both left and right, output to s.
        if (l > 0) gen(vo, l - 1, r, s + "(");
        if (r > l) gen(vo, l, r - 1, s + ")");
    }

};
