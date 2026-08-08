/*
我的思路：
有點像島嶼數量，
我先創建一個長為 n 的數組，初始化為 0，對這個數組進行 dfs，找到聯通在一起的島嶼，數量 +1 ，並且把遍歷過的數字記為 1 ，使得之後不會重複遍歷

*/

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(n);
        auto dfs = [&] (this auto&& dfs, int x) -> void {
            vis[x] = 1;
            for (int y : g[x]) {
                if (vis[y] == 0) {
                    dfs(y);
                }
            }
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};
