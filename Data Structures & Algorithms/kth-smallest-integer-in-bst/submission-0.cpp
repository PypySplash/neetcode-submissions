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
        // O(N log k)
        priority_queue<int> max_heap; // C++ 預設最大堆（彈出最大
        dfs(root, k, max_heap);
        return max_heap.top();

    }
private:
    void dfs(TreeNode* node, int k, priority_queue<int> &pq) {
        if (!node) return;

        pq.push(node->val);

        if (pq.size() > k) {
            pq.pop();
        }
        
        dfs(node->left, k, pq);
        dfs(node->right, k , pq);
    }
};
