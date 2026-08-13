class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // Old index has i, j
        // Do math to find the rotated i and j
        //
        // basically to reflect it around the middle the new index is 
        // n-i
        // n-j

/*
        Input: matrix = [
            [1,2],
            [3,4]
        ]
*/

        // n-1  = 1
        // i, j = 0
        // 2
        // When column equals 

        int l = 0;
        int r = matrix.size() - 1;

        while (l < r) {
            int top = l;
            int bottom = r;

            for (int i = 0; i < r - l; i++) {
                
                 //save the topleft
                int topLeft = matrix[top][l + i];

                //move bottom left into top left
                matrix[top][l + i] = matrix[bottom - i][l];

                // move bottom right into bottom left
                matrix[bottom - i][l] = matrix[bottom][r - i];

                // move top right into bottom right
                matrix[bottom][r - i] = matrix[top + i][r];

                // move top left into top right
                matrix[top + i][r] = topLeft;

            }

            l ++;
            r --;

        }

    }
};
