/*
要知道能不能達成條件，就要找出圖中是否有環 -> dfs 三色判環法
首先
1. 建立鄰接表
2. 創建 colors 數組，準備進行對著 colors 數組進行 dfs 三色判環
3. 遍歷 colors, if colors[i] = 0, 則調用 dfs(i)
4. 執行 dfs(x)
    a. 首先標記 color[x] = 1, 表示節點正在訪問中
    b. 接著遍歷 x 的鄰居 y, if colors[y] = 1, 則找到環, 返回 true, else if colors[y] = 0 (未訪問過) 且 dfs(y) 返回 true 那麼 dfs(x) 也返回 true.
    c. 若沒有找到環, 那麼先標記 colors[x] = 2, 表示 x 也已經完全訪問完畢，然後返回 false
5. if dfs(i) 返回 true 那麼找到了環，返回 false
6. 若遍歷所有節點都沒找到環，返回 false
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for (auto& pre : prerequisites) {
            g[pre[1]].push_back(pre[0]);
        }

        vector<int> colors(numCourses);
        // 返回 true 表示找到了环
        auto dfs = [&] (this auto&& dfs, int x) -> bool {
            colors[x] = 1; // x 正在访问中
            for (int y : g[x]) {
                // 情况一：colors[y] == 1，表示发生循环依赖，找到了环
                // 情况二：colors[y] == 0，没有访问过 y，继续递归 y 获取信息
                if (colors[y] == 1 || colors[y] == 0 && dfs(y)) {
                    return true;
                }
                // 情况三：colors[y] == 2，重复访问 y 只会重蹈覆辙，和之前一样无法找到环，跳过
            }
            colors[x] = 2;
            return false;
        };

        for (int i = 0; i < numCourses; i++) {
            if (colors[i] == 0 && dfs(i)) {
                return false; // 有环 -> 無法完成課程: false
            } 
        }
        return true; // 没有环 -> 可完成課程: true
    }
};
