class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1000000000;
        int rate;
        int hours_needed;

        while (l <= r){
            std::cout << l << std::endl;
            std::cout << r << std::endl;
            rate = (l + r) / 2;

            // Eat the banannans
            hours_needed = 0;
            for (auto& pile : piles){
                hours_needed = hours_needed + (pile + rate - 1) / rate;
            }

            if (hours_needed > h){
                l = rate + 1;
            }
            else{
                r = rate - 1;
            }
        }

        return l;
    }
};
