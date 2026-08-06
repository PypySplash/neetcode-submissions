class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 按結束時間排序
        ranges::sort(intervals, {}, [](auto& a) { return a[1];});
        int ans = 0, prev_end = intervals[0][1];  // 先加入 intervals 的第一個區間
        // 從第二個區間開始
        for (int i = 1; i < intervals.size(); i++) {
            // 沒有重疊，更新邊界
            if (intervals[i][0] >= prev_end) {
                prev_end = intervals[i][1];
            } else {
                ans++;
            }
        }
        return ans;
    }
};
