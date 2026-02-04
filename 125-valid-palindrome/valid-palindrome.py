class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        alphabets = "abcdefghijklmnopqrstuvwxyz0123456789"
        start = 0
        end = len(s) - 1
        result = True

        while start < end:
            if s[start].lower() not in alphabets:
                start += 1
            elif s[end].lower() not in alphabets:
                end -= 1
            elif s[start].lower() != s[end].lower():
                result = False
                break
            else:
                start += 1
                end -= 1

        return result       