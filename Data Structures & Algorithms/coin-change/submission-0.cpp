/*
思路是：
完全背包
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 選 or 不選
        int n = coins.size();
        vector memo(n, vector<int>(amount + 1, -1)); // -1 表示没有计算过

        auto dfs = [&] (this auto&& dfs, int i, int c) -> int {
            if (i < 0) {
                return c == 0 ? 0 : INT_MAX / 2;
            }
            if (memo[i][c] != -1) { // 之前计算过
                return memo[i][c];
            }
            // 若當前零錢金額 > 剩餘金額
            if (coins[i] > c) { // 只能不選
                return memo[i][c] = dfs(i - 1, c);
            }
            // 不選 or 選 (扣掉當前硬幣金額, 選擇的硬幣數量 + 1)
            return memo[i][c] = min(dfs(i-1, c), dfs(i, c - coins[i]) + 1);
        };
        int ans = dfs(n-1, amount);
        return ans < INT_MAX / 2 ? ans : -1;
    }
};
