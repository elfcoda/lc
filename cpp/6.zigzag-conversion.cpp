/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (31.79%)
 * Total Accepted:    317.5K
 * Total Submissions: 998.7K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */
class Solution {
public:
    string convert(string s, int numRows) {
        int iLen = s.length();
        if (iLen < 3 || numRows == 1) return s;

        vector<string> vs(numRows, "");

        int k = 0;
        while (k < iLen)
        {
            // remove if
            for (int d = 0; d < numRows && k < iLen; d++)
                vs[d].push_back(s[k++]);
            for (int u = numRows - 2; u > 0 && k < iLen; u--)
                vs[u].push_back(s[k++]);
        }

        string sRet = "";
        for (const auto& s: vs)
        {
            sRet += s;
        }

        return sRet;
    }
};
