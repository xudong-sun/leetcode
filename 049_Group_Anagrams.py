'''
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
'''


class Solution(object):
    def groupAnagrams(self, strs):
        map_index = {}
        result = []
        for s in strs:
            t = ''.join(sorted(s))
            if t in map_index: result[map_index[t]].append(s)
            else:
                map_index[t] = len(result)
                result.append([s])
        return result

if __name__ == '__main__':
    print(Solution().groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))

