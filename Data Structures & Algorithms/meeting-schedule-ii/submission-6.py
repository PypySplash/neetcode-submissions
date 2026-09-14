"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""
import heapq
class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        # 使用最小堆來維護最小的結束時間
        # 照起始時間排序
        intervals.sort(key=lambda x : x.start)
        min_heap = []
        for interval in intervals:
            if min_heap and interval.start >= min_heap[0]:
                heapq.heappop(min_heap)
            heapq.heappush(min_heap, interval.end)
        return len(min_heap)



        # # 直接把 start, end 分別做排序，不需維護原本 start 和 end 的配對關係（小不直覺
        # start = [interval.start for interval in intervals]
        # end = [interval.end for interval in intervals]
        # start.sort()
        # end.sort()
        # ans = cnt = s = e = 0
        # while s < len(intervals):
        #     if start[s] < end[e]:
        #         cnt += 1
        #         s += 1
        #     else:
        #         cnt -= 1
        #         e += 1
        #     ans = max(ans, cnt)
        # return ans