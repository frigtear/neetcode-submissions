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

    bool dfs(TreeNode* node, int curr, int target){
        if (node){
            curr += node->val;
            if ((curr == target) && (node->left == nullptr && node->right == nullptr)){
                return true;
            }
            else{
                return dfs(node->left, curr, target) || dfs(node->right, curr, target);
            }
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};