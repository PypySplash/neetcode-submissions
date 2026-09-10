class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); // m * n
        vector<vector<int>> ans(n, vector<int>(m)); // n * m
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) ans[i][j] = matrix[i][j];
                else ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};