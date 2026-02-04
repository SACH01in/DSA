class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        counter_s = Counter(s);
        counter_t = Counter(t);

        return counter_s == counter_t
        