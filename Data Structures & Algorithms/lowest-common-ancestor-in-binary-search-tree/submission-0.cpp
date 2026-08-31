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

/*
思路應該是，給定 p, q ，要往上找祖先，找到的祖先先寄起來，直到找到共同的祖先，感覺不太對，有點久沒想 LCA 了
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // BST 特性: 左子樹節點值都小於當前節點，右子樹節點值都大於當前節點
        // 先使得 p always <= q
        if (p->val > q->val) {
            swap(p, q);
        }
        if ((p->val > root->val && q->val > root->val)) { // p, q 都在右子樹
            return lowestCommonAncestor(root->right, p, q);
        } else if (p->val < root->val && q->val < root->val) { // p, q 都在左子樹
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};
