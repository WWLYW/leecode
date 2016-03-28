"""
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

Subscribe to see which companies asked this question
"""

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        if len(s) == 0 or len(wordDict) == 0:
            return False

        findwordList = [0]
        for i in xrange(1, len(s) + 1):
            for j in xrange(len(findwordList) - 1, -1, -1):
                substr = s[findwordList[j]:i]
                if substr in wordDict:
                    findwordList.append(i)
                    break
        return findwordList[-1] == len(s) 

a = Solution()
s = "leetcode"
wordDict = ['l', 'le', 'lee', 'tcode']
print a.wordBreak(s, wordDict)
