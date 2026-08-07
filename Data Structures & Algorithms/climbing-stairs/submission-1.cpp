class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1);
        auto dfs = [&] (auto& dfs, int i) -> int {
            if (i <= 1) {
                return 1;
            }
            int& res = memo[i]; // 注意这里是引用
            if (res) { // 之前计算过
                return res;
            }
            return res = dfs(dfs, i-1) + dfs(dfs, i-2); // 记忆化
        };
        return dfs(dfs, n);
    }
};
