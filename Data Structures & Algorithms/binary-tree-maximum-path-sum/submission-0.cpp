class Solution {
private:
    // 1. This class variable tracks the maximum sum across ALL recursive calls
    int largestSumSeen; 

    int helper(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftMaxPath = helper(node->left);
        int rightMaxPath = helper(node->right);

        leftMaxPath = std::max(leftMaxPath, 0);
        rightMaxPath = std::max(rightMaxPath, 0);

        int currentPathSum = node->val + leftMaxPath + rightMaxPath;

        largestSumSeen = std::max(largestSumSeen, currentPathSum);

        return node->val + std::max(leftMaxPath, rightMaxPath);
    }

public:
    int maxPathSum(TreeNode* root) {
        largestSumSeen = INT_MIN; 
        
        helper(root); 
        
        return largestSumSeen; 
    }
};