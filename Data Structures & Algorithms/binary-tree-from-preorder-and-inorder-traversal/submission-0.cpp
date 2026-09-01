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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }
private:
    // 用 span 可以避免拷贝，不用 span 的写法见【C++ 写法二】
    TreeNode* build(span<int> preorder, span<int> inorder) {
        if (preorder.empty()) return nullptr;  // 空节点
        int root = preorder[0];
        // ranges::find(在哪個裡面找, 要找到哪一個數)
        int left_size = ranges::find(inorder, root) - inorder.begin(); // 左子树的大小
        TreeNode* left = build(preorder.subspan(1, left_size), inorder.subspan(0, left_size));
        TreeNode* right = build(preorder.subspan(left_size + 1), inorder.subspan(left_size + 1));
        return new TreeNode(preorder[0], left, right);
    }
};
