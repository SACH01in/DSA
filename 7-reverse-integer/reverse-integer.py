class Solution:
    def reverse(self, x: int) -> int:
        absolute = lambda x: -x if x < 0 else x
        temp_val = absolute(x)
        reverse_x = 0

        while temp_val != 0:
            reverse_x = reverse_x *10 + (temp_val % 10)
            temp_val = temp_val // 10

        if x < 0:
            reverse_x = -reverse_x

        if reverse_x < -2**31 or reverse_x > 2**31 - 1:
            reverse_x = 0

        return reverse_x;