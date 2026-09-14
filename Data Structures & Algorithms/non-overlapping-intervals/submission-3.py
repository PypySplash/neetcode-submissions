class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # 核心邏輯：儘早把位置空出來: 按結束時間排序
        intervals.sort(key=lambda x : x[1])
        ans = 0
        prev_end = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] < prev_end:
                ans += 1
            else:
                prev_end = intervals[i][1]
        return ans

        # # 按開始時間排序，結束時間正序
        # intervals.sort(key=lambda x : (x[0], x[1]))
        # ans = 0
        # prev_end = intervals[0][1]
        # for i in range(1, len(intervals)):
        #     if intervals[i][0] < prev_end:
        #         ans += 1
        #         # 這邊需貪婪地移除結束時間較晚的
        #         prev_end = min(prev_end, intervals[i][1])
        #     else:
        #         prev_end = intervals[i][1]
        # return ans
        
