class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        std::set<std::pair<int, int>> indices_with_zero;

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    indices_with_zero.insert({i, j});
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (indices_with_zero.contains({i, j})){
                    // Its zero so we need to replace column and row with zeros
                    int row = i;
                    int column = j;

                    for (int i = 0; i < matrix[0].size(); i++){
                        matrix[row][i] = 0;
                    }

                    for (int i = 0; i < matrix.size(); i++) {
                        matrix[i][column] = 0;
                    }

                }
            }
        }

    }
};
