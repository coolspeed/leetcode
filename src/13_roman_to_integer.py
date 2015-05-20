__author__ = 'coolspeed'

# 3999 / 3999 test cases passed.
# Status: Accepted
# Runtime: 168 ms


char_to_digit = {
    'I': 1,
    'V': 5,
    'X': 1,
    'L': 5,
    'C': 1,
    'D': 5,
    'M': 1
}

char_to_weight = {
    'I': 1,
    'V': 1,
    'X': 10,
    'L': 10,
    'C': 100,
    'D': 100,
    'M': 1000
}

dic = {
    1: ('I', 'V'),
    10: ('X', 'L'),
    100: ('C', 'D'),
    1000: ('M', '_'),
    10000: ('_', '_')
}


class Solution:
    # @param {string} s
    # @return {integer}
    def romanToInt(self, s):
        ret = 0

        for i in xrange(len(s)):
            curr_char = s[i]
            curr_digit = char_to_digit[curr_char]
            curr_weight = char_to_weight[curr_char]

            if curr_digit == 1:
                curr_five = dic[curr_weight][1]
                curr_ten = dic[curr_weight * 10][0]
                if i < len(s) - 1 and s[i + 1] in [curr_five, curr_ten]:
                    ret -= curr_digit * curr_weight
                else:
                    ret += curr_digit * curr_weight
            else:  # 5
                ret += curr_digit * curr_weight

        return ret


mysolution = Solution()
input_str = "XL"
ret = mysolution.romanToInt(input_str)
print "ret =", ret

