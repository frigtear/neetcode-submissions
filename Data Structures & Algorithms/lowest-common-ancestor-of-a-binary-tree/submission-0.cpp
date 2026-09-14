/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr) {
            return nullptr;
        }

        // Since values are guaranteed to be unique,
        // we can compare values.
        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // p and q were found on opposite sides,
        // so root is their lowest common ancestor.
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // If both are on one side, pass that result upward.
        if (left != nullptr) {
            return left;
        }

        return right;
    }
};