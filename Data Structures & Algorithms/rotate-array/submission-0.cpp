class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        vector<int> copy = nums;
        int shifted_index;
        for (int i = 0; i < nums.size(); i++){
            shifted_index = (i + k) % nums.size();
            nums[shifted_index] = copy[i];
        }
        
    }
};