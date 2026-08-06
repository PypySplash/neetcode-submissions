class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // O(n)
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();

        // 1. 完全在 newInterval 左側（不重疊）
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i++]);
        }

        // 2. 有重疊，持續擴展 newInterval 的邊界
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // 3. 完全在 newInterval 右側（不重疊）
        while (i < n) {
            ans.push_back(intervals[i++]);
        }
        return ans;
        
        // O(n log n)
        // intervals.push_back(newInterval);
        // ranges::sort(intervals, {}, [](auto& a) { return a[0]; });
        // // Merge Interval
        // vector<vector<int>> ans;
        // for (auto& interval : intervals) {
        //     // 若 ans 不為空且 ans 中最後面的區間的 end >= 當前 intervals start
        //     if (!ans.empty() && ans.back()[1] >= interval[0]) {
        //         ans.back()[1] = max(ans.back()[1], interval[1]);
        //     }
        //     // else 就直接加入當前區間
        //     else {
        //         ans.push_back(interval);
        //     }
        // }
        // return ans;
    }
};
