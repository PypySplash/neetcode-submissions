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
        // 遍歷一次(快慢指針，讓快指針先走 n 步，這樣他們走的步數就會是 len - n 步)
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        int tmp = n;
        // 回圈結束 slow 停在要刪除的節點前一格
        while (tmp > 0) {
            fast = fast->next;
            tmp--;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;


        // // 遍歷兩次
        // ListNode* cur = head;
        // int len = 0;
        // while (cur) {
        //     cur = cur->next;
        //     len++;
        // }
        // // cout << cnt;
        // len -= n;
        // ListNode* dummy = new ListNode(0, head);
        // cur = dummy;
        // while (len > 0) {
        //     cur = cur->next;
        //     len--;
        // }
        // cur->next = cur->next->next;
        // // 不回傳 head 是因為考慮到 edge case, 有可能 head 被刪了，所以回傳 dummy->next 
        // return dummy->next;
        // // 可考慮把 dummy, 移除的節點刪除，清空記憶體
    }
};
