__author__ = 'coolspeed'

# 3999 / 3999 test cases passed.
# Status: Accepted
# Runtime: 108 ms


class Solution:
    # @param {integer} num
    # @return {string}
    def intToRoman(self, num):
        ret = ""
        dic = {
            1: ('I', 'V'),
            10: ('X', 'L'),
            100: ('C', 'D'),
            1000: ('M', '_')
        }

        for weight in [1000, 100, 10, 1]:
            curr_digit = (num / weight) % 10
            # print "weight =", weight
            # print "curr_digit =", curr_digit
            curr_tuple = dic[weight]
            one, five = curr_tuple

            if curr_digit < 4:
                ret += curr_digit * one
            elif curr_digit == 4:
                ret += one + five
            elif 5 <= curr_digit <= 8:
                ret += five
                for i in xrange(curr_digit - 5):
                    ret += one
            elif curr_digit == 9:
                ten = dic[weight * 10][0]
                ret += one + ten

        return ret


mysolution = Solution()
input_num = 3333
ret = mysolution.intToRoman(input_num)
print "ret =", ret

