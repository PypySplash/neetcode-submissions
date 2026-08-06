class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        ranges::sort(intervals, {}, [](auto& a) { return a[0]; });
        // Merge Interval
        vector<vector<int>> ans;
        for (auto& interval : intervals) {
            // 若 ans 不為空且 ans 中最後面的區間的 end >= 當前 intervals start
            if (!ans.empty() && ans.back()[1] >= interval[0]) {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
            // else 就直接加入當前區間
            else {
                ans.push_back(interval);
            }
        }
        return ans;
    }
};
