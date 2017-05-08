class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e
    def __str__(self):
        return '[' + str(self.start) + ', ' + str(self.end) + ']'

def generate_intervals(intervals):
    '''generate a list of intervals
    intervals: a list of [s, e]
    return: a list of Interval
    '''
    res = []
    for interval in intervals:
        res.append(Interval(interval[0], interval[1]))
    return res

