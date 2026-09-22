class Codec {
private:

    void helper(TreeNode* node, string &result){
        if (node){
            result += to_string(node->val);
            result += ",";
            helper(node->left, result);
            helper(node->right, result);
        }
        else{
            result += "/,";   // fixed
        }
    }

    TreeNode* helper2(const string& preorder, size_t& index) {
        if (index >= preorder.size()) {
            return nullptr;
        }

        size_t end = preorder.find(',', index);

        string token = preorder.substr(index, end - index);

        index = end + 1;

        if (token == "/") {
            return nullptr;
        }

        int value = stoi(token);

        TreeNode* node = new TreeNode(value);

        node->left = helper2(preorder, index);
        node->right = helper2(preorder, index);

        return node;
    }

public:

    string serialize(TreeNode* root) {
        string result;
        helper(root, result);
        return result;
    }

    TreeNode* deserialize(string data) {
        size_t index = 0;   
        return helper2(data, index);
    }
};