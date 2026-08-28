class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        std::sort(intervals.begin(), intervals.end());
        int end_date = INT_MIN;
        int num_to_remove = 0;
        for (const auto &interval : intervals) {
            if ( interval[0] < end_date ){
                num_to_remove ++;
                end_date = std::min(end_date, interval[1]);
               // std::cout << "[" << interval[0] << "," << interval[1] << "]";
            }
            else {
                end_date = interval[1];
            }
        }

        return num_to_remove;
    }
};
