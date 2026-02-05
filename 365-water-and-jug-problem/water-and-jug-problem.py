class Solution(object):

    def canMeasureWater(self, x, y, target):
        """
        :type x: int
        :type y: int
        :type target: int
        :rtype: bool
        """
        def GCD(a,b):
            while b>0:
                [a,b] = [b,a%b]
            return a

        if(target > x+y):
            return False
        elif (x == target or y == target or target == x+y):
            return True
        elif (target % GCD(x,y) == 0):
            return True

        return False
        