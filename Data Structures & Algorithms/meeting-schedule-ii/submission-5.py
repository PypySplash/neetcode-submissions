"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        # 直接把 start, end 分別做排序，不需維護原本 start 和 end 的配對關係（小不直覺
        start = [interval.start for interval in intervals]
        end = [interval.end for interval in intervals]
        start.sort()
        end.sort()

        ans = cnt = s = e = 0
        while s < len(intervals):
            if start[s] < end[e]:
                cnt += 1
                s += 1
            else:
                cnt -= 1
                e += 1
            ans = max(ans, cnt)
        return ans