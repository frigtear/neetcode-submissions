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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if (root1 == nullptr && root2 == nullptr){
            return nullptr;
        }

        bool twoExists = false;
        bool oneExists = false;
        int r1val = 0;
        int r2val = 0;
        if (root1 != nullptr){
            r1val = root1->val;
            oneExists = true;
        }
        if (root2 != nullptr){
            r2val = root2->val;
            twoExists = true;
        }

        TreeNode* node = new TreeNode(r1val + r2val);

        // ok now recursively deal with the children
        node->left = mergeTrees(oneExists ? root1->left : nullptr, twoExists ? root2->left : nullptr);
        node->right = mergeTrees(oneExists ? root1->right : nullptr, twoExists ? root2->right : nullptr);
        return node;

        
    }
};