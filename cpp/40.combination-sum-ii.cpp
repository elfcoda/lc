/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (41.53%)
 * Total Accepted:    223.6K
 * Total Submissions: 535.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::map<int, int> mii;
        for (const auto& it: candidates) ++mii[it];

        vector<vector<int>> ans;
        vector<int> v;
        auto mit = mii.begin();
        combine(ans, v, mii, mit, target);

        return ans;
    }

    void combine(vector<vector<int>>& ans, vector<int>& v, const map<int, int>& mii, map<int, int>::iterator mit, int target) {
        if (target == 0) {
            if (!v.empty()) ans.push_back(v);
            return;
        }
        if (mit == mii.end()) return;

        int count = std::min(target / mit->first, mit->second);
        for (int i = 0; i < count ; ++i) v.push_back(mit->first);
        for (int j = count; j >= 0; --j) {
            combine(ans, v, mii, std::next(mit), target - j * mit->first);
            if (j != 0) v.pop_back();
        }
    }
};
