class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Input: nums1 = [10,20,20,40,0,0], m = 4, nums2 = [1,2], n = 2

        // Output: [1,2,10,20,20,40]

        // 1, 2, 20, 20, 40, 10, 20


        // [10,20,20,40,1,2]
        // [1,20,20,40,10,2]
        // [1,10,20,20,40,2]
        //               
        //


        int p1 = m - 1;
        int p2 = n - 1;
        int curr = nums1.size() - 1;

        while (curr > -1){
            
            if (p1 < 0 || (p1 >= 0 && p2 >= 0 && nums2[p2] >= nums1[p1])) {
                nums1[curr] = nums2[p2];
                p2 --;
            }
            else if (p2 < 0 || p1 >= 0 && nums1[p1] > nums2[p2]){
                nums1[curr] = nums1[p1];
                p1 --;
            }
            
            curr -= 1;

        }


    }

};