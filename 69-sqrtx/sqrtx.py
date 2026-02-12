class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 1 :
            return 1
        i = 1
        while True:
            if(x < i*i):
                return i-1
            i += 1
        