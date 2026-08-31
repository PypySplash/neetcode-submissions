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
    void reorderList(ListNode* head) {
        // O(n) 做法（直觀
        vector<ListNode*> lv;
        ListNode* cur = head;
        // int size = 0;
        while (cur) {
            lv.push_back(cur);
            // cout << cur->val;
            cur = cur->next;
            // size++;
        }
        int left = 0, right = lv.size() - 1;
        // cout << lv.size();
        while (left < right) {
            lv[left]->next = lv[right];
            left++;
            if (left == right) break;
            lv[right]->next = lv[left];
            right--;
        }
        lv[right]->next = nullptr;
    }
};
