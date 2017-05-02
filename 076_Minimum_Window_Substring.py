'''
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
'''


class Solution(object):
    def minWindow(self, s, t):
        if t == '': return ''
        t_map = {}
        for c in t:
            if c in t_map: t_map[c] += 1
            else: t_map[c] = 1
        s_map = {c:0 for c in t_map}
        i = z = 0
        ls, lt = len(s), len(t)
        while i < ls:
            c = s[i]
            if c in s_map:
                s_map[c] = 1
                z += 1
                break
            i += 1
        j = i + 1
        while j < ls and z < lt:
            c = s[j]
            if c in s_map:
                s_map[c] += 1
                if s_map[c] <= t_map[c]: z += 1
            j += 1
        if z < lt: return ''
        min_length = j
        mi, mj = i, j
        while True:
            if min_length > j - i:
                min_length = j - i
                mi, mj = i, j
            c = s[i]
            s_map[c] -= 1
            if s_map[c] < t_map[c]: z -= 1
            while i < ls - 1:
                i += 1
                c = s[i]
                if c in s_map:
                    if s_map[c] <= t_map[c]: break
                    else: s_map[c] -= 1
            if i == ls: break
            while j < ls and z < lt:
                c = s[j]
                if c in s_map:
                    s_map[c] += 1
                    if s_map[c] <= t_map[c]: z += 1
                j += 1
            if z < lt: break
        return s[mi:mj]

if __name__ == '__main__':
    print Solution().minWindow('', 'A')


