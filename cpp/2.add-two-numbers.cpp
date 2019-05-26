/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.02%)
 * Total Accepted:    851.6K
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int iSum = 0;
        bool bC = false;
        ListNode* tHead = new ListNode(0);
        ListNode* tP = tHead;

        while (l1 != NULL || l2 != NULL)
        {
            iSum = bC ? 1 : 0;
            int i1 = l1 == NULL ? 0 : l1 -> val;
            int i2 = l2 == NULL ? 0 : l2 -> val;
            if ((iSum += i1 + i2) >= 10)
            {
                iSum %= 10;
                bC = true;
            }
            else
            {
                bC = false;
            }
            tP = tP -> next = new ListNode(iSum);
            l1 = l1 == NULL ? l1 : l1 -> next;
            l2 = l2 == NULL ? l2 : l2 -> next;
        }

        if (bC)
        {
            tP = tP -> next = new ListNode(1);
        }

        tHead = tHead -> next;
        return tHead;
    }
};
