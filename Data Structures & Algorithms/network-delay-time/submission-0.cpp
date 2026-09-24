/*
2026.09.23 bjak oa 第二題
只寫出了 dq + bfs，
沒寫出後半部分： min heap 維護
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n);
        // 先建鄰接表
        for (auto& time : times) {
            int u = time[0], v = time[1], t = time[2];
            g[u-1].push_back({v-1, t});
        }
        // 初始化 dist 陣列
        vector<int> dist(n, INT_MAX);
        // 起點初始化為 0
        dist[k-1] = 0;
        // 開始 dijkstra，裡面裝的是：{目前到 k 的最短路, k}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // pq 無 push_back，用 push or emplace, push({0, k-1}) or emplace(0, k-1)
        pq.push({0, k-1}); // {cost, node}
        // 當 pq 不為空
        while (!pq.empty()) {
            // C++ 不能直接彈出並取得，需分兩行寫
            // 新的到 cur 點的 cost c
            auto [c, cur] = pq.top(); // 這裡 auto 不能加 &，否則 pop 掉之後資訊就不見了
            pq.pop();
            // 若當前到此節點的路徑長比之前的還大，則直接跳過根本不需更新
            if (c > dist[cur]) continue;

            for (auto& [y, d] : g[cur]) {
                if (c + d < dist[y]) {
                    dist[y] = c + d;
                    pq.push({c + d, y});
                }
            }
        }
        // ------------------ 這裡就是唯一的差別 ------------------
        // 如果是 OA 題 Source -> Target：
        // return dist[target] if dist[target] != float('inf') else -1

        int mx = ranges::max(dist);
        return mx != INT_MAX ? mx : -1;
        
    }
};
