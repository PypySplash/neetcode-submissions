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

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    void reorderList(ListNode* head) {
        // O(1) space 做法：快慢指針找中點後，後半 reverse Linkedlist, 接著 merge 2 linked list (不用比大小而是輪流)
        // 1. 快慢指針找中點
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 2. 後半 reverse, 且將 slow->next 改為 nullptr (slow 是前半的尾巴)
        ListNode* second = reverseList(slow->next);
        slow->next = nullptr;
        // 3. 交錯合併
        ListNode* first = head;
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (second) {
            cur->next = first;
            first = first->next;
            cur = cur->next;

            cur->next = second;
            second = second->next;
            cur = cur->next;
        }
        cur->next = first;

        // // O(n) space 做法（直觀
        // vector<ListNode*> lv;
        // ListNode* cur = head;
        // // int size = 0;
        // while (cur) {
        //     lv.push_back(cur);
        //     // cout << cur->val;
        //     cur = cur->next;
        //     // size++;
        // }
        // int left = 0, right = lv.size() - 1;
        // // cout << lv.size();
        // while (left < right) {
        //     lv[left]->next = lv[right];
        //     left++;
        //     if (left == right) break;
        //     lv[right]->next = lv[left];
        //     right--;
        // }
        // lv[right]->next = nullptr;
    }
};
