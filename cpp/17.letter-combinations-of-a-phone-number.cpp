/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (41.51%)
 * Total Accepted:    390.5K
 * Total Submissions: 939K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int len = digits.length();
        if (len == 0) return ans;
        std::vector<std::string> vs{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> tmp;
        for (int i = 0; i < len; ++i)
        {
            tmp.push_back(vs[digits[i] - '0']);
        }

        genStr(tmp, 0, ans);

        return ans;
    }

    void genStr(const vector<string>& vi, int viIdx, vector<string>& vo)
    {
        vector<string> tmp;
        for (int i = vi.size() - 1; i >= 0; --i)
        {
            if (vo.empty())
            {
                string se = "0";
                for (const auto& it: vi[i])
                {
                    se[0] = it;
                    vo.push_back(se);
                }
            }
            else
            {
                tmp.clear();
                for (const auto& it: vi[i])
                {
                    for (const auto& s: vo)
                    {
                        string st;
                        st.push_back(it);
                        st += s;
                        tmp.push_back(st);
                    }
                }
                std::swap(tmp, vo);
            }
        }
    }
};
