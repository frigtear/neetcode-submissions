class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size(), 1);
        std::vector<int> postfix(nums.size(), 1);
        std::vector<int> result;
        int product = 1;

        for ( int i = 0; i<nums.size(); i++) {
            product *= nums[i];
            prefix[i] = product;
        }

        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--){
            product *= nums[i];
            postfix[i] = product;
        }
     
        for (int i = 0; i < nums.size(); i++){
            int sum = 1;
            if (i > 0){
                sum *= prefix[i - 1];
            }
            if (i < nums.size() - 1){
                sum *= postfix[i + 1];
            }
            result.push_back(sum);
        }

/*
        for (int num : prefix){
            std::cout << num << " ";
        }
        for (int num : postfix){
            std::cout << num << " ";
        }
*/
        return result;

    }
};
