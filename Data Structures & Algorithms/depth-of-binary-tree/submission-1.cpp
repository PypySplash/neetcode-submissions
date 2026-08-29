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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // // dfs
        // return 1 + max(maxDepth(root->left), maxDepth(root->right));
        // bfs
        deque<TreeNode*> dq({root});
        int ans = 0;
        while (!dq.empty()) {
            int level_size = dq.size();
            for (int i = 0; i < level_size; i++) {
                TreeNode* node = dq.front();
                dq.pop_front();
                if (node->left) {
                    dq.push_back(node->left);
                }
                if (node->right) {
                    dq.push_back(node->right);
                }
            }
            ans++;
        }
        return ans;
    }
};
