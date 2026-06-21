class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int curr = 0;
        for (auto& num : nums){
           // std::cout << num << " " << curr << std::endl;
            curr = std::max(curr, 0);
            curr += num;
            max_sum = std::max(max_sum, curr);
        }

        return max_sum;
    }
};
