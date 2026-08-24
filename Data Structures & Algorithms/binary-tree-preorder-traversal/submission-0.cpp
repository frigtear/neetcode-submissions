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
private:
    void helper(std::vector<int> &output, TreeNode* node) {
        if (node == nullptr){
            return;
        }
        output.push_back(node->val);
        helper(output, node->left);
        helper(output, node->right);
    }


public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        helper(result, root);
        return result;
    }
};