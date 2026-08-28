/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::vector<int> start;
        std::vector<int> end;

        for (const auto &interval : intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        std::sort(start.begin(), start.end());
        std::sort(end.begin(), end.end());

        int s = 0;
        int e = 0;
        int count = 0;
        int result = 0;

        while (s < intervals.size() && e < intervals.size()){
            if (start[s] < end[e]){
                count ++;
                s++;
            }
            else {
                e++;
                count --;
            }
            result = std::max(result, count);
        }
        return result;

    }
};
