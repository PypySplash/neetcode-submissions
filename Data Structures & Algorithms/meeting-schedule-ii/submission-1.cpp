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
        int n = intervals.size(); 
        if (n == 0) return 0;
        
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }
        ranges::sort(starts);
        ranges::sort(ends);

        int s = 0, e = 0;
        int cnt = 0, ans = 0;  // cnt 記錄當前佔用的房間數，ans 記錄歷史最大值

        while (s < n) {
            // 新會議的開始時間，早於目前最早結束的會議時間
            // 意味著沒有房間能及時釋放，必須開新房間
            if (starts[s] < ends[e]) {
                cnt++;
                s++;  // 推進 start 指標，處理下一個會議
            }
            // 有會議已經結束（或剛好結束），釋放出一間房間
            else {
                cnt--;
                e++;
            }
            // 更新所需的最多會議室數量
            ans = max(ans, cnt);
        }
        return ans;
    }
};
