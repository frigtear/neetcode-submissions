class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        bool carry = true;
        int i = digits.size() - 1;
        while (i >= 0 && carry == true ){
            if (digits[i] == 9){
                digits[i] = 0;
            }
            else {
                digits[i] ++;
                carry = false;
            }
            i--;
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
