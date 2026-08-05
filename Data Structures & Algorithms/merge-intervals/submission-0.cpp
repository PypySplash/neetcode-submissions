class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals, {}, [](auto& a) { return a[0]; });
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
