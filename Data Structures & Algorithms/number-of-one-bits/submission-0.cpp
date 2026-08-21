class Solution {
public:
    int hammingWeight(uint32_t n) {
        int numBitsSet = 0;
        while (n > 0) {
            if ((n & 1) == 1){
                numBitsSet ++;
            }
            n = n >> 1;

        }
        return numBitsSet;
    }
};
