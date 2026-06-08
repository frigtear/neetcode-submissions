class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> seen;

        for (auto& num : nums){
            if ( seen.contains( num ) ){
                return true;
            }
            else {
                seen.insert(num);
            }
        }
        return false;
    }
};