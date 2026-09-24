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

    int pre_idx = 0;
    std::unordered_map<int, int> mappings;

    TreeNode* helper(vector<int>& preorder, int l, int r){

        if (l > r){
            return nullptr;
        }
        int root_val = preorder[pre_idx++];
        TreeNode* node = new TreeNode(root_val);
        // left subtree
        node->left = helper(preorder, l,  mappings[root_val] - 1);
        node->right = helper(preorder, mappings[root_val] + 1, r);

        return node;
    }



public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (size_t i = 0; i < inorder.size(); i++){
            mappings[inorder[i]] = i;
        }

        return helper(preorder, 0, preorder.size() - 1);
        
    }
};
