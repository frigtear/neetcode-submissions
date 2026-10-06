class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        vector<int> copy = nums;
        int shifted_index;
        int num_size = nums.size();
        for (int i = 0; i < nums.size(); i++){
            shifted_index = (i + k) % num_size;
            nums[shifted_index] = copy[i];
        }
        
    }
};