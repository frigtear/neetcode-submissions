class Solution {
private:
// x=2.00000
// n=5

// helper(3) * helper(3)
// helper(1) * helper(1) * helper(1) * helper(1)
// 

    double helper(double num, long long n){
        if (n == 0){
            return 1;
        }
      
        double power = helper(num, n / 2);
        double result = power * power;
        if (n % 2 == 1){
            result *= num; 
        }

        return result;
    }

public:
    double myPow(double x, int n) {
        
        long long num = n;

        double result;
        result = helper(x, std::abs(num));
        
        std::cout << result << std::endl;

        if (num < 0){
            return 1.0 / result;
        }
        return result;
    }
};
