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
    ListNode* mergeTwo(ListNode* l1, ListNode* l2)
    {
        // not null
        ListNode* head, * p;
        if (l1->val < l2->val) { head = p = l1; l1 = l1->next; }
        else { head = p = l2; l2 = l2->next; }

        while (true)
        {
            if (l1 == NULL) { p->next = l2; return head; }
            else if (l2 == NULL) { p->next = l1; return head; }
            else if (l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }

        return NULL;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;

        for (const auto& it: lists)
        {
            if (it == NULL) continue;
            if (head == NULL) head = it;
            else head = mergeTwo(head, it);
        }

        return head;
    }
};
