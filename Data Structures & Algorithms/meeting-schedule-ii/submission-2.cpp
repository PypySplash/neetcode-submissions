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

        // min_heap
        // 1. 按 start 時間排序
        ranges::sort(intervals, {}, [](auto& a) { return a.start; });
        // 2. Min-Heap 儲存各會議室的結束時間
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (const auto& interval : intervals) {
            // 如果最早結束的房間已經空出來了，釋放它
            if (!min_heap.empty() && interval.start >= min_heap.top()) {
                min_heap.pop();
            }
            // 佔用/開闢一間房間，記錄其 end 時間
            min_heap.push(interval.end);
        }
        return min_heap.size();

        
        // two pointers
        // vector<int> starts(n), ends(n);
        // for (int i = 0; i < n; i++) {
        //     starts[i] = intervals[i].start;
        //     ends[i] = intervals[i].end;
        // }
        // ranges::sort(starts);
        // ranges::sort(ends);

        // int s = 0, e = 0;
        // int cnt = 0, ans = 0;  // cnt 記錄當前佔用的房間數，ans 記錄歷史最大值

        // while (s < n) {
        //     // 新會議的開始時間，早於目前最早結束的會議時間
        //     // 意味著沒有房間能及時釋放，必須開新房間
        //     if (starts[s] < ends[e]) {
        //         cnt++;
        //         s++;  // 推進 start 指標，處理下一個會議
        //     }
        //     // 有會議已經結束（或剛好結束），釋放出一間房間
        //     else {
        //         cnt--;
        //         e++;
        //     }
        //     // 更新所需的最多會議室數量
        //     ans = max(ans, cnt);
        // }
        // return ans;
    }
};
