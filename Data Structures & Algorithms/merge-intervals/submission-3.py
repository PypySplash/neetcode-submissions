class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x : (x[0], -x[1]))
        ans = []
        for i, (start, end) in enumerate(intervals):
            if i == 0:
                ans.append([start, end])
            if start == ans[-1][0]:
                continue
            if start <= ans[-1][1]:
                ans[-1][1] = max(ans[-1][1], end)
            else:
                ans.append([start, end])
        return ans