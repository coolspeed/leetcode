__author__ = 'coolspeed'

import bisect


class Solution:
    recursion_depth = 0

    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    def findMedianSortedArrays(self, nums1, nums2):
        print "recursion_depth =", self.recursion_depth
        print "nums1 =", str(nums1), "nums2 =", str(nums2)
        len1 = len(nums1)
        len2 = len(nums2)

        if len1 == 0:
            return self.median(nums2)

        if len2 == 0:
            return self.median(nums1)

        if len1 == len2 == 1:
            return 0.5 * (nums1[0] + nums2[0])

        if min(len1, len2) <= 2:
            if len1 > 2:
                nums1, nums2 = nums2, nums1

            for elem in nums1:
                bisect.insort_left(nums2, elem)

            return self.median(nums2)

        median1 = self.median(nums1)
        median2 = self.median(nums2)

        if median1 == median2:
            return median1

        if median1 > median2:
            nums1, nums2 = nums2, nums1
            print "nums1 =", str(nums1), "nums2 =", str(nums2)
            len1, len2 = len2, len1
            median1, median2 = median2, median1

        assert median1 < median2

        remove_len = self.removeLenOf2(nums1, nums2)
        print "remove_len =", remove_len

        # if remove_len <= 1 and min(len1, len2) <= 2:
        #     medians1 = self.getMedians(nums1)
        #     medians2 = self.getMedians(nums2)
        #     mediansSorted = sorted(medians1 + medians2)
        #     return self.median(mediansSorted)
        #
        # else:
        new_nums1 = nums1[remove_len : ]  # remove left part
        new_nums2 = nums2[ : len2 - remove_len]  # remove right part

        print
        print "----------------"

        self.recursion_depth += 1
        return self.findMedianSortedArrays(new_nums1, new_nums2)


    def median(self, a_list):
        list_len = len(a_list)
        assert list_len > 0
        if list_len % 2 == 0:
            ret = 0.5 * (a_list[list_len / 2 - 1] + a_list[list_len / 2])  # 4 -> 1, 2
        else:
            ret = a_list[list_len / 2]  # 3 -> 1

        return float(ret)

    def removeLenOf2(self, list_a, list_b):  # judge through the shorter list
        if len(list_a) >= len(list_b):
            list_a, list_b = list_b, list_a

        if len(list_a) % 2 == 0:
            return len(list_a) / 2 - 1

        else:
            return len(list_a) / 2

    def getMedians(self, aList):
        listLen = len(aList)
        if listLen % 2 == 0:
            return aList[listLen / 2 - 1 : listLen / 2 + 1]

        else:
            return aList[listLen / 2 - 1 : listLen / 2 + 2]


mysolution = Solution()

nums1 = [1, 4, 5]
nums2 = [2, 3, 6, 7, 8]

myresult = mysolution.findMedianSortedArrays(nums1, nums2)

print
print "===================================="
print myresult

