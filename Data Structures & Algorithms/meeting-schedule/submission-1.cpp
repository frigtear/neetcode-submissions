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
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const Interval &start, const Interval &end) {
            return start.start < end.start;
        });

        int end_date = 0;
        for (const auto &interval : intervals){
            if (interval.start >= end_date){
                end_date = interval.end;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
