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
        // 兩種寫法
        // ranges::sort(intervals, {}, [](auto& a) { return a.start; });
        ranges::sort(intervals, [](auto& a, auto& b) {
            return a.start < b.start;
        });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i-1].end > intervals[i].start) {
                return false;
            }
        }
        return true;
    }
};
