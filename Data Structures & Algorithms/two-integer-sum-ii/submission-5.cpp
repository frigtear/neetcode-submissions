class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> result;
        while ( l < r ) {
            int sum = numbers[l] + numbers[r];
            //std::cout << l << " " << r << std::endl;
            //std::cout << sum << " " << target << std::endl;
            if (sum == target){
                result = {l+1, r+1};
                return result;
            }
            else if ( sum < target ){
                l ++;
            }
            else{
                -- r;
            }
        } 

        return result;

    }
};
