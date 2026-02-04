class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if(x < 0) or (x % 10 == 0 and x != 0):
            return False;
        
        original = x;
        reversed = 0;

        while (x > 0):
            reversed = (reversed *10) + (x % 10);
            x = x // 10;

        return original == reversed;

        return false
        