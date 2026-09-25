class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // nums = [6,1,2,3,4,5], target = 1
        //   

        int l = 0;
        int r = nums.size() - 1;
        while (l <= r){

            int last = nums[r];
            int first = nums[l];
            
            if (last == target){
                return r;
            }
            if (first == target){
                return l;
            }

            int c = (l + r) / 2;

            if (nums[c] == target){
                return c;
            }

            if (nums[c] < last){

                if ((target > nums[c] && target < last)){
                    l = c + 1;
                }
                else {
                    r = c - 1;
                }

            }
            else{
                if ((target < nums[c] && target > first)){
                    r = c - 1;
                }
                else {
                    l = c + 1;
                }
            }

        }

        return -1;

    }
};
