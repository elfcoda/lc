/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (48.41%)
 * Total Accepted:    347.6K
 * Total Submissions: 712.9K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        combine(ans, v, candidates, 0, target);

        return ans;
    }

    void combine(vector<vector<int>>& ans, vector<int>& v, const vector<int>& candidates, int idx, int target) {
        if (target == 0) {
            if (!v.empty()) ans.push_back(v);
            return;
        }
        if (idx == candidates.size()) return;
        int count = target / candidates[idx];
        for (int m = 0; m < count; ++m) v.push_back(candidates[idx]);
        for (int i = count; i >= 0; --i) {
            combine(ans, v, candidates, idx + 1, target - i * candidates[idx]); // new target
            if (i != 0) v.pop_back();
        }
    }
};
