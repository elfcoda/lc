/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (34.41%)
 * Total Accepted:    390.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 *
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL, * p = NULL;
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];

        bool bFlag = false;
        multiset<int> si;
        for (const auto& it: lists)
        {
            if (it == NULL) continue;
            if (bFlag == false) {
                bFlag = true;
                head = it;
            }
            if (p) p->next = it;
            p = it;
            while (p->next)
            {
                si.insert(p->val);
                p = p->next;
            }
            si.insert(p->val);
        }

        // revalue
        ListNode* walk = head;
        for (const auto& i: si)
        {
            walk->val = i;
            walk = walk->next;
        }

        return head;
    }
};
