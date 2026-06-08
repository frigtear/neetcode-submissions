class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> frequencies;

        for (int num : nums) {
            frequencies[num]++;
        }

        for (int i = 0; i + 1 < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (frequencies[nums[j]] > frequencies[nums[i]]) {
                    std::swap(nums[i], nums[j]);
                }
            }
        }

        std::vector<int> result;
        std::set<int> seen;

        for (int i = 0; i < nums.size() && result.size() < k; i++) {
            if (seen.find(nums[i]) == seen.end()) {
                result.push_back(nums[i]);
                seen.insert(nums[i]);
            }
        }

        return result;
    }
};