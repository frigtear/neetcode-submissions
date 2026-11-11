class Solution {
public:
    int trap(vector<int>& height) {
        size_t l = 0;
        size_t r = height.size() - 1;

        int lmax = INT_MIN;
        int rmax = INT_MIN;

        int rain_water = 0;
        while (l < r){

            lmax = std::max(height[l], lmax);
            rmax = std::max(height[r], rmax);

            while (l < r && lmax <= rmax){
                l++;
                lmax = std::max(height[l], lmax);
                rain_water += lmax - height[l];
            }

            while (l < r && rmax < lmax){
                r--;
                rmax = std::max(height[r], rmax);
                rain_water += rmax - height[r];
            }
        }

        return rain_water;


    }
};