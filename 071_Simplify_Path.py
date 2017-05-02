'''
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
'''


class Solution(object):
    def simplifyPath(self, path):
        dd = path.strip('/').split('/')
        r = [''] * len(dd)
        i = 0
        for d in dd:
            if d == '..': i = max(i-1, 0)
            elif d == '.' or d == '': continue
            else:
                r[i] = d
                i += 1
        return '/' + '/'.join(r[:i])

if __name__ == '__main__':
    print(Solution().simplifyPath('/home/../../..'))

