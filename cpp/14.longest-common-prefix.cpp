/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.49%)
 * Total Accepted:    464.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
 *
 */
class Solution {
public:
    string findCommPre(const string& s1, const string& s2)
    {
        string sRet = "";
        int iMinLen = min(s1.length(), s2.length());
        for (int i = 0; i < iMinLen; i++)
        {
            if (s1[i] == s2[i]) sRet.push_back(s1[i]);
            else break;
        }

        return sRet;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        string s0 = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            string sFind = findCommPre(s0, strs[i]);
            if (sFind == "") return "";
            else s0 = sFind;
        }

        return s0;
    }
};
