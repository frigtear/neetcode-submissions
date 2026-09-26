class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        std::stack<std::pair<int, int>> temps;
        std::vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++){
            if (temps.empty() || temps.top().first >= temperatures[i]){
                temps.push({temperatures[i], i}); // will always be decreasing
            } 
            else {
                // whoops its increasing now. this means we must start pop
                while (!temps.empty() && temps.top().first < temperatures[i]){
                    result[temps.top().second] = (i - temps.top().second);
                    temps.pop();
                }
                temps.push({temperatures[i], i});
            }
        } 

        return result;

    }
};
