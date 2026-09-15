class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        # 遍歷整個網狀圖，經過時標記走過，遇到 1 時 dfs，先標記走過，接著將上下左右四個方向的方向都檢查，若有相鄰島嶼，繼續 dfs （記得檢查邊界！， dfs 結束時，島嶼數量 +1，接著繼續遍歷網格圖
        directions = {(0, 1), (0, -1), (1, 0), (-1, 0)}
        def dfs(i: int, j: int) -> None:
            if i < 0 or i >= m or j < 0 or j >= n or vis[i][j]:
                return
            if grid[i][j] == "0":
                vis[i][j] = True
                return
            vis[i][j] = True
            for dx, dy in directions:
                dfs(i + dx, j + dy)
            

        vis = [[False] * n for _ in range(m)]
        ans = 0
        for i, x in enumerate(grid):
            for j, y in enumerate(x):
                if y == "0":
                    vis[i][j] = True
                # 若為 1 且還沒拜訪過，dfs
                elif y == "1" and not vis[i][j] :
                    dfs(i, j)
                    ans += 1
        return ans
        