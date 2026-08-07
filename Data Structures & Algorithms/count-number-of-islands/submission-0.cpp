/*
這題就是遍歷一遍 grid，遇到 1 時， dfs 她 adjacent 的 grid 看有無連接在一起，到過的 grid[i][j] 可以直接把它改成 0 ，這樣才不會無限地歸
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;

        auto dfs = [&] (auto& dfs, int i, int j) -> void {
            // 若超出邊界，或遇到水，返回
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
                return;
            }
            grid[i][j] = '0';
            dfs(dfs, i + 1, j);
            dfs(dfs, i - 1, j);
            dfs(dfs, i, j - 1);
            dfs(dfs, i, j + 1);
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(dfs, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
