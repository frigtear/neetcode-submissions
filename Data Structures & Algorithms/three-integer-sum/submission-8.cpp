class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            size_t l = i + 1;
            size_t r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});

                    ++l;
                    --r;

                    while (l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }

                    while (l < r && nums[r] == nums[r + 1]) {
                        --r;
                    }
                }
                else if (sum < 0) {
                    ++l;
                }
                else {
                    --r;
                }
            }
        }

        return result;
    }
};