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

private:
    TreeNode* lca;

    std::pair<bool, bool> helper(TreeNode* root, TreeNode* p, TreeNode* q, bool &foundLca){

        if (root == nullptr){
            return {false, false};
        }

        auto left = helper(root->left, p, q, foundLca);
        auto right = helper(root->right, p, q, foundLca);
        bool foundP = left.first || right.first || root == p;
        bool foundQ = left.second || right.second || root == q;
        if (foundP && foundQ && foundLca == false){
            lca = root;
            foundLca = true;
        }
        return {foundP, foundQ};
    }



public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        bool foundLca = false;
        helper(root, p, q, foundLca);
        return lca; 
    }
};