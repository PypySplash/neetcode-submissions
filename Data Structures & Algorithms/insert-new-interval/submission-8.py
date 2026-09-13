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
        n = len(intervals)
        ans = []
        inserted = False
        for i, (x, y) in enumerate(intervals):
            # left
            if y < newInterval[0]:
                ans.append([x, y])
            # overlap -> 改 newInterval
            elif x <= newInterval[1]:
                newInterval[0] = min(x, newInterval[0])
                newInterval[1] = max(y, newInterval[1])
            else:
                if not inserted:
                    ans.append(newInterval)
                    inserted = True
                ans.append(intervals[i])
        if not inserted:
            ans.append(newInterval)
        return ans