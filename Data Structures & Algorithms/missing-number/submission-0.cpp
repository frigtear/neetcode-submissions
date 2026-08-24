class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int xorNums = 0;
        for (int num : nums){
            xorNums ^= num;
        }

        int xorRange = 0;

        for (int i = 0; i <= nums.size(); i++) {
            xorRange ^= i;
        }

        return xorNums ^ xorRange;
    }
};
