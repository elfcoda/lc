/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.97%)
 * Total Accepted:    429.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 */
class Solution {
public:
    void getNext(const string& needle, vector<int>& next)
    {
        int i = 0, j = -1;
        next[0] = -1;
        while (i < needle.size())
        {
            if (j == -1 || needle[i] == needle[j])
            {
                ++i;
                ++j;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;

        vector<int> next(needle.length() + 1, 0);
        getNext(needle, next);

        int j = -1, hlen = haystack.length(), nlen = needle.length();
        for (int i = -1; i < hlen;)
        {
            int idx = i - j;
            while ((j == -1) || (j < nlen && i < hlen && haystack[i] == needle[j]))
            {
                ++i;
                ++j;
            }
            if (j == nlen) return idx;
            else if (i == hlen) return -1;
            else j = next[j];
        }

        return -1;
    }
};
