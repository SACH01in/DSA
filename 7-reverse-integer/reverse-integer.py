class Solution:
    def reverse(self, x: int) -> int:
        absolute = lambda x: -x if x < 0 else x
        result = 0
        temp_arr = []
        temp_val = absolute(x)

        while temp_val != 0:
            temp_arr.append(temp_val % 10)
            temp_val = temp_val // 10

        for indx, n in enumerate(temp_arr):
            result += n * (10 ** (len(temp_arr) - indx - 1))

        if x < 0:
            result = -result

        if result < -2**31 or result > 2**31 - 1:
            result = 0

        return result;