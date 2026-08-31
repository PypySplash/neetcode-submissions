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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode*> dq({root});
        vector<vector<int>> ans;
        // 當 dq 不為空
        while (!dq.empty()) {
            int level_size = dq.size();
            // 創建一個 level vector 來存取當層的所有節點值
            vector<int> level;
            for (int i = 0; i < level_size; i++) {
                // C++ popleft 的取值和 pop 要分開
                TreeNode* tmp = dq.front();
                dq.pop_front();
                if (tmp->left) dq.push_back(tmp->left);
                if (tmp->right) dq.push_back(tmp->right);
                level.push_back(tmp->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
