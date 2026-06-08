class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> values;

        for (int i = 0; i < nums.size(); i++){
            if (!values.contains(nums[i])){
                values[target - nums[i]] = i;
            }
            else {
                return std::vector<int> { values[nums[i]], i };
            }
        }
    }
};
