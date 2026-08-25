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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        if (root == nullptr){
            return new TreeNode(val);
        }
        while (true){

            if ( curr->left == nullptr and val < curr->val ){
                curr->left = new TreeNode(val);
                break;
            }
            else if (curr->right == nullptr and val > curr->val){
                curr->right = new TreeNode(val);
                break;
            }
            else if (curr->left != nullptr and val < curr->val){
                curr = curr->left;
            }
            else if (curr->right != nullptr){
                curr = curr->right;
            }
            else{
                break;
            }
        }

        return root;
        
    }
};