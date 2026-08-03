class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Input: triplets = [[1,2,3],[7,1,1]], target = [7,2,3]

        // Input: triplets = [[2,5,6],[1,4,4],[5,7,5]], target = [5,4,6]
        //      // if you need a largest from 2 different triplets 
        //         then you should return false
        //          target = [5, 4, 6] is false because we need 5 from 5, 7, 5 and 4 from 1, 4, 4 but 7 > 4
        //          

        // If target[i] == triplet[i] then we pick this. 

        std::set<int> seen[3];

        for (const auto& triplet : triplets) {
            bool isInvalid = false;
            for (int i = 0; i < 3; i++){
              //  std::cout << "TRIPLET: TARGET " << triplet[i] << " " << target[i] << std::endl;
                if (triplet[i] > target[i]){
                    isInvalid = true; // ignore this triplet
                   // std::cout << "CONTINUING";
                }
            }

            if (isInvalid) {
                continue;
            }


         //   std::cout << "TRIPLET: " << std::endl;
            for (int i = 0; i < 3; i++) {
             //   std::cout << triplet[i] << " " << std::endl;
                seen[i].insert(triplet[i]);
            }
        } 

        for (int i = 0; i < 3; i++){
          //  std::cout << "TARGET " << i << " " << target[i];
            if (!seen[i].contains(target[i])){
                return false;
            }
        }

        return true;


    }
};
