class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> result;
        for (const auto &interval : intervals){
           
            if (!result.empty() && interval[0] <= result.back()[1] ){
                auto last = result.back();
                result.pop_back();
                result.push_back({last[0], std::max(interval[1], last[1])});
            }
            else{
                result.push_back(interval);
            }
        }
        
        return result;
    }
};
