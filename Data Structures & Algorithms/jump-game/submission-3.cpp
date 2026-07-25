class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int farthestJump = 0;
        for (int i = 0; i < nums.size(); i++){
            if ( farthestJump >= i ){
                farthestJump = std::max(farthestJump, i + nums[i]);
            }
            else {
                return false;
            }
        }
        return true;
        
    }
};
