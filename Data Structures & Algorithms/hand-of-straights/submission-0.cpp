class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        // Sort the numbers 
        // Make a frequency dict
        // 
        // If needed groups 
        std::map<int, int> freqMap;

        for (const int card : hand){
            freqMap[card]++;
        }    

        while (!freqMap.empty()) {
            // Get the lowest key with freq > 0
            int card = freqMap.begin()->first;
            std::cout << "GROUP IS " << card << std::endl;
            for (int i = 1; i <= groupSize; i++){
                std::cout << card << " " << std::endl;
                if (freqMap.contains(card)){
                    freqMap[card] --;
                    if (freqMap[card] <= 0) {
                        freqMap.erase(card);
                    }
                    card ++;
                  
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};
