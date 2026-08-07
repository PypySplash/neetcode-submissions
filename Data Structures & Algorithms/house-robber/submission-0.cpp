class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        // dfs(i) 表示从 nums[0] 到 nums[i] 最多能偷多少
        auto dfs = [&] (auto& dfs, int i) -> int {
            if (i < 0) {
                return 0;
            }
            if (memo[i] != -1) { // 之前计算过
                return memo[i];
            }
            // 選 or 不選
            return memo[i] = max(dfs(dfs, i-1), dfs(dfs, i-2) + nums[i]);
        };
        return dfs(dfs, n-1);
    }
};
