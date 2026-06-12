class Solution {
public:
    int trap(vector<int>& height) {
        // water at one spot -> smaller of two pointers - height there
        // We know that the next wall we encounter will be equal height or more
        // So left pointer - height[current]
        int l = 0;
        int r = height.size() - 1;
        int rightMax = 0;
        int leftMax = 0;
        int water = 0;
        while (l < r){
            if (height[l] <= height[r]){

                if (height[l] < leftMax){
                    water += leftMax - height[l];
                }
                else {
                    leftMax = height[l];
                }

                l++;

            }
            else {
                if ((height[r]) < rightMax){
                    water += rightMax - height[r];
                }
                else {
                    rightMax = height[r];
                }
                r--;
            }
        }

        return water;

    }
};
