/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 遍歷兩次
        ListNode* cur = head;
        int len = 0;
        while (cur) {
            cur = cur->next;
            len++;
        }
        // cout << cnt;
        len -= n;
        ListNode* dummy = new ListNode(0, head);
        cur = dummy;
        while (len > 0) {
            cur = cur->next;
            len--;
        }
        ListNode* nxt = cur->next;
        cur->next = cur->next->next;
        nxt->next = nullptr;
        // 不回傳 head 是因為考慮到 edge case, 有可能 head 被刪了，所以回傳 dummy->next 
        return dummy->next;
    }
};
