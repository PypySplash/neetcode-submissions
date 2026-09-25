/*
dfs(i, j) 表示從 grid[0][0] ~ grid[m-1][n-1] 的方法數
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) f[i][0] = 1;
        for (int j = 0; j < n; j++) f[0][j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] = f[i][j-1] + f[i-1][j];
            }
        }
        return f[m-1][n-1];
    }
};
