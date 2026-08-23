class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++) {

            uint32_t sample = ( n & (1u << i) );
            int amountToMove = (31 - i) - i;
            if (amountToMove < 0){
                result |= sample >> std::abs(amountToMove);
            }
            else {
                result |= sample << std::abs(amountToMove);
            }

        }

        return result;


        // 1 0 1 0 1 0
        // 5   3 2 

    }
};
