/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (47.21%)
 * Total Accepted:    585.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head, * p;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val < l2->val) { head = p = l1; l1 = l1->next; }
        else { head = p = l2; l2 = l2->next; }

        ListNode* tmp;
        while (true)
        {
            if (l1 == NULL)
            {
                p->next = l2;
                return head;
            }
            else if(l2 == NULL)
            {
                p->next = l1;
                return head;
            }
            else if (l1->val < l2->val)
            {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }

        return NULL;
    }
};
