/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (36.39%)
 * Total Accepted:    184.7K
 * Total Submissions: 506.4K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 *
 *
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
    ListNode* reverse(ListNode* head, ListNode* tail)
    {
        ListNode *p = tail;
        while (head != tail)
        {
            auto tmp = head->next;
            head->next = p;
            p = head;
            head = tmp;
        }

        return p;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) return head;
        auto node = head;

        for (int i = 0; i < k; ++i)
        {
            if (node) node = node->next;
            else return head;
        }

        auto pHead = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return pHead;
    }
};
