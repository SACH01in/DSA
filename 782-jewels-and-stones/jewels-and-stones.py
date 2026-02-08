class Solution(object):
    def numJewelsInStones(self, jewels, stones):
        """
        :type jewels: str
        :type stones: str
        :rtype: int
        """
        new_jewels = 0

        for s in stones:
            if s in jewels:
                new_jewels += 1
        
        return new_jewels
        