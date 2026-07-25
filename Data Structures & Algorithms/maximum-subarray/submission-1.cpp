class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = nums[0];
        int curr = 0;
        for (int num : nums){
            curr += num;
            largestSum = std::max(curr, largestSum);
            curr = std::max(curr,0);
        }
        return largestSum;
    }
};
