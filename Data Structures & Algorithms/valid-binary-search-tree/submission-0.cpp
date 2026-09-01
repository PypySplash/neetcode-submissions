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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
private:
    bool helper(TreeNode* node, long long low, long long high) {
        // base case 空節點是合法的
        if (!node) return true;
        // 檢查當前節點值，是否在範圍內
        if (node->val <= low || node->val >= high) {
            return false;
        }
        // 往左走，改上界, 往右走，改下界
        return helper(node->left, low, node->val) && helper(node->right, node->val, high);
    }
};
