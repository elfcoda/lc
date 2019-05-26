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
        if (s.length() < 3 || numRows == 1) return s;

        vector<string> vs;
        for (int i = 0; i < numRows; i++)
            vs.push_back("");

        // init
        vector<int> m_hash2QueIdx;
        int iModCount = (numRows - 1) * 2;
        m_hash2QueIdx.reserve(iModCount + 1);
        m_hash2QueIdx.resize(iModCount + 1);
        for (int m = 0; m < iModCount; m++)
        {
            m_hash2QueIdx[m] = (m < numRows) ? m : numRows - (m + 1 - numRows) - 1;
        }

        for (int k = 0; k < s.length(); k++)
        {
            vs[m_hash2QueIdx[(k%iModCount)]].push_back(s[k]);
        }

        string sRet = "";
        for (const auto& s: vs)
        {
            sRet += s;
        }

        return sRet;
    }
};
