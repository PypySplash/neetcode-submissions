"""
分成 3 種情況：
1. left to newIntervals 
2. overlap:
cur_end >= new_start
cur_start <= new_end
3. right to newIntervals
"""

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # while 迴圈版本
        n = len(intervals)
        ans = []
        i = 0
        while i < n and intervals[i][1] < newInterval[0]:
            ans.append(intervals[i])
            i += 1
        # print(f"i: {i}")
        while i < n and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(intervals[i][0], newInterval[0])
            newInterval[1] = max(intervals[i][1], newInterval[1])
            i += 1
        ans.append(newInterval)
        while i < n and intervals[i][0] > newInterval[1]:
            ans.append(intervals[i])
            i += 1
        print(f"i: {i}")
        return ans




        # # for 迴圈版本: 需額外維護一個 inserted 變數來判斷持續更新的 overlap newInterval 有無被插入 -> while 回圈版更加簡潔
        # n = len(intervals)
        # ans = []
        # inserted = False
        # for i, (x, y) in enumerate(intervals):
        #     # left
        #     if y < newInterval[0]:
        #         ans.append([x, y])
        #     # overlap -> 改 newInterval
        #     elif x <= newInterval[1]:
        #         newInterval[0] = min(x, newInterval[0])
        #         newInterval[1] = max(y, newInterval[1])
        #     else:
        #         if not inserted:
        #             ans.append(newInterval)
        #             inserted = True
        #         ans.append(intervals[i])
        # if not inserted:
        #     ans.append(newInterval)
        # return ans
