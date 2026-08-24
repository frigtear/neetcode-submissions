class Solution {
public:
    int getSum(int a, int b) {
       // uint32_t abits = static_cast<uint32_t>(a);
        //uint32_t bbits = static_cast<uint32_t>(b);
        // We will be doing long addition in binary :)
        uint32_t result = 0;
        bool carry = 0;
        for (int i = 0; i < 32; i++) {
            bool bita = 1 & ( a >> i );
            bool bitb = 1 & ( b >> i );
            bool sum = bita ^ bitb ^ carry;
            carry = (bita & bitb) | (bita & carry) | (bitb & carry);
            result |= (sum << i);

        }

        return result;

    }
};
