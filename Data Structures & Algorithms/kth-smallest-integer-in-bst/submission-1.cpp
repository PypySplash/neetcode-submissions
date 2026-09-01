/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // O(H + k), H: 樹的高度, 直接利用二叉樹的特性去做 inorder traversal
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()) {
            // 一直往左走，將沿途節點推入 Stack（尋找當前最小值）
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();

            // 處理當前節點：計數減 1
            k--;
            if (k == 0) return cur->val;

            // 轉向右子樹
            cur = cur->right;
        }
        return -1;

        // // O(N log k)
        // priority_queue<int> max_heap; // C++ 預設最大堆（彈出最大
        // dfs(root, k, max_heap);
        // return max_heap.top();
    }
// private:
//     void dfs(TreeNode* node, int k, priority_queue<int> &pq) {
//         if (!node) return;
//         pq.push(node->val);
//         if (pq.size() > k) pq.pop();
//         dfs(node->left, k, pq);
//         dfs(node->right, k , pq);
//     }
};
