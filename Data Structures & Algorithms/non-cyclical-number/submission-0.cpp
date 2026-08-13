class Solution {

private:
    int getNextNumber(int n){
        int copy = n;
        int result = 0;
        while (copy > 0){
            result += (copy % 10) * (copy % 10);
            copy /= 10;
        }
        //std::cout << result << std::endl;
        return result;

    }

public:
    bool isHappy(int n) {
        
        std::set<int> seen;
        
        while (n != 1){
            n = getNextNumber(n);
            if (seen.contains(n)){
                return false;
            }
            seen.insert(n);
            
        }
        //std::cout << getNextNumber(n);

        
        return true;

    }
};
