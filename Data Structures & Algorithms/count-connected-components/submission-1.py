class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        # first construct the adj list to access the neighbor info
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[x].append(y)
            g[y].append(x)

        # use dfs to mark the same cc
        ans = 0
        vis = [False] * n
        def dfs(i: int) -> None:
            vis[i] = True
            for x in g[i]:
                if not vis[x]:
                    dfs(x)
        
            
        for i in range(n):
            if not vis[i]:
                dfs(i)
                ans += 1
        return ans
