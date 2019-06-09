/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (23.56%)
 * Total Accepted:    133.6K
 * Total Submissions: 565.4K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 *
 * Example 1:
 *
 *
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 *
 *
 * barfoofoobarthefoobarman"\n["bar","foo","the"]
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.size() == 0) return vector<int>{};
        std::unordered_map<string, int> mpre;
        std::vector<int> ans;
        for (const auto& it: words) mpre[it]++;
        int len = words[0].length(), nums = words.size(), slen = s.length();
        for (int i = 0; i < len; ++i)
        {
            std::unordered_map<string, int> mcur;
            int count = 0;
            int low = i;
            for (int j = i; j < slen - len + 1 && low < slen - len * nums + 1; j += len)
            {
                string sstr = s.substr(j, len);
                if (mpre.count(sstr))
                {
                    ++mcur[sstr];
                    ++count;
                    if (mcur[sstr] > mpre[sstr])
                    {
                        while (mcur[sstr] > mpre[sstr])
                        {
                            --mcur[s.substr(low, len)];
                            low += len;
                            --count;
                        }
                    }
                    else if (count == nums) // judge after mcur error. logic
                    {
                        ans.push_back(low);
                        --mcur[s.substr(low, len)];
                        low += len;
                        --count;
                    }
                }
                else
                {
                    low = j + len;
                    count = 0;
                    mcur.clear();
                }
            }
        }

        return ans;
    }
};
